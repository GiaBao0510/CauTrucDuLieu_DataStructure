#include<stdio.h>
#define Maxlength 100
#define NIL -1// Dinh nghia NIL = -1.
typedef char Datatype;
typedef int Node;
typedef struct{
	Datatype data[Maxlength];//Luu tru nhan(du lieu) cua moi nut trong cay
	Node parent[Maxlength];/*Luu tru cha cua cac nut trong cay theo nguyen tac: cha cua
	nut i se luu o vi tri i trong mang */
	int Maxnode;//so nut thuc su trong cay
}Tree;
//Khoi tao cay rong
void Makenull_Tree(Tree *T){
	T->Maxnode=0;
}
//Kiem tra cay co rong khong
int Empty_Tree(Tree T){
	return T.Maxnode==0;
}
//Xac dinh nut cha
Node parent(Node n,Tree T){
	if(Empty_Tree(T)||n>T.Maxnode-1){
		return NIL;
	}
	else{
		return T.parent[n];
	}
}
//Xac dinh nhan cua nut
Datatype Label(Node n,Tree T){
	if(Empty_Tree(T)||n>T.Maxnode-1){
		return NIL;
	}
	else{
		return T.data[n];
	}
}
//Xac dinh nut goc
Node Root(Tree T){
	if(!Empty_Tree(T)){
		return 0;
	}
	else{
		return NIL;
	}
}
//Ham xac dinh con trai nhat cua mot nut
Node Leftmost_child(Node n,Tree T)
{ Node i; int found;
if (n<0) return NIL;
i=n+1;//Vi trí nút ðau tiên hy vong là con cua nút n
found=0;
while ((i<=T.Maxnode-1) && !found)
if (T.parent[i]==n){
	found=1;
} 
/* Ða tim thay con trái nhat cua nút n */
else {
	i++;
}
if (found) {
	return i;
}
else{
	return NIL;
} 
}
//Ham xac dinh ang em ruot phai
Node Right_Sibling(Node n,Tree T)
{ Node i,parent; 
int found;
	if (n<0) return NIL;
parent=T.parent[n];
	i=n+1;
	found=0;
while ((i<=T.Maxnode-1) && !found){
	if (T.parent[i]==parent){
		found=1;
	} 
	else{
	i++;	
	} }
if (found){
	return i;
} 
else{
	return NIL;
} 
}
//Duyet tien tu
void PreOrder(Node n,Tree T){
	Node i;
	printf("%c ",Label(n,T));
	i=Leftmost_child(n,T);
	while(i!=NIL){
		PreOrder(i,T);
		i=Right_Sibling(i,T);
	}
}
//Duyet trung tu
void InOrder(Node n,Tree T)
{ Node i;
i=Leftmost_child(n,T);
if (i!=NIL) InOrder(i,T);
printf("%c ",Label(n,T));
i=Right_Sibling(i,T);
while (i!=NIL)
{
InOrder(i,T);
i=Right_Sibling(i,T);
}
}
//Duyet Hau tu
void PostOrder(Node n,Tree T)
{ Node i;
i=Leftmost_child(n,T);
while (i!=NIL)
{
PostOrder(i,T);
i=Right_Sibling(i,T);
}
printf("%c ",Label(n,T));
}
