#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a = 64999;
    char *p;

    p = &a;
    for (int i=0;i<4;i++) {
        printf("p=%p; *p=%x\n",p,*p);
        p++;
    }
}