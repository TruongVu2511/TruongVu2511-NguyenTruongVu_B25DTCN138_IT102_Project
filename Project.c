#include <stdio.h>
#include <string.h>
#define MAX 100

struct Room {
    char roomId[5];
    int type;
    double price;
    int status;
};
struct Date {
    int day;
    int month;
    int year;
};
struct Booking {
    char bookId[20];
    char roomId[5];
    char customerName[50];
    struct Date receivedDateRoom;
    int days;
    double totalCost;
};
struct Room rooms[MAX] = {
    {"101", 1, 500, 0},
    {"102", 2, 700, 0},
    {"103", 1, 600, 1},
    {"104", 2, 800, 2},
    {"105", 1, 550, 0},
    {"106", 2, 750, 1},
    {"107", 1, 650, 2},
    {"108", 2, 900, 0},
    {"109", 1, 580, 1},
    {"110", 2, 720, 0},
    {"111", 1, 610, 2},
    {"112", 2, 820, 1},
    {"113", 1, 560, 1},
    {"114", 2, 770, 2},
    {"115", 1, 630, 1},
    {"116", 2, 880, 0},
    {"117", 1, 590, 2},
    {"118", 2, 740, 1},
    {"119", 1, 620, 1},
    {"120", 2, 860, 2},
    {"121", 1, 570, 1},
    {"122", 2, 780, 0},
    {"123", 1, 640, 2},
    {"124", 2, 910, 1},
    {"125", 1, 600, 1},
    {"126", 2, 730, 2},
    {"127", 1, 660, 1},
    {"128", 2, 890, 0},
    {"129", 1, 610, 2},
    {"130", 2, 950, 1}
};
struct Booking bookings[MAX]={
    {"001", "103", "Nguyen Van A", {25, 11, 2025}, 3, 600 * 3},
    {"002", "104", "Tran Thi B",   {26, 11, 2025}, 2, 800 * 2},
    {"003", "106", "Le Van C",     {27, 11, 2025}, 4, 750 * 4},
    {"004", "107", "Pham Thi D",   {28, 11, 2025}, 1, 650 * 1}
};

int roomCount = 30;
int bookingCount = 4;

int isValidDateFormat(char date[]);
int isRoomIdExists(char roomId[5]);
void addRoom();
void updateRoom();
void maintenanceRoom();
void displayRoom();
void searchRoom();
void arrangeListRoom();
void checkIn();
void rentalHistory(); 

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
            	maintenanceRoom();
                break;
            case 4:
            	displayRoom();
                break;
            case 5:
            	searchRoom(); 
                break;
            case 6:
            	arrangeListRoom();
                break;
            case 7:
            	checkIn();
                break;
            case 8:
            	rentalHistory();
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

int isRoomIdExists(char roomId[5]) {
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].roomId, roomId) == 0) {
            return i;
        }
    }
    return -1;
}

void addRoom() {
    int typeNew;
    double priceNew;
    char tempRoomId[10];

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
        if (scanf("%d", &typeNew) != 1) {
            printf("Loi: Khong duoc de trong!\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (typeNew != 1 && typeNew != 2) {
            printf("Loi: Loai phong chi duoc chon 1 hoac 2!\n");
        } else {
            rooms[roomCount].type = typeNew;
            break;
        }
    } while (1);

    do {
        printf("Nhap gia phong moi dem: ");
        if (scanf("%lf", &priceNew) != 1) {
            printf("Loi: Khong duoc de trong!\n");
            while (getchar() != '\n');
            continue;
        }
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
        if (scanf("%d", &typeNew) != 1) {
            printf("Loi: Khong duoc de trong!\n");
            while (getchar() != '\n');
            continue;
        }
        if (typeNew != 1 && typeNew != 2) {
            printf("Loi: Loai phong chi duoc chon 1 hoac 2!\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Nhap gia phong moi: ");
        if (scanf("%lf", &priceNew) != 1) {
            printf("Loi: Khong duoc de trong!\n");
            while (getchar() != '\n');
            continue;
        }
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

void maintenanceRoom() {
    char roomId[5];
    int idx;

    do {
        printf("Nhap so phong can bao tri: ");
        fgets(roomId, sizeof(roomId), stdin);
        roomId[strcspn(roomId, "\n")] = '\0';

        if (strlen(roomId) == 0) {
            printf("Loi: So phong khong duoc de trong\n");
            continue;
        }

        idx = isRoomIdExists(roomId);
        if (idx == -1) {
            printf("Loi: Khong tim thay phong\n");
            return;
        }

        if (rooms[idx].status == 1) {
            printf("Loi: Phong %s dang co khach, khong the dua vao bao tri\n", roomId);
            return;
        }

        if (rooms[idx].status == 2) {
            printf("Phong %s dang trong trang thai bao tri roi\n", roomId);
            return;
        }

        rooms[idx].status = 2;
        printf("Da dua phong %s vao trang thai bao tri thanh cong\n", roomId);
        return;

    } while (1);
}

void displayRoom() {
    int page_number;
    int page_size = 10;

    if (roomCount == 0) {
        printf("Danh sach phong hien tai trong! Vui long them phong truoc.\n");
        return;
    }

    int total_pages = (roomCount % page_size == 0) ? roomCount / page_size : roomCount / page_size + 1;
    char ch = 'y';

    do {
        
        printf("Moi ban chon so trang can xem (1-%d): ", total_pages);
        if (scanf("%d", &page_number) != 1 || page_number < 1 || page_number > total_pages) {
            printf("Loi: So trang khong hop le!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        int start = (page_number - 1) * page_size;
        int end = start + page_size;

        printf("\nTrang %d/%d:\n", page_number, total_pages);
        printf("| STT | So phong | Loai  | Gia tien | Trang thai  |\n");

        for (int i = start; i < end && i < roomCount; i++) {
            printf("| %-3d | %-8s | %-5d | %-8.0f | ", 
                   i + 1, rooms[i].roomId, rooms[i].type, rooms[i].price);

            switch (rooms[i].status) {
                case 0:  printf("Trong"); break;
                case 1:  printf("Co khach"); break;
                case 2:  printf("Bao tri"); break;
                default: printf("Khong ro"); break;
            }
            printf("\n");
        }

        printf("Bang danh sach phong co phan trang 10 dong/trang, hien thi ro trang thai bang chu.\n");

        printf("Ban co muon xem tiep khong? (y/n): ");
        ch = getchar();
        while (getchar() != '\n');

    } while (ch == 'y' || ch == 'Y');
}

void searchRoom(){
    int type;
    int found = 0;

    printf("Nhap loai phong can tim (1 = Don, 2 = Doi): ");
    if (scanf("%d", &type) != 1 || (type != 1 && type != 2)) {
        while (getchar() != '\n'); 
        printf("Loi: Vui long chon 1 (Don) hoac 2 (Doi)!\n");
        return;
    }
while (getchar() != '\n');

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].type == type && rooms[i].status == 0) {
            found++;
        }
    }

    if (found == 0) {
        printf("Hien tai khong co phong trong loai %s!\n", (type == 1) ? "Don" : "Doi");
        return;
    }

    printf("\nDanh sach cac phong TRONG loai %s:\n", (type == 1) ? "Don" : "Doi");
    printf("| STT | So phong | Loai | Gia tien | Trang thai |\n");

    int stt = 1;
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].type == type && rooms[i].status == 0) {
            printf("| %-3d | %-8s | %-4d | %-8.0f | Trong |\n",
                   stt++, rooms[i].roomId, rooms[i].type, rooms[i].price);
        }
    }
}
void arrangeListRoom() {
    if (roomCount == 0) {
        printf("Danh sach phong trong, khong can sap xep!\n");
        return;
    }
    for (int i = 0; i < roomCount - 1; i++) {
        for (int j = 0; j < roomCount - i - 1; j++) {
            if (rooms[j].price < rooms[j + 1].price) {
                struct Room temp = rooms[j];
                rooms[j] = rooms[j + 1];
                rooms[j + 1] = temp;
            }
        }
    }

    printf("Da sap xep danh sach phong theo gia giam dan thanh cong!\n");
    
    displayRoom(); 
}
int isValidDate(int day, int month, int year) {
    if (year < 1900 || year > 2100){
	 return 0;
    }
    if (month < 1 || month > 12){
     return 0;
    }
    int maxDay;

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;
        case 2:
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                maxDay = 29;
            } else {
                maxDay = 28;
            }
            break;
    }
    return (day >= 1 && day <= maxDay);
}

void checkIn() {
    char roomId[5];
    char customerName[50];
    int days, idx;
    int day, month, year; 

    do {
        printf("Nhap ma phong muon dat: ");
        fgets(roomId, sizeof(roomId), stdin);
        roomId[strcspn(roomId, "\n")] = '\0';

        idx = -1;
        for (int i = 0; i < roomCount; i++) {
            if (strcmp(rooms[i].roomId, roomId) == 0) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            printf("Khong tim thay phong co ma %s! Vui long nhap lai.\n", roomId);
        } else if (rooms[idx].status != 0) {
            printf("Phong %s khong trong, khong the check-in!\n", roomId);
            idx = -1;
        }
    } while (idx == -1);
do {
    printf("Nhap ten khach hang: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = '\0'; 

    if (strlen(customerName) == 0) {
        printf("Loi: Ten khach hang khong duoc de trong!\n");
        continue;
    }
    int flag = 1;
    for (int i = 0; i < strlen(customerName); i++) {
        if ((customerName[i] >= 'A' && customerName[i] <= 'Z') ||
            (customerName[i] >= 'a' && customerName[i] <= 'z') ||
            (customerName[i] == ' ')) {
        } else {
            valid = 0; 
            break;
        }
    }

    if (valid == 0) {
        printf("Loi: Ten khach hang chi duoc chua chu cai va khoang trang!\n");
    } else {
        break;
    }
} while (1);


    do {
        printf("Nhap so ngay thue: ");
        if (scanf("%d", &days) != 1 || days <= 0) {
            printf("So ngay thue khong hop le! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
            days = -1;
        }
    } while (days <= 0);
    while (getchar() != '\n'); 

    do {
        printf("Nhap ngay nhan phong (DD/MM/YYYY): ");
        if (scanf("%d/%d/%d", &day, &month, &year) != 3 || !isValidDate(day, month, year)) {
            printf("Loi: Ngay khong hop le! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    } while (1);
    while (getchar() != '\n');
    
    rooms[idx].status = 1;

    snprintf(bookings[bookingCount].bookId,sizeof(bookings[bookingCount].bookId),"%d", bookingCount + 1);
    strcpy(bookings[bookingCount].roomId, roomId);
    strcpy(bookings[bookingCount].customerName, customerName);
    bookings[bookingCount].receivedDateRoom.day   = day;
    bookings[bookingCount].receivedDateRoom.month = month;
    bookings[bookingCount].receivedDateRoom.year  = year;
    bookings[bookingCount].days      = days;
    bookings[bookingCount].totalCost = rooms[idx].price * days;

    bookingCount++;

    printf("\n===== HOA DON =====\n");
    printf("Ma dat phong : %s\n", bookings[bookingCount - 1].bookId);
    printf("Phong        : %s\n", bookings[bookingCount - 1].roomId);
    printf("Khach hang   : %s\n", bookings[bookingCount - 1].customerName);
    printf("Ngay nhan    : %02d/%02d/%04d\n",
           bookings[bookingCount - 1].receivedDateRoom.day,
           bookings[bookingCount - 1].receivedDateRoom.month,
           bookings[bookingCount - 1].receivedDateRoom.year);
    printf("So ngay thue : %d\n", bookings[bookingCount - 1].days);
    printf("Tong tien    : %.0f VND\n", bookings[bookingCount - 1].totalCost);
    printf("===================\n");
}
void rentalHistory() {
    char roomId[5];
    int flagRoom = 0;
    int flagHistory = 0;

    do {
        printf("Nhap ma phong can xem lich su thue: ");
        scanf("%4s", roomId);
        while (getchar() != '\n');

        for (int i = 0; i < roomCount; i++) {
            if (strcmp(rooms[i].roomId, roomId) == 0) {
                flagRoom = 1;
                break;
            }
        }
        if (flagRoom == 0) {
            printf("Loi: Khong tim thay phong %s! Vui long nhap lai.\n", roomId);
        } else {
            break; 
        }

    } while (1);
    printf("\n===== LICH SU THUE PHONG %s =====\n", roomId);
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].roomId, roomId) == 0) {
            flagHistory = 1;
            printf("Khach hang   : %s\n", bookings[i].customerName);
            printf("Ngay nhan   : %02d/%02d/%04d\n",
                   bookings[i].receivedDateRoom.day,
                   bookings[i].receivedDateRoom.month,
                   bookings[i].receivedDateRoom.year);
            printf("So ngay thue : %d\n", bookings[i].days);
            printf("Tong tien    : %.0f VND\n", bookings[i].totalCost);
            printf("-----------------------------\n");
        }
    }
    if (flagHistory == 0) {
        printf("Phong %s chua tung co khach thue!\n", roomId);
    }
}



