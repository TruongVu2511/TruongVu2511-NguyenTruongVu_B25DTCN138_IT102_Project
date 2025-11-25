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
    {"101", 1, 500, 1},
    {"102", 2, 700, 0},
    {"103", 1, 600, 1}
};
int roomCount = 3;

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

void maintenanceRoom(){
	char roomId[5];
	int idx;
	
	do{
		printf("Nhap so phong can bao tri :");
		fgets(roomId,5,stdin);
		roomId[strcspn(roomId,"\n")] = '\0';
		
		if(strlen(roomId)==0){
			printf("Loi : So phong khong duoc de trong\n");
			continue;
		}
		idx = isRoomIdExists(roomId);
		if(idx==-1){
			printf("Loi : khong tim thay phong\n");
			return;
		}
		if(rooms[idx].status==1){
			printf("Loi : phong %s dang co khach , khong the dua vao bao tri\n",roomId);
			return;
		}
		
		rooms[idx].status=2;
		printf("Da dua phong %s vao trang thai bao tri thanh cong\n ",roomId);
		return;
		
	}while(1);
}

void showRoomsPaginate() {
    int page_number = 1;
    int page_size = 10;

    if (roomCount == 0) {
        printf("Danh sach phong hien tai trong! Vui long them phong truoc.\n");
        return;
    }

    int total_pages = (roomCount % page_size == 0) ? roomCount / page_size : roomCount / page_size + 1;

    while (1) {
        printf("Moi ban chon so trang can xem (1-%d): ", total_pages);
        if (scanf("%d", &page_number) != 1 || page_number < 1 || page_number > total_pages) {
            printf("Loi: So trang khong hop le!\n");
            while (getchar() != '\n');
            continue;
        }

        int start = (page_number - 1) * page_size;
        int end = start + page_size;

        printf("\nTrang %d/%d:\n\n", page_number, total_pages);
        printf("+-----+----------+-------+----------+-------------+\n");
        printf("| STT | So phong | Loai  | Gia tien | Trang thai  |\n");
        printf("+-----+----------+-------+----------+-------------+\n");

        for (int i = start; i < end && i < roomCount; i++) {
            char *statusText;
            switch (rooms[i].status) {
                case 0: statusText = "Trong"; break;
                case 1: statusText = "Co khach"; break;
                case 2: statusText = "Bao tri"; break;
                default: statusText = "Khong ro"; break;
            }

            printf("| %-3d | %-8s | %-5d | %-8.0f | %-11s |\n",
                   i + 1, rooms[i].roomId, rooms[i].type, rooms[i].price, statusText);
        }

        printf("+-----+----------+-------+----------+-------------+\n");

        while (getchar() != '\n'); 
        printf("Ban co muon thoat hay khong? (y/n): ");
        char ch = getchar();
        if (ch == 'y' || ch == 'Y') {
            break;
        }
    }
}



