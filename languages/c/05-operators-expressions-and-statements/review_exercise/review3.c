#include <stdio.h>
int main(void)
{
    int x1, x2, x3, x4, x5, x6;

    x1 = 30.0 / 4.0 * 5.0; // 37
    x2 = 30.0 / (4.0 * 5.0); // 1
    x3 = 30 / 4 * 5; // 37
    x4 = 30 * 5 / 4 ; // 37
    x5 = 30 / 4.0 * 5; // 37
    x6 = 30 / 4 * 5.0; // 1

    printf("%d %d %d %d %d %d\n", x1, x2, x3, x4, x5, x6);
}
