#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "fibo.h"

Matrix mul(Matrix An, Matrix Bn) {
    Matrix AnBn;
    AnBn.a11 = An.a11 * Bn.a11 + An.a12 * Bn.a21;
    AnBn.a12 = An.a11 * Bn.a12 + An.a12 * Bn.a22;
    AnBn.a21 = An.a21 * Bn.a11 + An.a22 * Bn.a21;
    AnBn.a22 = An.a21 * Bn.a12 + An.a22 * Bn.a22;
    return AnBn;
}

//再帰関数
Matrix getAn(int n) {
    Matrix Anresult;
    Anresult.a11 = 0;
    Anresult.a12 = 0;
    Anresult.a21 = 0;
    Anresult.a22 = 0;
// 0, 1, 偶数、奇数
    if (n == 0) {
        Anresult = (Matrix){ .a11 = 1, .a12 = 0, .a21 = 0, .a22 = 1};
        return Anresult;
    }
    if (n == 1) {
        Anresult = (Matrix){ .a11 = 1, .a12 = 1, .a21 = 1, .a22 = 0};
        return Anresult;
    }
    if (n % 2 == 0) {
        Anresult = getAn(n/2);
        return mul(Anresult, Anresult); // 2乗を計算する
    }

    if (n % 2 == 1) {
        Anresult = getAn((n-1)/2);
        return mul(mul(Anresult, Anresult), (Matrix){ .a11 = 1, .a12 = 1, .a21 = 1, .a22 = 0}); // 2乗を計算する
    }
    return Anresult;

}

long fibo(int n) {
    assert(n <= 90 && n >= 0); //負の数でも×にする。
    if (n = 0) return 1;
    
    Matrix Anminus1 = getAn(n - 1);
    long F0 = 1;
    long F1 = 1;
    long Fn = Anminus1.a11 * F1 + Anminus1.a12 * F0;
    long Fnminus1 = Anminus1.a21 * F1 + Anminus1.a22 * F0;
    printf("%ld, %ld\n", Fn, Fnminus1);
    return Fn;
}