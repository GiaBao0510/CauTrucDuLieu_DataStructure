#include<stdio.h>
#include<malloc.h>
typedef int Elementtype;
struct Node{
	Elementtype Element;//Luu tri gia tri cua nut
	struct Node *Next;//Con tro tro den phan tu ke tiep
};
typedef struct Node *Position;//kieu vi tri 
typedef Position List;
//Khoi tao danh sach rong
void Makenull_list(List *L){
	(*L)=(struct Node*)malloc(sizeof(struct Node));
	(*L)->Next=NULL;
}
//Kiem tra danh sach rong
int Empty_list(List L){
	return (L->Next==NULL);
}
//Tra ve phan tu dau tien
Position First_list(List L){
	return L;
}
//Tra ve vi tri sau phan tu cuoi cung
Position End_list(List L){
	Position P;
	P=First_list(L);
	while(P->Next!=NULL){
		P=P->Next;
	}
	return P;
}
//Tra ve vi tri phan tu dung sau vi tri P trong danh sach L
Position Next(Position P,List L){
	if(!Empty_Set(A)) return P->Next;
}
//Tra ve vi tri phan tu dung truoc vi tri P trong danh sach L
Position Previous(Position P,List L){
	Position Q;
	while(Q->Next!=P){
		Q=Q->Next;
	}
	return Q;
} 
//Tra ve gia tri tai vi tri P trong danh sach L
Elementtype Retrieve(Position P,List L){
	if(P->Next!=NULL){
		return P->Next->Element;
	}
}
//Xac dinh gia tri X trong danh sach L
Position Locate(Elementtype X,List L){
	Position P;
	int found=0;
	while((P->Next!=NULL)&&!found){
		if(Retrieve(P,L)==X){
			found=1;
		}
		else{
			P=P->Next;
		}
	}
	return P;
}
//Xen phan tu X vao danh sach L
void Insert_list(Elementtype X,Position P,List *L){
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=X;
	T->Next=P->Next;
	P->Next=T; 
}
//Xoa phan tu tai vi vi P trong danh sach L
void Delete_list(Position P,List L){
	Position T;
	if(P->Next!=NULL){
		T=P->Next;
		P->Next=T->Next;
	}
	free(T);
}
