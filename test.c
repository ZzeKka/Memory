#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h> 

void test(int *n);

int main(void)   
{
    int x = 4;
    test(&x);
    return 0;
}

void test(int *n)
{
    printf("%d\n", n);
}
