#include<stdio.h>

int main (int argc, char* argv[]){
    int var1 = 1;
    int var2 = 2;
    int* pointer;

    pointer = &var1;
    printf("var1=%d var2=%d &var1=%p, &var2=%p, pointer=%p *pointer=%d\n", var1, var2, &var1, &var2, &pointer, *pointer);

    *pointer = 11;
    printf("var1=%d var2=%d &var1=%p, &var2=%p, pointer=%p *pointer=%d\n", var1, var2, &var1, &var2, &pointer, *pointer);

    pointer = &var2;
    printf("var1=%d var2=%d &var1=%p, &var2=%p, pointer=%p *pointer=%d\n", var1, var2, &var1, &var2, &pointer, *pointer);

    *pointer = 21;
    printf("var1=%d var2=%d &var1=%p, &var2=%p, pointer=%p *pointer=%d\n", var1, var2, &var1, &var2, &pointer, *pointer);

    printf("the pointer itself is located at %p\n", &pointer);
}
