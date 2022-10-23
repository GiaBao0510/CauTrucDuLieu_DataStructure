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
int Count_List(ElementType X,List L){
	int dem=0;
	Position P;
	P=First_List(L);
	while(P!=End_List(L)){
		if(Retrieve(P,L)==X){
			dem++;
		}
		P=Next(P,L);
	}
	return dem;
}
ElementType Max_List(List L){
	Position p,k;
	p=First_List(L);
	k=Retrieve(p,L);
	while(p!=End_List(L)){
		if(Retrieve(p,L)>k){
			k=Retrieve(p,L);
		}
		p=Next(p,L);
	}
	return k;
}
ElementType Min_List(List L){
	Position p,k;
	p=First_List(L);
	k=Retrieve(p,L);
	while(p!=End_List(L)){
		if(Retrieve(p,L)<k){
			k=Retrieve(p,L);
		}
		p=Next(p,L);
	}
	return k;
}
int Sum_List(List L){
	Position p;
	int sum=0;
	p=First_List(L);
	while(p!=End_List(L)){
		sum+=Retrieve(p,L);
		p=Next(p,L);
	}
	return sum;
}
int main(){
	List L;
	int k,m,n;
	Makenull_List(&L);
	ReadList(&L);
	PrintfList(L);
	printf("\nVi tri dau tien trong danh sach: %d - %d",First_List(L),Retrieve(First_List(L),L));
	printf("\nVi tri sau phan tu cuoi cung trong danh sach: %d - %d",End_List(L),NULL);
	printf("\nGia tri lon nhat trong danh sach: %d",Max_List(L));
	printf("\nGia tri nho nhat trong danh sach: %d",Min_List(L));
	printf("\nTong cac phan tu trong danh sach: %d",Sum_List(L));
	printf("\nNhap phan tu X trong danh sach: ");scanf("%d",&k);
	printf("\nPhan tu %d o vi tri %d",Locate(k,L));
    printf("\nVi tri phan tu dung truoc vi tri %d trong danh sach la vi tri: %d - %d",Locate(k,L),Previous(Locate(k,L),L),Retrieve(Previous(Locate(k,L),L),L));
    printf("\nVi tri phan tu dung sau vi tri %d trong danh sach la vi tri: %d - %d",Locate(k,L),Next(Locate(k,L),L),Retrieve(Next(Locate(k,L),L),L));
	printf("\nPhan tu %d xuat hien %d lan trong danh sach.",k,Count_List(k,L));	
}
