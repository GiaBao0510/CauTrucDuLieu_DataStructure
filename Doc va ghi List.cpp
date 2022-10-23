#include<stdio.h>
#include"C:\BasicProgramming\DanhSachList\CacPhepToanList.cpp"
void ReadList(List *L){
	int i,n,x;
	printf("Nhap so luong phan tu trong danh sach: ");scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i);scanf("%d",&x);
		Insert_List(x,End_List(*L),L);
	}
}
void PrintfList(List L){
	printf("\nCac phan tu trong danh sach:\n");
	Position P;
	int i=1;
	P=First_List(L);
	while(P!=End_List(L)){
		printf("%d - %d\n",i,Retrieve(P,L));
		P=Next(P,L);
		i++;
	}
}
int main(){
	List L;
	int k,m,n;
	Makenull_List(&L);
	ReadList(&L);
	PrintfList(L);
	printf("\nVi tri phan tu dau tien: %d - %d",Locate(Retrieve(First_List(L),L),L),Retrieve(First_List(L),L));
	printf("\nVi tri sau phan tu cuoi: %d - %d",Locate(Retrieve(End_List(L),L),L),Retrieve(End_List(L),L));
	printf("\nNhap vi tri can Xoa: ");scanf("%d",&k);
	Delete_List(k,&L);
	PrintfList(L);
	printf("\n\tChen Vi tri:\n");
	printf("\nNhap vi tri can chen:");scanf("%d",&m);
	printf("\nNhap phan tu tai vi tri can chen:");scanf("%d",&n);
	Insert_List(n,m,&L);
	PrintfList(L);
}
