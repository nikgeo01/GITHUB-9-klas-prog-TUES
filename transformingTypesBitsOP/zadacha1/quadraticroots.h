#if !defined(QUADRATICROOTS_H)
#define QUADRATICROOTS_H

struct QuadraticRootsResult
{
    double x1;
    double x2;

    int noRealRoots;
};

struct QuadraticRootsResult findRoots(double a, double b, double c);

#endif



