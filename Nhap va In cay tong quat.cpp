#include<stdio.h>
#include"C:\BasicProgramming\CayTongQuat\PhepToanCayTongQuat.cpp"
int Read(Tree *T){
	int i;
	Makenull_Tree(*&T);
	do{
		printf("\nNhap so luong nut cho cay: ");scanf("%d",&T->Maxnode);
	}while((T->Maxnode-1<1)||(T->Maxnode-1>Maxlength));
	printf("Nhap nut goc: "); fflush(stdin);
	scanf("%c",&T->data[0]);
	T->parent[0]=NIL;
	for(i=1;i<=T->Maxnode-1;i++){
		printf("Nhap cha(Parent) cua nut [%d]: ",i);
		scanf("%d",&T->parent[i]);
		printf("Nhap nhan cua nut[%d]: ",i);fflush(stdin);
		scanf("%c",&T->data[i]);
	}
}
int main(){
	Tree T;
	printf("\tNhap du lieu cay tong quat.\n");
	Read(&T);
	printf("Nut goc: %d ",Root(T));
	printf("\nDanh sach duyet tien tu cua cay:\n");
	PreOrder(Root(T),T);
	printf("\nDanh sach duyet trung tu cua cay:\n");
	InOrder(Root(T),T);
	printf("\nDanh sach duyet hau tu cua cay:\n");
	PostOrder(Root(T),T);
}
