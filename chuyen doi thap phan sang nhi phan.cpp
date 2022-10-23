#include<stdio.h>
#include"C:\BasicProgramming\StackNganXep\StackS.cpp"
void dec2bin(int num,Stack *S){
	int x;
	if(num==0){
		printf("%d ",num);
	}
	while(num>=0){
		x=num%2;
		Push(x,*&S);
		num/=2;
		if(num==0){
			break;
		}
	}
	while(!Empty_Stack(*S)){
		printf("%d ",Top(*S));
		Pop(*&S);
	}
}
int main(){
	Stack s;
	Makenull_Stack(&s);
	int n;
	printf("Nhap vao phan tu N: ");scanf("%d",&n);
	dec2bin(n,&s);
}
