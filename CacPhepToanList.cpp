#include<stdio.h>
#define Maxlength 100
typedef int ElementType;//Kieu phan tu trong danh sach
typedef int Position;//Kieu vi tri trong danh sach
typedef struct{
	ElementType Elements[Maxlength];//Noi dung cua phan tu trong danh sach
	Position Last;// Do dai cua danh sach
}List; 
//Tao danh sach rong
void Makenull_List(List *L){
	L->Last=0;
}
//Kiem tra danh sach rong
int Empty_List(List L){
	return L.Last==0;
}
//Tra ve vi tri dau tien trong danh sach
Position First_List(List L){
	return 1;
}
//Tra ve vi tri sau phan tu cuoi cung trong danh sach
Position End_List(List L){
	return L.Last+1;
}
//Tra ve noi dung cua phan tu tai vi tri P,trong danh sach
ElementType Retrieve(Position P,List L){
	if(Empty_List(L)){
		printf("Danh sach rong.");
	}
	else{
		return L.Elements[P-1];
	}
}
//Tra ve vi tri phan tu dung sau vi tri P trong danh sach l
Position Next(Position P,List L){
	return P+1; 
}
//Tra ve vi tri phan tu dung truoc vi tri P trong danh sach l
Position Previous(Position P,List L){
	return P-1; 
}
//Xen phan tu X,tai vi tri P,trong danh sach L
void Insert_List(ElementType X,Position P,List *L){
	if((L->Last)==Maxlength){
		printf("Danh sach day.");
	}
	if((P<1)||(P>L->Last+1)){
		printf("Vi tri khong hop le.");
	}
	else{
		Position Q;
		for(Q=(L->Last-1)+1;Q>P-1;Q--){
			L->Elements[Q]=L->Elements[Q-1];
		}
		L->Elements[P-1]=X;
		L->Last++;
	}
}
//Xoa phan tu tai vi tri P trong danh sach L
void Delete_List(Position P,List *L){
	if(Empty_List(*L)){
		printf("Danh sach rong.");
	}
		if((P<1)||(P>L->Last+1)){
		printf("Vi tri khong hop le.");
	}
	else{
		Position Q;
		for(Q=P-1;Q<L->Last-1;Q++){
			L->Elements[Q]=L->Elements[Q+1];
		}
		L->Last--;
	}
}
//Tim phan tu X trong danh sach L
Position Locate(ElementType X,List L){
	int phao=0;
	Position P;
	P=First_List(L);
	while((P!=End_List(L))&&(!phao)){
		if(Retrieve(P,L)==X){
			phao=1;
		}
		else{
			P=Next(P,L);
		}
	}
	return P;
}
