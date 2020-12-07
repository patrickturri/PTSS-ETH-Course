/**
 * Header for Penna animal class.
 * Programming Techniques for Scientific Simulations, HS 2020
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "genome.hpp"

/// Penna namespace.
namespace Penna
{

    /// Animal with a Genome and age.
    class Animal
    {
    public:
        static const age_t maximum_age = Genome::number_of_genes; ///< upper age limit

        static void set_maturity_age(age_t);                 ///< set maturity age
        static void set_probability_to_get_pregnant(double); ///< set birth rate modifier

        static void set_bad_threshold(age_t); ///< set threshold for deletrious mutation
        static age_t get_bad_threshold();     ///< get deletrious mutation threshold

        Animal();               ///< default constructor: Uses all good genome
        Animal(const Genome &); ///< constructor using a given genome

        bool is_dead() const;     ///< get death status
        bool is_pregnant() const; ///< get pregnancy status
        age_t age() const;        ///< get age

        void grow();         ///< grow the animal older by one year
        Animal give_birth(); ///< create baby with inherited, randomly mutated genes

    private:
        static age_t bad_threshold_;                ///< number T of bad genes an animal can tolerate
        static age_t maturity_age_;                 ///< maturity age parameter R
        static double probability_to_get_pregnant_; ///< birth rate modifier b

        const Genome gen_;
        age_t age_;
        bool pregnant_;
    };

} // namespace Penna

#endif // ANIMAL_HPP
