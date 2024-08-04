#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void XuatKyTu(char* st)
{
    printf("Cac ky tu trong chuoi: \n");
    while (*st != '\0') 
    {
        printf("%c ", *st);
        st++;
    }
    printf("\n");
}


void KyTuHoa(char* st)
{
    while (*st != '\0') 
    {
        *st = toupper((unsigned char)*st);
        st++;
    }
}


void ChuoiKyTuHoa(char* st) 
{
    int KyTuKeTiep = 1; // dat co danh dau ky tu dau
    while (*st != '\0') 
    {
        if (isspace((unsigned char)*st)) 
        {
            KyTuKeTiep = 1; // dat co khi gap dau cach
        }
        else if (KyTuKeTiep) 
        {
            *st = toupper((unsigned char)*st);
            KyTuKeTiep = 0;
        }
        else
        {
            *st = tolower((unsigned char)*st);
        }
        st++;
    }
}


void menu() {
    char str[100];
    int choice;
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; 
    }
    printf("\n--------- MENU ----------\n");
    printf("1. Xuat gia tri tung ky tu cua chuoi\n");
    printf("2. Chuyen toan bo chuoi ve chu hoa\n");
    printf("3. Viet hoa ky tu dau moi tu\n");
    printf("0. Thoat\n");

    do {
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);
        getchar(); 

        switch (choice) {
        case 1:
            XuatKyTu(str);
            break;
        case 2:
            KyTuHoa(str);
            printf("Chuoi sau khi chuyen ve chu hoa: %s\n", str);
            break;
        case 3:
            ChuoiKyTuHoa(str);
            printf("Chuoi sau khi viet hoa ky tu dau moi tu: %s\n", str);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            exit(0);
        default:
            printf("Khong hop le. Chon lai\n");
            break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
