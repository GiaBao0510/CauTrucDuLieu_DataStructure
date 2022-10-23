#include<stdio.h>
#define Maxlength 100 //Quy dinh do dai toi da
typedef int Elementtype;//kieu phan tu trong ngan xep
typedef struct{
	Elementtype Elments[Maxlength];//Noi dung cua phan tu trong ngan xep
	int top_index;//Quan ly dinh cua ngan xep
}Stack;
//Khoi tao ngan xep rong
void Makenull_Stack(Stack *s){
	s->top_index=Maxlength;
}
//Kiem tra ngan xep rong
int Empty_Stack(Stack s){
	return s.top_index==Maxlength;
}
//Kiem tra ngan xep day
int Full_Stack(Stack s){
	return s.top_index==0;
}
//In ra phan tu dung dau ngan xep
Elementtype Top(Stack s){
	if(Empty_Stack(s)){
		printf("Danh sach rong.");
	}
	else{
		return s.Elments[s.top_index];
	}
}
//Xoa phan tu o dinh ngan xep
void Pop(Stack *s){
	if(Empty_Stack(*s)){
		printf("Danh sach rong.");
	}
	else{
		s->top_index+=1;
	}
}
//Them phan tu X vao dinh ngan xep
void Push(Elementtype X,Stack *s){
	if(Full_Stack(*s)){
		printf("Ngan xep day.");
	}
	else{
		s->top_index-=1;
		s->Elments[s->top_index]=X;
	}
}

