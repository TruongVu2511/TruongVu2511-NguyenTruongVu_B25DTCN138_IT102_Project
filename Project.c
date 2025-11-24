#include <stdio.h>
#include <string.h>
#define MAX 100

struct Room{
	char roomId[5];
	int type;
	double price;
	int status;
};
struct Booking{
	char bookId[20];
	char roomId[5];
	char customerName[50];
	int days;
	double totalCost;
};
struct Room rooms[MAX];
int roomCount = 0; 

int isRoomIdExists(char roomId[5]) {
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].roomId, roomId) == 0) {
            return i; 
        }
    }
    return -1; 
}
void addRoom() {
    struct Room r;
    printf("Nhap so phong: ");
    scanf("%4s", r.roomId);

    if (strlen(r.roomId) < 3 || strlen(r.roomId) > 4) {
        printf("Loi: so phong phai co 3-4 ki tu\n");
        return;
    }
    if (isRoomIdExists(r.roomId) != -1) {
        printf("Loi: so phong da ton tai\n");
        return;
    }
    printf("Nhap loai phong: ");
    scanf("%d", &r.type);
    if (r.type != 1 && r.type != 2) {
        printf("Loi: Loai phong chi duoc chon 1 hoac 2\n");
        return;
    }
    printf("Gia phong moi dem: ");
    scanf("%lf", &r.price);
    if (r.price <= 0) {
        printf("Loi: Gia tien phai lon hon 0\n");
        return;
    }
    r.status = 0; 
    rooms[roomCount] = r;
    roomCount++; 
    printf("Them phong thanh cong! Phong da duoc tao\n");
}
void updateRoom() {
    char roomId[5];
    int typeNew;
    double priceNew;

    printf("Nhap so phong can cap nhat: ");
    scanf("%4s", roomId);
    int idx = isRoomIdExists(roomId);
    if (idx == -1) {
        printf("Loi: Khong tim thay phong %s!\n", roomId);
        return;
    }
    printf("Thong tin hien tai:\n");
    printf("So phong: %s\n", rooms[idx].roomId);
    printf("Loai phong: %d\n", rooms[idx].type);
    printf("Gia phong: %.2f\n", rooms[idx].price);
    printf("Trang thai: %d\n", rooms[idx].status);

    printf("Nhap loai phong moi: ");
    scanf("%d", &typeNew);
    if (typeNew != 1 && typeNew != 2) {
        printf("Loi: Loai phong chi duoc chon 1 hoac 2\n");
        return;
    }
    printf("Nhap gia phong moi: ");
    scanf("%lf", &priceNew);
    if (priceNew <= 0) {
        printf("Loi: Gia phong phai lon hon 0\n");
        return;
    }
    rooms[idx].type = typeNew;
    rooms[idx].price = priceNew;

    printf("Cap nhat thong tin phong thanh cong!\n");
}
int main(){
	int choice;
	struct Room r1 = {"101", 1, 500, 0}; 
    struct Room r2 = {"102", 2, 700, 0}; 
    struct Room r3 = {"103", 1, 600, 0}; 

    rooms[roomCount++] = r1;
    rooms[roomCount++] = r2;
    rooms[roomCount++] = r3;
	do{
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
		
		printf("Moi ban nhap lua chon :");
		scanf("%d",&choice);
		
		switch(choice){
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
				printf("Dang thoat");
				break;
			default:
				printf("Lua chon khong hop le . Vui long chon lai\n");
		}
		
	}while(choice!=9);
	
	return 0;
}
