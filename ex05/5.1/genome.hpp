#ifndef GENOME_HPP
#define GENOME_HPP

#include <iostream>

class Genome
{
public:
    using age_t = unsigned int;
    static const age_t number_of_genes = std::numeric_limits<unsigned long>::digits;
    void set_mutation_rate(age_t);
    void mutate();
    Genome(){};               // default ctor
    Genome(const Genome &){}; // copy ctor
    ~Genome() {}              // dctor
    age_t count_bad(age_t) const;

private:
    std::bitset<number_of_genes> genes_;
    static age_t mutation_rate_; // random mutations, it will be the index where the mutation will occur in the genome bitset
};

#endif