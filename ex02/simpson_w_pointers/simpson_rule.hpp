double simpson_rule(double a, double b, int bins, double (*func)(double x));

// Pre-conditions
/*
- N must be a positive integer
- b >= a

Post-conditions
- The result is the integral of the specified function in the interval [a,b]

*/
