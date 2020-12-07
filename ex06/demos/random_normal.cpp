#include <iostream>
#include <iomanip> // for setfill & setw
#include <cmath>
#include <vector>
#include <random> // c++11

int main()
{

    // default random engine
    std::default_random_engine e;
    e.seed(42); // set seed

    // set distribution
    double mu = 0.;    // mean
    double sigma = 1.; // standard deviation
    std::normal_distribution<double> dist(mu, sigma);

    // histogram parameters
    double hist_low = mu - 4 * sigma;
    double hist_upp = mu + 4 * sigma;
    int nbins = 21;                              // number of bins in histogram
    double dbin = (hist_upp - hist_low) / nbins; // bin size
    std::vector<int> hist(nbins);

    // generate histogram
    int Nsamples = 10000; // number of samples
    double rnd;
    int index;
    for (int i = 0; i < Nsamples; i++)
    {
        rnd = dist(e);
        index = std::round((rnd - hist_low) / dbin);
        index = std::max(0, index);         // clip index
        index = std::min(nbins - 1, index); // clip index
        hist[index] += 1;
    }

    // find largest bin
    int maxH = hist[0];
    for (int i = 0; i < nbins; i++)
    {
        maxH = std::max(maxH, hist[i]);
    }

    // print histogram
    for (int i = 0; i < nbins; i++)
    {
        int histn = hist[i] * (72. / maxH); // normalize to terminal width
        std::cout << std::setfill('0') << std::setw(2) << i << ": "
                  << std::string(histn, '*') << std::endl;
    }
}
