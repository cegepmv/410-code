#include <stdio.h>

void changerVal(int* x, int* y) {
    int temp;

    /* printf("x=%p\t&x=%p\t*x=%d\n",x,&x,*x);
    printf("y=%p\t&y=%p\t*y=%d\n",y,&y,*y); */

    temp = *x;
    /* printf("\ntemp = *x\n---------\n");
    printf("temp=%p\t\t&temp=%p\t*temp=???\n",temp,&temp);
    printf("x=%p\t&x=%p\t*x=%d\n",x,&x,*x);
    printf("y=%p\t&y=%p\t*y=%d\n",y,&y,*y); */
    
    *x = *y;
    /* printf("\n*x = *y;\n---------\n");
    printf("temp=%p\t\t&temp=%p\t*temp=???\n",temp,&temp);
    printf("x=%p\t&x=%p\t*x=%d\n",x,&x,*x);
    printf("y=%p\t&y=%p\t*y=%d\n",y,&y,*y); */

    *y = temp;
    /* printf("\n*y = temp;\n---------\n");
    printf("temp=%p\t\t&temp=%p\t*temp=???\n",temp,&temp);
    printf("x=%p\t&x=%p\t*x=%d\n",x,&x,*x);
    printf("y=%p\t&y=%p\t*y=%d\n",y,&y,*y); */
}

int main() {

    int a = 11;
    int b = 22;
    
    changerVal(&a,&b);
    printf("a=%d, b=%d\n",a,b); // Doit afficher "a=22, b=11"

}