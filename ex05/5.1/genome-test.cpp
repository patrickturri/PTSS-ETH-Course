
#include "genome.hpp"
#include <cassert>
#include <iostream>

void test(int M)
{

    Genome::set_mutation_rate(M);
    Genome parent_g; // create obj parent
    Genome child_g;  // create obj child

    for (size_t index = 0; index < 1000; ++index)
    {
        child_g = Genome(parent_g); // call to copy ctor
        child_g.mutate();

        // Age a parent and child over their lifetime, tracking their difference.
        // Check that child's count_bad differs at most by one per year.
        // Check the current year's gene bit and keep track of the difference
        // between parent and child. This should stay within the mutation rate.
        // The child becomes the new parent for the next iteration.
        int diff = child_g.count_bad(0) == parent_g.count_bad(0) ? 0 : 1;
        for (size_t age = 1; age < Genome::number_of_genes; ++age)
        {
            const size_t deletrious = child_g.count_bad(age);
            const size_t deletrious_prev = child_g.count_bad(age - 1);
            assert((deletrious_prev == deletrious) ||
                   (deletrious_prev + 1 == deletrious));
            const size_t child_b = deletrious - deletrious_prev;
            const size_t parent_b = parent_g.count_bad(age) - parent_g.count_bad(age - 1);
            if (parent_b != child_b)
                ++diff;
        }
        assert(diff <= M && (diff % 2 == M % 2));
        parent_g = child_g;
    }
}

int main()
{

    // seed the random number generator
    srand(42);

    // run the test
    for (size_t M = 1; M < 5; ++M)
        test(M);
    std::cout << "Genome tests passed." << std::endl;
    return 0;
}
