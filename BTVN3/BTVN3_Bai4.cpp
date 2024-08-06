#include<stdio.h>
#include<stdlib.h>

#define MAX 100



int SoSanhTangDan(const void* a, const void* b) 
{
	return (*(int*)a - *(int*)b);
}


int SoSanhGiamDan(const void* a, const void* b) 
{
	return (*(int*)b - *(int*)a);
}

void SapXepDuongCheoPhu(int a[MAX][MAX], int n, int tangDan)
{
	int temp[MAX];
	for (int i = 0; i < n; i++) 
	{
		temp[i] = a[i][n - 1 - i];
	}

	if (tangDan)
	{
		qsort(temp, n, sizeof(int), SoSanhTangDan);
	}
	else 
	{
		qsort(temp, n, sizeof(int), SoSanhGiamDan);
	}

	
	for (int i = 0; i < n; i++)
	{
		a[i][n - 1 - i] = temp[i];
	}
}

void SapXepDong(int a[MAX][MAX], int n) 
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) {
			qsort(a[i], n, sizeof(int), SoSanhGiamDan);
		}
		else {
			qsort(a[i], n, sizeof(int), SoSanhTangDan);
		}
	}
}


void SapXepCot(int a[MAX][MAX], int n) {
	for (int j = 0; j < n; j++) {
		int temp[MAX];
		for (int i = 0; i < n; i++) {
			temp[i] = a[i][j];
		}

		if (j % 2 == 0) {
			qsort(temp, n, sizeof(int), SoSanhTangDan);
		}
		else {
			qsort(temp, n, sizeof(int), SoSanhGiamDan);
		}

		for (int i = 0; i < n; i++) {
			a[i][j] = temp[i];
		}
	}
}


void SapXepDuongCheoChinhVaSongSong(int a[MAX][MAX], int n) 
{
	for (int d = -n + 1; d < n; d++)
	{
		int temp[MAX];
		int k = 0;

		for (int i = 0; i < n; i++) 
		{
			int j = i + d;
			if (j >= 0 && j < n) 
			{
				temp[k++] = a[i][j];
			}
		}

		qsort(temp, k, sizeof(int), SoSanhTangDan);

		k = 0;
		for (int i = 0; i < n; i++) 
		{
			int j = i + d;
			if (j >= 0 && j < n) 
			{
				a[i][j] = temp[k++];
			}
		}
	}
}


void DiChuyenChanLe(int a[MAX][MAX], int n) 
{
	int temp[MAX * MAX];
	int k = 0;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (a[i][j] % 2 == 0) 
			{
				temp[k++] = a[i][j];
			}
		}
	}


	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0) 
			{
				temp[k++] = a[i][j];
			}
		}
	}

	
	k = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			a[i][j] = temp[k++];
		}
	}
}


int KiemTraDoiXungQuaDuongCheoChinh(int a[MAX][MAX], int n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (a[i][j] != a[j][i]) 
			{
				return 0;
			}
		}
	}
	return 1;
}
//In ma tr?n
void InMaTran(int a[MAX][MAX], int n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void menu()
{
	int choice;
	int n;
	int a[MAX][MAX];
	printf("Nhap cap cua ma tran vuong (n): ");
	scanf_s("%d", &n);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("\n----------------Menu--------------\n");
	printf("1. Sap xep duong cheo phu tang dan\n");
	printf("2. Sap xep duong cheo phu giam dan\n");
	printf("3. Sap xep cac dong (le tang dan, chan giam dan)\n");
	printf("4. Sap xep cac cot (le giam dan, chan tang dan)\n");
	printf("5. Sap xep cac duong cheo chinh va song song\n");
	printf("6. Di chuyen cac phan tu chan len dau va le xuong cuoi\n");
	printf("7. Kiem tra doi xung qua duong cheo chinh\n");
	printf("0. Thoat\n");
	do
	{
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			SapXepDuongCheoPhu(a, n, 1);
			printf("Ma tran sau khi sap xep duong cheo phu tang dan:\n");
			InMaTran(a, n);
			break;
		case 2:
			SapXepDuongCheoPhu(a, n, 0);
			printf("Ma tran sau khi sap xep duong cheo phu giam dan:\n");
			InMaTran(a, n);
			break;
		case 3:
			SapXepDong(a, n);
			printf("Ma tran sau khi sap xep cac dong (le tang dan, chan giam dan):\n");
			InMaTran(a, n);
			break;
		case 4:
			SapXepCot(a, n);
			printf("Ma tran sau khi sap xep cac cot (le giam dan, chan tang dan):\n");
			InMaTran(a, n);
			break;
		case 5:
			SapXepDuongCheoChinhVaSongSong(a, n);
			printf("Ma tran sau khi sap xep cac duong cheo chinh va song song:\n");
			InMaTran(a, n);
			break;
		case 6:
			DiChuyenChanLe(a, n);
			printf("Ma tran sau khi di chuyen cac phan tu chan len dau va le xuong cuoi:\n");
			InMaTran(a, n);
			break;
		case 7:
			if (KiemTraDoiXungQuaDuongCheoChinh(a, n)) {
				printf("Ma tran doi xung qua duong cheo chinh.\n");
			}
			else {
				printf("Ma tran khong doi xung qua duong cheo chinh.\n");
			}
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			exit(0);
		default:
			printf("Khong hop le.Moi nhap lai\n");
			break;
		}

	} while (choice!=0);

}

int main()
{
	menu();
	return 0;
}