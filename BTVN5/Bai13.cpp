//#include<stdio.h>
//
//
//
//long long CapSoNhandequy(int n, long long a, long long q) 
//{
//	if (n == 1) 
//	{
//		return a;
//	}
//	return q * CapSoNhandequy(n - 1, a, q);
//}
//
//int main() 
//{
//	int n;
//	long long a, q;
//	printf("Nhap gia tri hang dau a: ");
//	scanf_s("%lld", &a);
//	printf("Nhap gia tri cong boi q: ");
//	scanf_s("%lld", &q);
//	printf("nhap gia tri phan tu n: ");
//	scanf_s("%d", &n);
//	long long result = CapSoNhandequy(n, a, q);
//	printf("Phan tu thu %d cua cap so nhan la: %lld\n", n, result);
//
//	return 0;
//}