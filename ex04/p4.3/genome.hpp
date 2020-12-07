/**
 * Header for Penna genome class.
 * Programming Techniques for Scientific Simulations, HS 2020
 */

#ifndef GENOME_HPP
#define GENOME_HPP

#include <bitset>
#include <limits>

/// Penna namespace.
namespace Penna
{

    /// Type for age of Genome holders.
    using age_t = unsigned int;

    /// Genome class representing each gene with one bit.
    class Genome
    {
    public:
        // Up to this size bitset is a lot faster.
        static const age_t number_of_genes = ///< genome size
            std::numeric_limits<unsigned long>::digits;

        static void set_mutation_rate(age_t); ///< rate of mutation at birth

        // Default constructor: Initialize genes to all good.
        // Genome() {};  // provided by the compiler

        age_t count_bad(age_t) const; ///< count number of bad genes in first n years
        void mutate();                ///< mutate the genome by flipping of M genes

    private:
        static age_t mutation_rate_; ///< parameter M in Penna's paper
        std::bitset<number_of_genes> genes_;
    };

} // namespace Penna

#endif // GENOME_HPP
