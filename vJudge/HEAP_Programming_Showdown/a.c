#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    while (n != 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }
    printf("%d\n", sum);
    return 0;
}