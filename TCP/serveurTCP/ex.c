#include <stdio.h>

int main()
{
    int liste[] = {23,66,1,21}; // supposez que '23' est à l'adresse 0x77770210
    int* p = liste;
    
    printf("%d\n",liste[2]+3);
    printf("%d\n",*p+liste[0]);
    printf("%p\n",p);
    printf("%p\n",p+3);
    printf("%d\n",*p+3);
    printf("%d\n",*(p+3));

    return 0;
}
