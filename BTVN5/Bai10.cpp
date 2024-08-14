#include<stdio.h>

long long Fibonacci(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        long long a = 1, b = 1, c = 0;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

// Hàm in các số Fibonacci thuộc đoạn [m, n]
void Xuat_Fibonacci(int m, int n)
{
    int i = 1;
    long long fibo;
    printf("Cac so Fibonacci thuoc doan [%d, %d]:\n", m, n);
    while (1)
    {
        fibo = Fibonacci(i);
        if (fibo > n)
        {
            break;
        }
        if (fibo >= m)
        {
            printf("%lld ", fibo);
        }
        i++;
    }
    printf("\n");
}

int main()
{
    int m, n;
    printf("Nhap gia tri m: ");
    scanf_s("%d", &m);
    printf("Nhap gia tri n: ");
    scanf_s("%d", &n);
    Xuat_Fibonacci(m, n);

    return 0;
}
