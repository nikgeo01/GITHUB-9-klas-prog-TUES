#include <stdio.h>

#define ARRAY_SIZE 6

int main()
{

#ifdef ARRAY_SIZE
    #if ARRAY_SIZE > 0 && ARRAY_SIZE < 10
        double arr[ARRAY_SIZE];
        for(int i=0; i<ARRAY_SIZE; i++)
        {
            int elem = 1;
            for(int j=0; j<i; j++)
            {
                elem *= 2;
            }
            arr[i] = elem;
        }

        for(int i=0; i<ARRAY_SIZE; i++)
        {
          printf("%f\n",arr[i]);
        }
    #endif
#endif

    return 0;
}