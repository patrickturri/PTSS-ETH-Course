#include <numeric>
#include <cstdlib> // drand48()
#include <array>
#include "genome.hpp"

// Definition of the static variables.
Genome::age_t Genome::mutation_rate_;

void Genome::set_mutation_rate(age_t m)
{
    mutation_rate_ = m;
}

Genome::age_t Genome::count_bad(age_t n) const
{
    return (Genome::genes_ << (number_of_genes - n - 1)).count();
}

void Genome::mutate()
{
    std::array<unsigned char, number_of_genes> ages;
    std::iota(std::begin(ages), std::end(ages), 0);
    for (size_t i = 0; i < mutation_rate_; ++i)
    {
        const size_t pivot = i + drand48() * (number_of_genes - i);
        genes_.flip(ages[pivot]);
        std::swap(ages[pivot], ages[i]);
    }
}