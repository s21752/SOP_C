#include <stdio.h>
#include <stdlib.h>

int recursive(int index);
int iterative(int index);

int main()
{
    printf("Fibonacci number recursive: %d\n", recursive(9));
    printf("Fibonacci number iterative: %d\n", iterative(3));

    return 0;
}

int recursive(int index) {

    if(index == 0) {
        return 0;
    }

    if (index == 1) {
        return 1;
    }

    return recursive(index - 1) + recursive(index - 2);
}

int iterative(int index) {
    int a=0, b=1, temp=a;

    for(int i=0; i<index; i++) {
        temp = b;

        b = b + a;
        a = temp;
    }

    return temp;
}


