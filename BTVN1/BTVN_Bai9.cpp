#include<stdio.h>

void main()
{
	int a, b;
	int* pa, * pb;
	int tong, hieu, tich;
	float thuong;

	
	printf("Nhap so a: ");
	scanf_s("%d", &a);
	printf("Nhap so b: ");
	scanf_s("%d", &b);

	
	pa = &a;
	pb = &b;

	
	tong = *pa + *pb;
	hieu = *pa - *pb;
	tich = (*pa) * (*pb);
	thuong = (float)(*pa) / (*pb); 

	
	printf("Tong cua %d và %d là: %d, tai dia chi: %p\n", *pa, *pb, tong, (void*)&tong);
	printf("Hieu cua %d và %d là: %d, tai dia chi: %p\n", *pa, *pb, hieu, (void*)&hieu);
	printf("Tich cua %d và %d là: %d, tai dia chi: %p\n", *pa, *pb, tich, (void*)&tich);
	printf("Thuong cua %d và %d là: %.2f, tai dia chi: %p\n", *pa, *pb, thuong, (void*)&thuong);

}
