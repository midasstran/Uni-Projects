#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct{
	char ma[10];
	char ten[100];
	char tacgia[50];
	int namXB;
	float gia;
} Sach;
void xoadem(){
	int c;
	while((c=getchar())!='\n' && c!=EOF );
}
void nhap1Sach(Sach &ds){
	xoadem();
	printf("----------");
	printf("\nNhap ma: ");
	fgets(ds.ma,sizeof(ds.ma),stdin);
	ds.ma[strcspn(ds.ma,"\n")]='\0';
	printf("\nNhap ten: ");
	fgets(ds.ten,sizeof(ds.ten),stdin);
	ds.ten[strcspn(ds.ten,"\n")]='\0';
	printf("\nNhap tac gia: ");
	fgets(ds.tacgia,sizeof(ds.tacgia),stdin);
	ds.tacgia[strcspn(ds.tacgia,"\n")]='\0';
	printf("\nNhap nam xuat ban: ");
	scanf("%d",&ds.namXB);
	printf("\nNhap gia: ");
	scanf("%f",&ds.gia);
}
void nhapSach(Sach ds[],int n){
	for (int i=0;i<n;i++){
		nhap1Sach(ds[i]);
	}
}
void xuat1Sach(Sach &ds){
	printf("\nMa : %s	Ten: %s	Tac Gia: %s	Nam XB: %d	Gia: %.2f",ds.ma,ds.ten,ds.tacgia,ds.namXB,ds.gia);
}
void xuatSach(Sach ds[],int n){
	for (int i=0;i<n;i++){
		printf("\n---Sach %d---",i+1);
		xuat1Sach(ds[i]);
	}
}
void layHoTacGia(char hoten[],char ho[]){
	char temp[100];
	strcpy(temp,hoten);
	char *token=strtok(temp, " ");
	if (token!=NULL){
		strcpy(ho,temp);
//		printf("Ho sau khi tach: %s",ho);
	}
	else{
		ho[0]='\0';
	} 
}
void laytrongds(Sach ds[],int n){
	char ho[50];
	printf("\n-----");
	for (int i=0;i<n;i++){
		layHoTacGia(ds[i].tacgia,ho);
		printf("\nSach : %s		Ten Tac Gia:%s		Ho Tac Gia:%s",ds[i].ten,ds[i].tacgia,ho);
	}
}
void timSach(Sach ds[],int n,char key[]){
	printf("\nNhap ten sach hoac tac gia muon tim:");
	xoadem();
	fgets(key,100,stdin);
	key[strcspn(key,"\n")]='\0';
	for (int i=0;i<n;i++){
		if (strstr(key,ds[i].ten)!=NULL){
			xuat1Sach(ds[i]);
		}
		else if (strstr(key,ds[i].tacgia)!=NULL){
			xuat1Sach(ds[i]);
		}
	}
}
void timSachTheoNam(Sach ds[],int n,int nam){
	printf("\nNhap nam muon tim: ");
	scanf("%d",&nam);
	int found=0;
	for (int i=0;i<n;i++){
		if (nam<ds[i].namXB){
			found=1;
			if (found==1){
			xuat1Sach(ds[i]);}
		}
	}
	if (found!=1){
		printf("\nKhong tim thay");
	}
}
Sach timSachGiaMax(Sach ds[],int n){
	int max_val=0;
	for (int i=1;i<n;i++){
		if (ds[i].gia>ds[max_val].gia){
			max_val=i;
		}
	}
	printf("\nSach %d dat nhat", max_val + 1);
	return ds[max_val];
}
int xoaSach(Sach ds[],int *n,char ma[]){
	int found=-1;
	printf("\nNhap ma sach muon xoa: ");
	xoadem();
	fgets(ma,sizeof(10),stdin);
	ma[strcspn(ma,"\n")]='\0';
	for (int i=0;i<*n;i++){
		if (strcmp(ds[i].ma,ma)==0){
			found=i;
			break;
		}
	}
	if (found!=-1){
	for (int i=found;i<(*n)-1;i++){
		ds[i]=ds[i+1];
		printf("\nXoa thanh cong");
	}
	(*n)--;
	return 1;}
	return 0;
}

int main(){
	int n=0;
	char key[100];
	char maxoa[10];
	Sach *ds=NULL;
	int nam;
	int chon;
//	printf("Nhap so luong sach: ");
//	scanf("%d",&n);
//	ds=(Sach*)malloc(n*sizeof(Sach));
//	nhapSach(ds,n);
//	xuatSach(ds,n);
//	laytrongds(ds,n);
//	timSach(ds,n,key);
//	timSachTheoNam(ds,n,nam);
//  	timSachGiaMax(ds,n);
//	xoaSach(ds,&n,maxoa);
	do{
		printf("\n==========Quan ly sach==========");
		printf("\n1.Nhap danh sach");
		printf("\n2.Xuat danh sach");
		printf("\n3.Tach ho tac gia");
		printf("\n4.Tim sach theo ten sach hoac tac gia");
		printf("\n5.Tim sach theo nam");
		printf("\n6.Tim sach gia cao nhat");
		printf("\n7.Xoa sach theo ma");
		printf("\n0.Thoat chuong trinh");
		printf("\n================================");
		printf("\nNhap lua chon: ");
		scanf("%d",&chon);
		
		switch(chon){
			case 1:
				printf("\nNhap so luong sach: ");
				scanf("%d",&n);
				ds=(Sach*)malloc(n*sizeof(Sach));
				nhapSach(ds,n);
				break;
			case 2:
				if (n>0) xuatSach(ds,n);
				else printf("\nDanh sach trong");
				break;
			case 3:
				if (n>0) laytrongds(ds,n);
				else printf("\nDanh sach trong");
				break;
			case 4:
				if (n>0) timSach(ds,n,key);
				else printf("\nDanh sach trong");
				break;
			case 5:
				if (n>0) timSachTheoNam(ds,n,nam);
				else printf("\nKhong tim thay");
				break;
			case 6:
				if (n>0) timSachGiaMax(ds,n);
				else printf("\nDanh sach trong");
				break;
			case 7:
				if (n>0) xoaSach(ds,&n,maxoa);
				else printf("\nDanh sach trong");
				break;
			case 0:
				printf("\n...Dang thoat");
				break;
			default:
				printf("\nLua chon khong hop le, vui long thu lai");
		}
		
	}while(chon!=0);
	if (ds!=NULL) free(ds);
	
	return 0;
}
