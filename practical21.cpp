#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct{
	int id;
	char patient[50];
	char doctor[50];
	char surgery[50];
	float cost;
}ds;
void ReadFile(char *fname,int *pn, ds a[],int nmax){
	(*pn)=0;
	FILE *f=fopen(fname,"r");
	if (f==NULL){
		printf("\nKhong the doc file");
		return;
	}
	while (*pn<nmax && fscanf(f," %d,%49[^,],%49[^,],%49[^,],%f"
										, &a[*pn].id
										, a[*pn].patient
										, a[*pn].doctor
										, a[*pn].surgery
										, &a[*pn].cost)==5){
											(*pn)++;
										}
	fclose(f);
}
void PrintFile(ds a[],int n){
	if(n==0) return;
	printf("| %-15s | %-25s | %-20s | %-15s | %s", "ID","Patient","Doctor","Surgery","Cost");
	for (int i=0;i<n;i++){
		printf("\n| %-15d | %-25s | %-20s | %-15s | %.2f", a[i].id
										, a[i].patient
										, a[i].doctor
										, a[i].surgery
										, a[i].cost);
	}
}
//WriteFile(char *fname,ds a[]){
//	FILE *f=fopen(fname,"w");
//	if (f==NULL){
//		printf("\nKhong the luu ket qua");
//		return;
//	}
//	for (int i=0;i<n;i++){
//		fprintf(f,"%d,%49[^,],%49[^,],%49[^,],%f"
//										, a[i].id
//										, a[i].patient
//										, a[i].doctor
//										, a[i].surgery
//										, a[*pn].cost)
//	}
//}
void ClearBuffer(){
	int c;
	while ((c=getchar())!='\n' && c!=EOF);
}
void AverageFee(ds a[],int n){
	if (n==0) return;
	int cthy=0, clas=0, cden=0;
	float sthy=0, slas=0, sden=0;
	for (int i=0;i<n;i++){
		if (strcmp(a[i].surgery,"Thyroid")==0){
			cthy++; 
			sthy+=a[i].cost;
		}
		else if (strcmp(a[i].surgery,"Lasek")==0) {
			clas++;
			slas+=a[i].cost;
		}
		else if (strcmp(a[i].surgery,"Dental")==0){
			cden++;
			sden+=a[i].cost;
		}
	}
	FILE *f=fopen("AVERAGE.txt","w");
	fprintf(f,"\nTrung binh cua Thyroid : %.2f",sthy/cthy);
	fprintf(f,"\nTrung binh cua Lasek : %.2f",slas/clas);
	fprintf(f,"\nTrung binh cua Dental : %.2f",sden/cden);
	printf("\nDa thanh cong ...");
	fclose(f);
}
void DocRep(ds a[],int n){
	if (n==0) return;
	char SearchName[25];
//	ClearBuffer();
	printf("Nhap ten bac si muon tim: ");
	fgets(SearchName,sizeof(SearchName),stdin);
	SearchName[strcspn(SearchName,"\n")]='\0';
	int check=0;
	FILE *f=fopen("DOCTORNAME.txt","w");
	if (f==NULL) return;
	for (int i=0;i<n;i++){
		if (strcmp(a[i].doctor,SearchName)==0){
			check=1;
			fprintf(f,"\n| %-15d | %-25s | %-20s | %-15s | %.2f", a[i].id
										, a[i].patient
										, a[i].doctor
										, a[i].surgery
										, a[i].cost);
		}
	}
	if (!check) printf("\nKhong thanh cong ...");
	else printf("\nDa thanh cong ...");
	fclose(f);
}
void SurgeryRep(ds a[],int n){
	char S[25];
//	ClearBuffer();
	printf("\nNhap khoa phau thuat : ");
	fgets(S,sizeof(S),stdin);
	S[strcspn(S,"\n")]='\0';
	int check=0;
	FILE *f=fopen("TYPE.txt","w");
	if (f==NULL) return;
	for (int i=0;i<n;i++){
		if (strcmp(a[i].surgery,S)==0){
			check=1;
			fprintf(f,"\n| %-15d | %-25s | %-20s | %-15s | %.2f", a[i].id
										, a[i].patient
										, a[i].doctor
										, a[i].surgery
										, a[i].cost);
		}
	}
	if (!check) printf("\nKhong thanh cong ...");
	else printf("\nDa thanh cong ...");
	fclose(f);
}
void Total(ds a[],int n){
	FILE *f=fopen("TOTAL.txt","w");
	if (f==NULL) return;
	float slee=0, snorris=0, sbond=0;
	for (int i=0;i<n;i++){
		if (strcmp(a[i].doctor,"Lee")==0) slee+=a[i].cost;
		else if (strcmp(a[i].doctor,"Norris")==0) snorris+=a[i].cost;
		else if (strcmp(a[i].doctor,"Bond")==0) sbond+=a[i].cost;
	}
	fprintf(f,"\nTong tien cua bac si Lee : %.2f",slee);
	fprintf(f,"\nTong tien cua bac si Noris : %.2f",snorris);
	fprintf(f,"\nTong tien cua bac si Bond : %.2f",sbond);
	fclose(f);
}
int main(){
	ds list[100];
	int choice;
	int n=0;
	ReadFile("patient.txt",&n,list,100);
	do{
		printf("\n=== Menu ===");
		printf("\n1. In thong tin ra man hinh");
		printf("\n2. In chi phi trung binh");
		printf("\n3. Tim bac si theo ten");
		printf("\n4. Tim khoa phau thuat");
		printf("\n5. Tong so tien cua cac bac si");
		printf("\n6. De Thoat");
		printf("\n============");
		printf("\nNhap lua chon : ");
		scanf("%d",&choice);
		while ( getchar()!='\n');
		
		switch(choice){
			case 1:
//				ReadFile("patient.txt",&n,list,100);
				PrintFile(list,n);
				break;
			case 2:
				AverageFee(list,n);
				break;
			case 3:
				DocRep(list,n);
				break;
			case 4:
				SurgeryRep(list,n);
				break;
			case 5:
				Total(list,n);
				break;
			default:
				break;
		}
	
	}while(choice!=6);
	return 0;
}
