#include <stdio.h>
#include <string.h>
#define MAX 100

struct Room {
    char roomId[5];
    int type;
    double price;
    int status;
};
struct Booking {
    char bookId[20];
    char roomId[5];
    char customerName[50];
    int days;
    double totalCost;
};
struct Room rooms[MAX] = {
    {"101", 1, 500, 0},
    {"102", 2, 700, 0},
    {"103", 1, 600, 0}
};
int roomCount = 3;

int isRoomIdExists(char roomId[5]) {
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].roomId, roomId) == 0) {
            return i;
        }
    }
    return -1;
}
int isRoomIdExists(char roomId[5]);
void addRoom();
void updateRoom();
void maintenanceRoom();
void displayRoom();
void searchRoom();
void arrangeListRoom();
void checkIn();
void rentalHistory(); 

    do {
        printf("Nhap so phong (3-4 ky tu): ");
        fgets(tempRoomId, sizeof(tempRoomId), stdin);
        tempRoomId[strcspn(tempRoomId, "\n")] = '\0';

        if (strlen(tempRoomId) == 0) {
            printf("Loi: So phong khong duoc de trong!\n");
        } else if (strlen(tempRoomId) < 3 || strlen(tempRoomId) > 4) {
            printf("Loi: So phong phai tu 3 den 4 ky tu!\n");
        } else if (isRoomIdExists(tempRoomId) != -1) {
            printf("Loi: Phong %s da ton tai!\n", tempRoomId);
        } else {
            strcpy(rooms[roomCount].roomId, tempRoomId);
            break;
        }
    } while (1);

    do {
        printf("Nhap loai phong (1: Don, 2: Doi): ");
        if (typeNew != 1 && typeNew != 2) {
            printf("Loi: Loai phong chi duoc chon 1 hoac 2!\n");
        } else {
            rooms[roomCount].type = typeNew;
            break;
        }
    } while (1);

    do {
        printf("Nhap gia phong moi dem: ");
        if (priceNew <= 0) {
            printf("Loi: Gia phong phai lon hon 0!\n");
        } else {
            rooms[roomCount].price = priceNew;
            break;
        }
    } while (1);

    rooms[roomCount].status = 0;
    printf("Them phong thanh cong! Phong %s da duoc tao.\n", rooms[roomCount].roomId);
    roomCount++;
}
void updateRoom() {
    char roomId[10];
    int typeNew;
    double priceNew;
    int idx;

    do {
        printf("Nhap so phong can cap nhat: ");
        fgets(roomId, sizeof(roomId), stdin);
        roomId[strcspn(roomId, "\n")] = '\0';

        if (strlen(roomId) == 0) {
            printf("Loi: So phong khong duoc de trong!\n");
            continue;
        }
        idx = isRoomIdExists(roomId);
        if (idx == -1) {
            printf("Loi: Khong tim thay phong %s!\n", roomId);
        } else {
            break;
        }
    } while (1);

    printf("Thong tin hien tai:\n");
    printf("So phong: %s\n", rooms[idx].roomId);
    printf("Loai phong: %d\n", rooms[idx].type);
    printf("Gia phong: %.2f\n", rooms[idx].price);
    printf("Trang thai: %d\n", rooms[idx].status);

    do {
        printf("Nhap loai phong moi (1: Don, 2: Doi): ");
        if (typeNew != 1 && typeNew != 2) {
            printf("Loi: Loai phong chi duoc chon 1 hoac 2!\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Nhap gia phong moi: ");
        if (priceNew <= 0) {
            printf("Loi: Gia phong phai lon hon 0!\n");
        } else {
            break;
        }
    } while (1);

    rooms[idx].type = typeNew;
    rooms[idx].price = priceNew;
    printf("Cap nhat thong tin phong %s thanh cong!\n", roomId);
}
int main() {
    int choice;

    do {
        printf("+----------------------MENU-------------------+\n");
        printf("|1. Them phong moi                            |\n");
        printf("|2. Cap nhat phong                            |\n");
        printf("|3. Bao tri phong                             |\n");
        printf("|4. Hien thi danh sach                        |\n");
        printf("|5. Tim kiem                                  |\n");
        printf("|6. Sap xep danh sach phong                   |\n");
        printf("|7. Check-in                                  |\n");
        printf("|8. Lich su thue                              |\n");
        printf("|9. Thoat                                     |\n");
        printf("+---------------------------------------------+\n");

        printf("Moi ban nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addRoom();
                break;
            case 2:
                updateRoom();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                printf("Dang thoat...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

    } while (choice != 9);

    return 0;
}



