#include "animal.hpp"
#include <cassert>

// define static members
Genome::age_t Animal::bad_threshold_;
Genome::age_t Animal::maturity_age_;

void Animal::set_maturity_age(Genome::age_t age)
{
    maturity_age_ = age;
}

void Animal::set_bad_threshold(Genome::age_t t)
{
    bad_threshold_ = t;
}

Genome::age_t Animal::get_bad_threshold()
{
    return bad_threshold_;
}

Animal::Animal() : gen_(), age_(0){};
Animal::Animal(const Genome &gen) : gen_(gen), age_(0){};

bool Animal::is_dead() const
{
    return gen_.count_bad(age_) > bad_threshold_;
}

bool Animal::is_pregnant() const
{
    return pregnant_;
}

Genome::age_t Animal::age() const
{
    return age_;
}

void Animal::grow()
{
    assert(!(is_dead()));
    age_++;
    if (age_ > maturity_age_ && !pregnant_)
        pregnant_ = true;
}

Animal Animal::give_birth()
{
    pregnant_ = false;
    Genome child_genome = gen_;
    child_genome.mutate();
}