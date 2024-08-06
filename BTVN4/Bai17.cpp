#include <stdio.h>

int tinhXn(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    return tinhXn(n - 1) + (n - 1) * tinhXn(n - 2);
}

int main() 
{
    int n;
    printf("Nhap gia tri cua n: ");
    scanf_s("%d", &n);
    printf("Gia tri cua X(%d) la: %d\n", n, tinhXn(n));
    return 0;
}