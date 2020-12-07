#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "genome.hpp"

class Animal
{
public:
    static const Genome::age_t maximum_age = Genome::number_of_genes; ///< upper age limit

    static void set_maturity_age(Genome::age_t);  ///< set maturity age
    static void set_bad_threshold(Genome::age_t); ///< set threshold for deletrious mutation
    static Genome::age_t get_bad_threshold();     ///< get deletrious mutation threshold

    Animal();               ///< default constructor: Uses all good genome
    Animal(const Genome &); ///< constructor using a given genome

    bool is_dead() const;      ///< get death status
    bool is_pregnant() const;  ///< get pregnancy status
    Genome::age_t age() const; ///< get age

    void grow();         ///< grow the animal older by one year
    Animal give_birth(); ///< create baby with inherited, randomly mutated genes

private:
    static Genome::age_t bad_threshold_; ///< number T of bad genes an animal can tolerate
    static Genome::age_t maturity_age_;  ///< maturity age parameter R

    const Genome gen_;
    Genome::age_t age_;
    bool pregnant_;
};

#endif // end of ANIMAL_HPP