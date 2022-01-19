#pragma once

typedef struct matrix {
    long a11;
    long a12;
    long a21;
    long a22;
} Matrix;

long fibo(int n);
Matrix getAn(int n);