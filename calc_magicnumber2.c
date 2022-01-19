#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(void) {
    char HellocWorld[16] = "Hello,World\n\0\0\0"; // 最後に改行と 0 がつく。
    
    /*
    //assert(j < 99);
    printf("%s\n", HellocWorld);
    size_t len = strlen(HellocWorld);
    for (int i = 0; i < len+1; i++) {
        printf("%02x, ", HellocWorld[i]);
    }
    printf("\n");
    // 48, 65, 6c, 6c, 6f, 2c, 57, 6f, 72, 6c, 64, 0a, 00
    
    
    //float 分析
    float a[4];
    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 3.0;
    a[3] = 4.0;
    char* ap = (char*)&a[0];
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
        printf("%02x, ", *ap);
        ap++;
    }
    printf("|");
    }
    printf("\n");
    */
    //そうか、ap型のポインタを使ってfloatの中身を48, 65, 6c, 6c, 6f, ... で書き換えてしまえば答えが出てくるぞ！？

    float b[4];
    char* ap2 = (char*)&b[0];
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
        *ap2 = HellocWorld[4 * j + i];
        printf("%02x, ", *ap2); // ちゃんとそうなってるか見てみる。
        ap2++;
    }
    printf("|");
    }
    printf("\n");

    printf("%s", (char*)b);

    return EXIT_SUCCESS;
}