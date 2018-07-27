#include <RcppArmadillo.h>
#include <random>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp; 

// For PRN generation
class Random {
	protected:
		static std::mt19937_64 engine;
	public:
		static void seed() {
			engine.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		};
		static void seed( unsigned seed ) {
			engine.seed(seed);
		};
};

// [[Rcpp::export]]
void randomseed() { Random::seed(); }
// [[Rcpp::export]]
void setseed( unsigned seed ) { Random::seed(seed); }

// Static member definition
// std::random_device Random::rd;
std::mt19937_64 Random::engine;

// Gaussian distribution class
class Gaussian: public Random {
	private:
		std::normal_distribution<double> dist;
		double mean;
		double stddev;
		double inv_stddev;
	public:
		Gaussian( double mean, double stddev ) : dist(mean, stddev), mean(mean), stddev(stddev), inv_stddev(1/stddev) {};
		double random() {
			return dist(engine);
		}
		// Based on formula 7.1.26 from A&S
		double cdf( double x ) {
			// constants
			static const double a1 =  0.254829592;
			static const double a2 = -0.284496736;
			static const double a3 =  1.421413741;
			static const double a4 = -1.453152027;
			static const double a5 =  1.061405429;
			static const double p  =  0.3275911;

			// Save the sign of x
			int sign = 1;
			if (x < mean)
				sign = -1;
			x = fabs(x - mean)*inv_stddev/sqrt(2.0);

			// A&S formula 7.1.26
			double t = 1.0/(1.0 + p*x);
			double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

			return 0.5*(1.0 + sign*y);
		};
		double density( double x ) {
			static const float inv_sqrt_2pi = 0.3989422804014327;
			double t = (x - mean) * inv_stddev;
			return inv_sqrt_2pi * inv_stddev * std::exp(-.5 * t * t);
		};
};

// Uniform 0-1 distribution
class Uniform01: public Random {
	private:
		static std::uniform_real_distribution<double> dist;
	public:
		static double rand() {
			return dist(engine);
		};
};

std::uniform_real_distribution<double> Uniform01::dist(0.0, 1.0);

// [[Rcpp::export]]
double cdfCpp( double x, double mean, double stddev ) {
	Gaussian gauss(mean, stddev);
	return gauss.cdf(x);
}

// [[Rcpp::export]]
double densityCpp( double x, double mean, double stddev ) {
	Gaussian gauss(mean, stddev);
	return gauss.density(x);
}

// [[Rcpp::export]]
arma::vec randCpp( arma::uword n, double mean, double stddev ) {
	Gaussian gauss(mean, stddev);
	arma::vec x = arma::vec(n);
	for (arma::uword k = 0; k < n; k++)
		x(k) = gauss.random();
	return x;
}