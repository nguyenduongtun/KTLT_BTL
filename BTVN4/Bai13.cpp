//#include <stdio.h>
//
//double timGiaTri(int n, double a, double q) 
//{
//    if (n == 1)
//        return a;
//    return q * timGiaTri(n - 1, a, q);
//}
//
//int main() 
//{
//    int n;
//    double a, q;
//    printf("Nhap gia tri cua n: ");
//    scanf_s("%d", &n);
//    printf("Nhap gia tri cua a: ");
//    scanf_s("%lf", &a);
//    printf("Nhap gia tri cua q: ");
//    scanf_s("%lf", &q);
//    printf("Phan tu thu %d cua cap so nhan la: %lf\n", n, timGiaTri(n, a, q));
//    return 0;
//}