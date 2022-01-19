#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

int main(void) {
    printf("F1 = %ld, F10 = %ld, F90 = %ld", fibo(1), fibo(10), fibo(90));
    return 0;
}