#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lire_mem(char* p, int n) {
    for (int i=0;i<n;i++) {
        printf("p=%p; *p=%x\n",p,*p);
        p++;
    }   
}

int main() {
    int v1 = 25; 
    float v2 = 34.908; 
    long int v3 = 908445;

    printf("%d\n",v1);
    lire_mem(&v1,sizeof(v1));
    printf("\n%f\n",v2);
    lire_mem(&v2,sizeof(v2));
    printf("\n%li\n",v3);
    lire_mem(&v3,sizeof(v3));
    
}