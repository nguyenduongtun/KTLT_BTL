//#include <stdio.h>
//
//int tinhYn(int n) 
//{
//    if (n == 1)
//        return 1;
//    if (n == 2)
//        return 2;
//    if (n == 3)
//        return 3;
//    return tinhYn(n - 1) + 2 * tinhYn(n - 2) + 3 * tinhYn(n - 3);
//}
//
//int main() 
//{
//    int n;
//    printf("Nhap gia tri cua n: ");
//    scanf_s("%d", &n);
//    printf("Gia tri cua Y(%d) la: %d\n", n, tinhYn(n));
//    return 0;
//}