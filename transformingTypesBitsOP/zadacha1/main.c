#include <stdio.h>
#include "quadraticroots.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct QuadraticRootsResult intResult = findRoots(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    if (intResult.noRealRoots)
    {
        printf("The equation has no real roots.\n");
    }
    else
    {
        printf("The roots of the equation are %lf and %lf.\n", intResult.x1, intResult.x2);
    }

    struct QuadraticRootsResult floatResult = findRoots(atof(argv[1]), atof(argv[2]), atof(argv[3]));
    if (floatResult.noRealRoots)
    {
        printf("The equation has no real roots.\n");
    }
    else
    {
        printf("The roots of the equation are %f and %f.\n", floatResult.x1, floatResult.x2);
    }

    struct QuadraticRootsResult doubleResult = findRoots(atof(argv[1]), atof(argv[2]), atof(argv[3]));
    if (doubleResult.noRealRoots)
    {
        printf("The equation has no real roots.\n");
    }
    else
    {
        printf("The roots of the equation are %lf and %lf.\n", doubleResult.x1, doubleResult.x2);
    }

    return 0;
}
