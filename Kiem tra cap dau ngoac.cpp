#include<stdio.h>
#include<string.h>
#include"C:\BasicProgramming\StackNganXep\StackS.cpp"
int KTngoac(char kt[]){
	Stack S;
	Makenull_Stack(&S);
	for(int i=0;i<strlen(kt);i++){
		if(kt[i]=='('){//Day vao trong ngan xep
			Push(kt[i],&S);
		}
		else if(kt[i]==')'){
			if(!Empty_Stack(S)){//Ngan xep khong rong thi xoa
				Pop(&S);
			}
			else return 0;//rong thi tra ve 0
		}
	}
	if(Empty_Stack(S)) return 1;//Neu xoa het '(' la rong thi tra ve 1
	else return 0;//Nguoc la chua xoa het '(' thi tra ve 0
}
int main(){
	char a[50];
	printf("Nhap vao 1 doan co dau ngoac ben trong: ");gets(a);
	if(KTngoac(a)){
		printf("HOP LE");
	}
	else printf("KHONG HOP LE");
}
