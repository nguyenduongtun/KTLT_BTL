#include<stdio.h>
#include<limits.h> 
#include<stdbool.h> 
#include<stdlib.h>
#define MAX 100


void XuatCotSoLe(int a[][MAX], int rows, int cols)
{
	bool ktra = false; // bi?n ki?m tra xem có c?t nào ch? ch?a s? l? không

	printf("Cac cot chi chua so le:\n");
	for (int j = 0; j < cols; j++) {
		bool isOdd = true;
		for (int i = 0; i < rows; i++)
		{
			if (a[i][j] % 2 == 0) {
				isOdd = false;
				break;
			}
		}
		if (isOdd)
		{
			ktra = true;
			printf("Cot %d: ", j);
			for (int i = 0; i < rows; i++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}

	if (!ktra)
		printf("Khong co cot nao chi chua so le.\n");
}
int TimMaxTrenBien(int a[][MAX], int rows, int cols) 
{
	int max = INT_MIN;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
			{
				if (a[i][j] > max) 
				{
					max = a[i][j];
				}
			}
		}
	}
	return max;
}

int DemPTSo2(int num)
{
	int count = 0;
	while (num != 0) 
	{
		if (num % 10 == 2) 
		{
			count++;
		}
		num /= 10;
	}
	return count;
}


int DemPhanTuCoSo2(int a[][MAX], int rows, int cols)
{
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (DemPTSo2(a[i][j]) > 0) 
			{
				count++;
			}
		}
	}
	return count;
}
void XuatPhanTuCucTieu(int a[][MAX], int rows, int cols)
{
	printf("Cac phan tu cuc tieu trong ma tran:\n");
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			bool isCucTieu = true;
			if (i > 0 && a[i][j] >= a[i - 1][j]) isCucTieu = false;
			if (i < rows - 1 && a[i][j] >= a[i + 1][j]) isCucTieu = false;
			if (j > 0 && a[i][j] >= a[i][j - 1]) isCucTieu = false;
			if (j < cols - 1 && a[i][j] >= a[i][j + 1]) isCucTieu = false;
			if (isCucTieu)
			{
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

void SapXepDong(int a[][MAX], int rows, int cols) 
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols - 1; j++) 
		{
			for (int k = j + 1; k < cols; k++) 
			{
				if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) 
				{
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}
void SapXepCot(int a[][MAX], int rows, int cols) 
{
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows - 1; i++) 
		{
			for (int k = i + 1; k < rows; k++) 
			{
				if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) 
				{
					int temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
			}
		}
	}
}
bool KiemTraGiamDan(int a[][MAX], int rows, int cols)
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols - 1; j++) 
		{
			if (a[i][j] < a[i][j + 1])
			{
				return false;
			}
		}
	}
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows - 1; i++) 
		{
			if (a[i][j] < a[i + 1][j]) 
			{
				return false;
			}
		}
	}
	return true;
}
void LietKeDongChan(int a[][MAX], int rows, int cols) 
{
	printf("Chi so cac dong chua toan gia tri chan:\n");
	for (int i = 0; i < rows; i++) 
	{
		bool allEven = true;
		for (int j = 0; j < cols; j++) 
		{
			if (a[i][j] % 2 != 0)
			{
				allEven = false;
				break;
			}
		}
		if (allEven) {
			printf("Dong %d\n", i);
		}
	}
}


void LietKeDongGiamDan(int a[][MAX], int rows, int cols) 
{
	printf("Chi so cac dong chua gia tri giam dan:\n");
	for (int i = 0; i < rows; i++) 
	{
		bool isGiamDan = true;
		for (int j = 0; j < cols - 1; j++) 
		{
			if (a[i][j] < a[i][j + 1]) 
			{
				isGiamDan = false;
				break;
			}
		}
		if (isGiamDan) {
			printf("Dong %d\n", i);
		}
	}
}


int TimGiaTriXuatHienNhieuNhat(int a[][MAX], int rows, int cols) 
{
	int maxCount = 0;
	int giaTri = a[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) 
		{
			int count = 0;
			for (int k = 0; k < rows; k++) 
			{
				for (int l = 0; l < cols; l++) 
				{
					if (a[i][j] == a[k][l])
					{
						count++;
					}
				}
			}
			if (count > maxCount) 
			{
				maxCount = count;
				giaTri = a[i][j];
			}
		}
	}
	return giaTri;
}


int TimChuSoXuatHienNhieuNhat(int a[][MAX], int rows, int cols) 
{
	int count[10] = { 0 };
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			int num = a[i][j];
			while (num != 0) 
			{
				count[num % 10]++;
				num /= 10;
			}
		}
	}
	int maxCount = 0;
	int chuSo = 0;
	for (int i = 0; i < 10; i++) 
	{
		if (count[i] > maxCount) 
		{
			maxCount = count[i];
			chuSo = i;
		}
	}
	return chuSo;
}


void LietKeCotCoTongNhoNhat(int a[][MAX], int rows, int cols) 
{
	int minSum = INT_MAX;
	int minCol = -1;
	for (int j = 0; j < cols; j++) 
	{
		int sum = 0;
		for (int i = 0; i < rows; i++) 
		{
			sum += a[i][j];
		}
		if (sum < minSum) 
		{
			minSum = sum;
			minCol = j;
		}
	}
	printf("Cac cot co tong nho nhat la: ");
	for (int j = 0; j < cols; j++) 
	{
		int sum = 0;
		for (int i = 0; i < rows; i++) 
		{
			sum += a[i][j];
		}
		if (sum == minSum) 
		{
			printf("%d ", j);
		}
	}
	printf("\n");
}


void HoanViCot(int a[][MAX], int rows, int i, int j) 
{
	for (int k = 0; k < rows; k++) 
	{
		int temp = a[k][i];
		a[k][i] = a[k][j];
		a[k][j] = temp;
	}
}

void HoanViDong(int a[][MAX], int cols, int k, int l) 
{
	for (int i = 0; i < cols; i++)
	{
		int temp = a[k][i];
		a[k][i] = a[l][i];
		a[l][i] = temp;
	}
}
void menu()
{
	int a[MAX][MAX];
	int rows, cols;
	int choice;
	printf("Nhap so dong cua ma tran: ");
	scanf_s("%d", &rows);
	printf("Nhap so cot cua ma tran: ");
	scanf_s("%d", &cols);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("\n'---------------Menu----------------\n");
	printf("1. Xuat cac cot chi chua so le\n");
	printf("2. Phan tu lon nhat trong cac phan tu tren bien cua ma tran\n");
	printf("3. Tim so phan tu co chu so 2 xuat hien trong chu so cua no\n");
	printf("4. Xuat phan tu cuc tieu\n");
	printf("5. Sap xep ma tran cho cac dong co so le tang dan, so chan giam dan\n");
	printf("6. Sap xep ma tran cho cac cot co so le giam dan, so chan tang dan\n");
	printf("7. Kiem tra ma tran giam dan theo cot va dong(ziczac\n");
	printf("8. Liet ke cac dong chua toan chan\n");
	printf("9. Liet ke cac dong chua gia tri giam dan\n");
	printf("10. Tim gia tri xuat hien nhieu nhat trong ma tran\n");
	printf("11. Tim cac chu so xuat hien nhieu nhat trong ma tran\n");
	printf("12. Liet ke cac cot co tong gia tri nho nhat trong ma tran\n");
	printf("13. Hoan vi hai cot i va j trong ma tran\n");
	printf("14. Hoan vi 2 dong k va l trong ma tran\n");
	printf("0. Thoat\n");
	do
	{
		printf("Nhap lua chon: \n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			XuatCotSoLe(a, rows, cols);
			break;
		case 2:
			printf("Phan tu lon nhat tren bien cua ma tran la: %d\n", TimMaxTrenBien(a, rows, cols));
			break;
		case 3:
			printf("So phan tu co chu so 2 xuat hien trong chu so cua no: %d\n", DemPhanTuCoSo2(a, rows, cols));
			break;
		case 4:
			XuatPhanTuCucTieu(a, rows, cols);
			break;
		case 5:
			SapXepDong(a, rows, cols);
			printf("Ma tran sau khi sap xep cac dong (le tang dan, chan giam dan):\n");
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++) 
				{
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
			break;
		case 6:
			SapXepCot(a, rows, cols);
			printf("Ma tran sau khi sap xep cac cot (le giam dan, chan tang dan):\n");
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
			break;
		case 7:
			printf("Ma tran giam dan theo cot va dong (ziczac): %s\n", KiemTraGiamDan(a, rows, cols) ? "Dung" : "Sai");
		case 8:
			LietKeDongChan(a, rows, cols);
			break;
		case 9:
			LietKeDongGiamDan(a, rows, cols);
			break;
		case 10:
			printf("Gia tri xuat hien nhieu nhat trong ma tran la: %d\n", TimGiaTriXuatHienNhieuNhat(a, rows, cols));
			break;
		case 11:
			printf("Chu so xuat hien nhieu nhat trong ma tran la: %d\n", TimChuSoXuatHienNhieuNhat(a, rows, cols));
			break;
		case 12:
			LietKeCotCoTongNhoNhat(a, rows, cols);
			break;
		case 13:
			int i, j;
			printf("Nhap chi so hai cot can hoan vi: ");
			scanf_s("%d %d", &i, &j);
			HoanViCot(a, rows, i, j);
			printf("Ma tran sau khi hoan vi cot %d va cot %d:\n", i, j);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
			break;
		case 14:
			int k, l;
			printf("Nhap chi so hai dong can hoan vi: ");
			scanf_s("%d %d", &k, &l);
			HoanViDong(a, cols, k, l);
			printf("Ma tran sau khi hoan vi dong %d va dong %d:\n", k, l);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
		case 0:
			printf("Thoat chuong trinh");
			exit(0);
		default:
			printf("Khong hop le.Moi nhap lai");
			break;
		}
	} while (choice!=0);
}
int main()
{

	menu();
	return 0;
}