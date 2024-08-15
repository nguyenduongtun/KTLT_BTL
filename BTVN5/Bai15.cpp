//#include<stdio.h>
//
//
//long long TongA(int n);
//long long TinhA(int n);
//
//long long TongA(int n)
//{
//	if (n == 1) 
//	{
//		return 1;
//	}
//	return TongA(n - 1) + TinhA(n - 1);
//}
//
//
//long long TinhA(int n) 
//{
//	if (n == 1) 
//	{
//		return 1;
//	}
//	return n * TongA(n);
//}
//
//int main()
//{
//	int n;
//	printf("Nhap so nguyen duong n: ");
//	scanf_s("%d", &n);
//	long long result = TinhA(n);
//	printf("Gia tri cua A(%d) la: %lld\n", n, result);
//
//	return 0;
//}