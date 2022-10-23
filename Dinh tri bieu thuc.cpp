#include"C:\BasicProgramming\StackNganXep\StackS.cpp"
#include<string.h>
#include<malloc.h>
//La toan hang
int isoperand(char c){
	return (c>=48)&&(c<=57);
}
//Tra ve do uu tien
int priority(char c){
	if(c=='+'||c=='-'){
		return 1;
	}
	if(c=='*'||c=='/'||c=='%'){
		return 2;
	}
	return 0;
}
//Noi ky tu vao duoi cua chuoi
void strAdd(char *str,char c){
	int L=strlen(str);
	str[L]=c;
	str[L+1]=' ';
	str[L+2]='\0';
}
//Doi trung to sang hau to
void Infix2posfix(char *infix,char *posfix){
	Stack S;
	Makenull_Stack(&S);
	int i,L=strlen(infix);
	char token;
	for(i=0;i<L;i++){
		token=infix[i];
		if(token!=32){//Neu token khong la khoang tran
			if(isoperand(token)){//Neu token la toan hang
				strAdd(posfix,token);
			
			}
			else{
			 	if(token=='('){//Neu token la dau ngoac mo thi day vao stack
				 Push('(',&S);
				}
				else if(token==')'){//Neu tokenla dau ngoac dong thi lay gia tri cua toan hang noi vao hau to
					while(Top(S)!='('){
						strAdd(posfix,Top(S));
						Pop(&S);
					}
					Pop(&S);
				}
				else{ //Neu token la 1 toan tu
					//Ngan xep khac rong va do uu tien cua toan tu tren dinh Stack lon hon do uu tien cua toan tu hien tai
					while(!Empty_Stack(S)&&priority(Top(S))>=priority(token)){
					strAdd(posfix,Top(S));//Noi toan tu tren dinh ngan xep vao bieu thuc hau to
					Pop(&S);//Xoa bo	
					}
					Push(token,&S);
				}
			}
		}
	}//Het vong lap for
	while(!Empty_Stack(S)){//Neu con phan tu trong Stack thi ta lay no ra roi noi vao BT hau to
		strAdd(posfix,Top(S));
		Pop(&S);
	}
}
//Dinh tri bieu thuc hau to
int calculate(int a,int b,char operand){
	switch (operand){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '%':
			return a%b;				
	}
}
//Ham dinh tri BT hau to
int eval(char *C){
	Stack S;
	char token;
	int tren,duoi;
	Makenull_Stack(&S); 
	int L=strlen(C),i;
	for(i=0;i<L;i++){
		token=C[i];
		if(token!=32){
			if(isoperand(token)){
				Push(token-48,&S);
			}
			else{//La toan tu
				tren=Top(S);
				Pop(&S);
				duoi=Top(S);
				Pop(&S);
				Push(calculate(duoi,tren,token),&S);
			}
		}
	}
	 return Top(S);
}
int main(){
	char posfix[255];
	char infix[255];
	printf("\nNhap 1 bieu thuc toan hoc: ");gets(infix);
	strcpy(posfix,"");
	Infix2posfix(infix,posfix);
	printf("\n");
	puts(posfix);
	printf("\nGia tri cua bieu thuc la %d",eval(posfix));
	return 0;
}
