#include <stdio.h>




int foo(int n)
{
    int sum; //需要调试的地方
    int i;

    for (i=0; i<=n; i++)
    {
        sum = sum+i;
    }
    return sum;
}


int main(int argc, char** argv)
{
    int result = 0;
    int N = 100;
    result = foo(N);
    printf("1+2+3+...+%d= %d\n", N, result);
    return 0;
}
