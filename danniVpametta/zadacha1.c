#include <stdio.h>
#include <limits.h>

#define PRINTING(TYPE, FORMAT, BYTES, MAX, MIN, U, UMAX) printf("%-12s%-12s%-16zu%-20d%-20d%-20s%-10u\n", TYPE, FORMAT,BYTES, MAX, MIN, U, UMAX)
int main()
{

    printf("%-12s%-12s%-16s%-20s%-20s%-20s%-10s\n", "Type", "Format", "Bytes used", "Signed max value", "Signed min value", "Unsigned format", "Unsigned max");
    PRINTING("int", "%d", sizeof(int), INT_MAX, INT_MIN, "%u", UINT_MAX);
    PRINTING("char", "%c", sizeof(char), CHAR_MAX, CHAR_MIN, "%u", UCHAR_MAX);
    PRINTING("long", "%ld", sizeof(long), LONG_MAX, LONG_MIN, "%lu", ULONG_MAX);
    PRINTING("long long", "%lld", sizeof(long long), LLONG_MAX, LLONG_MIN, "%llu", ULLONG_MAX);
    PRINTING("short", "%hd", sizeof(short), SHRT_MAX, SHRT_MIN, "%hu", USHRT_MAX);
   

    return 0;
}
