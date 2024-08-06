//#include <stdio.h>
//
//int tinhAn(int n);
//
//// tinh tong tu a -> a(n)
//int tinhTong(int n) 
//{
//    if (n == 1)
//        return 1;
//    return tinhAn(n - 1) + tinhTong(n - 1);
//}
//
//// de quy tinh a(n)
//int tinhAn(int n) 
//{
//    if (n == 1)
//        return 1;
//    return n * tinhTong(n);
//}
//
//int main()
//{
//    int n;
//    printf("Nhap gia tri cua n: ");
//    scanf_s("%d", &n);
//    printf("Gia tri cua A(%d) la: %d\n", n, tinhAn(n));
//    return 0;
//}