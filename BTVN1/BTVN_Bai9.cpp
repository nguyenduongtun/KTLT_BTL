#include<stdio.h>

void main()
{
	int a, b;
	int* pa, * pb;
	int tong, hieu, tich;
	float thuong;

	// G�n gi� tr? cho a v� b
	printf("Nhap so a: ");
	scanf_s("%d", &a);
	printf("Nhap so b: ");
	scanf_s("%d", &b);

	// G�n ??a ch? c?a a v� b cho c�c con tr? pa v� pb
	pa = &a;
	pb = &b;

	// T�nh to�n t?ng, hi?u, t�ch, v� th??ng
	tong = *pa + *pb;
	hieu = *pa - *pb;
	tich = (*pa) * (*pb);
	thuong = (float)(*pa) / (*pb); // �p ki?u ?? t�nh th??ng ch�nh x�c h?n

	
	printf("Tong cua %d v� %d l�: %d, tai dia chi: %p\n", *pa, *pb, tong, (void*)&tong);
	printf("Hieu cua %d v� %d l�: %d, tai dia chi: %p\n", *pa, *pb, hieu, (void*)&hieu);
	printf("Tich cua %d v� %d l�: %d, tai dia chi: %p\n", *pa, *pb, tich, (void*)&tich);
	printf("Thuong cua %d v� %d l�: %.2f, tai dia chi: %p\n", *pa, *pb, thuong, (void*)&thuong);

}