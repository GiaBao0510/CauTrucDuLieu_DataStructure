#include<stdio.h>
#include"C:\BasicProgramming\StackNganXep\StackS.cpp"
//Doc Ngan xep
void readStack(Stack *s){
	int n,i,x;
	printf("Nhap so luong phan tu: "); scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i);scanf("%d",&x);
		Push(x,s);
	}
}
//In ngan xep
void PrintStack(Stack s){
	printf("\nCac phan tu trong ngan xep:\n"); 
	while(!Empty_Stack(s)){
		printf("\t%d\n",Top(s));
		Pop(&s);
	}
}
int main(){
	Stack S;
	Makenull_Stack(&S);
	readStack(&S);
	PrintStack(S);
	printf("\nPhan tu o dinh ngan xep: %d",Top(S));
	printf("\nXoa phan tu o dinh ngan xep:\n");
	Pop(&S);
	PrintStack(S);
	int x;
	printf("\nNhap phan tu muon them vao dau Ngan xep: ");scanf("%d",&x);
	Push(x,&S);
	PrintStack(S);
	return 0;
}
