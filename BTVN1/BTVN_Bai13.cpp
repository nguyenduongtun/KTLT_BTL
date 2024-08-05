#include<stdio.h>

#define MAX_SIZE 100 

void TinhChiaMang(int a[], int b[], int sizea, int sizeb)
{
	
	if (sizea != sizeb)
	{
		printf("Kich thuoc cua hai mang phai bang nhau.\n");
		return;
	}

	printf("Ket qua phep chia cac phan tu mang a cho cac phan tu mang b:\n");

	for (int i = 0; i < sizea; i++)
	{
		if (b[i] == 0) 
		{
			printf("Phan tu b[%d] = 0: Khong the chia cho 0.\n", i);
		}
		else 
		{
			printf("a[%d] / b[%d] = %f\n", i, i, (float)a[i] / b[i]);
		}
	}
}

void main() 
{
	int a[MAX_SIZE], b[MAX_SIZE];
	int sizea, sizeb;
	printf("Nhap so phan tu cua mang a: ");
	scanf_s("%d", &sizea);
	if (sizea <= 0 || sizea > MAX_SIZE) 
	{
		printf("Kich thuoc mang a khong hop le.\n");
		
	}
	printf("Nhap cac phan tu cua mang a:\n");
	for (int i = 0; i < sizea; i++) 
	{
		printf("a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}

	printf("Nhap so phan tu cua mang b: ");
	scanf_s("%d", &sizeb);
	if (sizeb <= 0 || sizeb > MAX_SIZE) 
	{
		printf("Kich thuoc mang b khong hop le.\n");
		
	}
	printf("Nhap cac phan tu cua mang b:\n");
	for (int i = 0; i < sizeb; i++) 
	{
		printf("b[%d]: ", i);
		scanf_s("%d", &b[i]);
	}

	TinhChiaMang(a, b, sizea, sizeb);


}