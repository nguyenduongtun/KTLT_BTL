//#include<stdio.h>
//
//
//long long Fibonacci(int n) 
//{
//	if (n <= 2) 
//	{
//		return 1;
//	}
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//
//// Hàm tìm s? Fibonacci l?n nh?t nh?ng nh? h?n n (?? quy)
//long long FibonaccimaxDeQuy(int n, int i, long long a, long long b)
//{
//	if (a + b >= n) 
//	{
//		return b;
//	}
//	return FibonaccimaxDeQuy(n, i + 1, b, a + b);
//}
//
//int main() 
//{
//	int n;
//	printf("Nhap so nguyen duong n: ");
//	scanf_s("%d", &n);
//	long long result = FibonaccimaxDeQuy(n, 1, 1, 1);
//	printf("So Fibonacci lon nhat nhung nho hon %d (de quy): %lld\n", n, result);
//
//	return 0;
//}