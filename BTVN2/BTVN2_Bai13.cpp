#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define GIA_VE_TRE_EM 20000
#define GIA_VE_NGUOI_LON 40000

typedef struct {
    char hoten[MAX];
    char SDT[MAX];
    int soVeNguoiLon;
    int soVeTreEm;
    char tenphim[MAX];
    char phongchieu[MAX];
    char xuatchieu[MAX];
    int tienPhaiTra;
} KhachHang;

void chuanHoa(char str[]) {
    int i, j;
    int len = strlen(str);

    i = 0;
    while (i < len && str[i] == ' ') {
        i++;
    }


    j = 0;
    while (i < len) {
        if (str[i] != ' ' || (j > 0 && str[j - 1] != ' ')) {
            str[j++] = str[i];
        }
        i++;
    }

    
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    str[j] = '\0'; 
}


void docDanhSachKhachHang(KhachHang dskh[], int* n) 
{
    char filename[] = "DATA/danh_sach_khach_hang.txt";
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file %s.\n", filename);
        return;
    }

    *n = 0;
    while (fscanf_s(file, "%[^\n]\n%[^\n]\n%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%d\n",
        dskh[*n].hoten, sizeof(dskh[*n].hoten),
        dskh[*n].SDT, sizeof(dskh[*n].SDT),
        &dskh[*n].soVeNguoiLon, &dskh[*n].soVeTreEm,
        dskh[*n].tenphim, sizeof(dskh[*n].tenphim),
        dskh[*n].phongchieu, sizeof(dskh[*n].phongchieu),
        dskh[*n].xuatchieu, sizeof(dskh[*n].xuatchieu),
        &dskh[*n].tienPhaiTra) != EOF) {
        (*n)++;
    }

    printf("Da doc file %s thanh cong!\n", filename);
    fclose(file);
}
void xuatDanhSachKhachHang(KhachHang dskh[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ho Ten: %s\n", dskh[i].hoten);
        printf("So Dien Thoai: %s\n", dskh[i].SDT);
        printf("So Ve Nguoi Lon: %d\n", dskh[i].soVeNguoiLon);
        printf("So Ve Tre Em: %d\n", dskh[i].soVeTreEm);
        printf("Ten Phim: %s\n", dskh[i].tenphim);
        printf("Phong Chieu: %s\n", dskh[i].phongchieu);
        printf("Xuat Chieu: %s\n", dskh[i].xuatchieu);
        printf("Tien Phai Tra: %d\n\n", dskh[i].tienPhaiTra);
    }
}

void tinhTienPhaiTra(KhachHang dskh[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        dskh[i].tienPhaiTra = dskh[i].soVeNguoiLon * GIA_VE_NGUOI_LON +
            dskh[i].soVeTreEm * GIA_VE_TRE_EM;
    }
}

int tinhTongDoanhThu(KhachHang dskh[], int n) 
{
    int tongDoanhThu = 0;
    for (int i = 0; i < n; i++)
    {
        tongDoanhThu += dskh[i].tienPhaiTra;
    }
    return tongDoanhThu;
}

void tinhTongDoanhThuTheoPhim(KhachHang dskh[], int n) 
{
    char tenPhim[MAX];
    printf("Nhap ten phim: ");
    fgets(tenPhim, MAX, stdin);
    tenPhim[strcspn(tenPhim, "\n")] = '\0';
    chuanHoa(tenPhim);

    int tongDoanhThu = 0;
    for (int i = 0; i < n; i++) {
        char tenPhimDskh[MAX];
        strcpy_s(tenPhimDskh, dskh[i].tenphim);
        chuanHoa(tenPhimDskh);

        if (strcmp(tenPhimDskh, tenPhim) == 0) {
            tongDoanhThu += dskh[i].tienPhaiTra;
        }
    }

    printf("Tong doanh thu cua phim '%s': %d\n", tenPhim, tongDoanhThu);
}

void xuatThongTinTheoPhongChieuVaXuatChieu(KhachHang dskh[], int n, const char* phongChieu, const char* xuatChieu) 
{
    for (int i = 0; i < n; i++) 
    {
        if (strcmp(dskh[i].phongchieu, phongChieu) == 0 && strcmp(dskh[i].xuatchieu, xuatChieu) == 0)
        {
            printf("Ho Ten: %s\n", dskh[i].hoten);
            printf("So Dien Thoai: %s\n", dskh[i].SDT);
            printf("So Ve Nguoi Lon: %d\n", dskh[i].soVeNguoiLon);
            printf("So Ve Tre Em: %d\n", dskh[i].soVeTreEm);
            printf("Ten Phim: %s\n", dskh[i].tenphim);
            printf("Phong Chieu: %s\n", dskh[i].phongchieu);
            printf("Xuat Chieu: %s\n", dskh[i].xuatchieu);
            printf("Tien Phai Tra: %d\n\n", dskh[i].tienPhaiTra);
        }
    }
}

void swap(KhachHang* a, KhachHang* b) 
{
    KhachHang temp = *a;
    *a = *b;
    *b = temp;
}

void sapXepTheoTienPhaiTra(KhachHang dskh[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (dskh[i].tienPhaiTra > dskh[j].tienPhaiTra) 
            {
                swap(&dskh[i], &dskh[j]);
            }
        }
    }
}

void sapXepTheoTen(KhachHang dskh[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (strcmp(dskh[i].hoten, dskh[j].hoten) > 0) 
            {
                swap(&dskh[i], &dskh[j]);
            }
        }
    }
}

int binarySearchByName(KhachHang dskh[], int n, const char* hoTen) 
{
    int left = 0, right = n - 1;
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        int cmp = strcmp(dskh[mid].hoten, hoTen);
        if (cmp == 0) 
        {
            return mid;
        }
        else if (cmp < 0)
        {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

void menu()
{
    int choice;
    int n = 0;
    KhachHang* dskh = (KhachHang*)malloc(MAX * sizeof(KhachHang));
    char filename[]= "DATA/danh_sach_khach_hang.txt";
    printf("\n---------------Menu-------------\n");
    printf("1. Doc danh sach khach hang tu file\n");
    printf("2. Xuat danh sach khach hang\n");
    printf("3. Tinh tien phai tra cho moi khach hang\n");
    printf("4. Tinh tong doanh thu cua rap phim\n");
    printf("5. Tinh tong doanh thu cua tung phim\n");
    printf("6. Xuat thong tin khach hang theo phong chieu va xuat chieu\n");
    printf("7. Sap xep danh sach theo so tien phai tra tang dan\n");
    printf("8. Sap xep danh sach theo ten tang dan\n");
    printf("9. Tim khach hang theo ten (Binary Search)\n");
    printf("0. Thoat\n");
    do
    {
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            docDanhSachKhachHang(dskh, &n);
            break;
        case 2:
            xuatDanhSachKhachHang(dskh, n);
            break;
        case 3:
            tinhTienPhaiTra(dskh, n);
            xuatDanhSachKhachHang(dskh, n);
            break;
        case 4:
            printf("Tong doanh thu cua rap phim: %d\n", tinhTongDoanhThu(dskh, n));
            break;
        case 5:
            tinhTongDoanhThuTheoPhim(dskh, n);
            break;
        case 6: {
            char phongChieu[MAX];
            char xuatChieu[MAX];
            printf("Nhap phong chieu: ");
            fgets(phongChieu, MAX, stdin);
            phongChieu[strcspn(phongChieu, "\n")] = '\0';

            printf("Nhap xuat chieu: ");
            fgets(xuatChieu, MAX, stdin);
            xuatChieu[strcspn(xuatChieu, "\n")] = '\0';

            xuatThongTinTheoPhongChieuVaXuatChieu(dskh, n, phongChieu, xuatChieu);
            break;
        }
        case 7:
            sapXepTheoTienPhaiTra(dskh, n);
            xuatDanhSachKhachHang(dskh, n);
            break;
        case 8:
            sapXepTheoTen(dskh, n);
            xuatDanhSachKhachHang(dskh, n);
            break;
        case 9: {
            char hoTen[MAX];
            printf("Nhap ho ten khach hang can tim: ");
            fgets(hoTen, MAX, stdin);
            hoTen[strcspn(hoTen, "\n")] = '\0';

            sapXepTheoTen(dskh, n);
            int index = binarySearchByName(dskh, n, hoTen);
            if (index != -1) {
                printf("Tim thay khach hang '%s' tai vi tri %d\n", hoTen, index);
            }
            else {
                printf("Khong tim thay khach hang '%s'\n", hoTen);
            }
            break;
        }
        case 0:
            printf("Thoat chuong trinh\n");
            exit(0);
        default:
            printf("Khong hop le.Moi Nhap lai");
            break;
        }

    } while (choice!=0);
}
int main()
{
    menu();
    return 0;
}