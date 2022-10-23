#include<stdio.h>
#define B 100
#define deleted -1000
#define empty 1000
typedef int emlement;	//Kieu du lieu
typedef	int position;	//Vi tri cua phan tu
typedef	emlement dictionary[B];
//Tra ve gia tri bam
int H(int x){
	return x%B;
}
//Tao tu dien rong
void makeNullDic(dictionary A){
	int i;
	for(i=0;i<B;i++){
		A[i]=empty;
	}
}
//Kiem tra tu dien co rong chua
int emptyDic(dictionary D){
	int i=0,found=0;
	while(found == 0 && i<B){
		if(D[i]!=empty){
			found = 1;	//La chua rong
		}else{
			i++;
		}
	}
	return found;
}
//Kiem tra tu dien co day chua
int fullDic(dictionary D){
	int i=0,found=0;
	while(found == 0 && i<B){
		if(D[i]==empty){
			found = 1;	//La chua day
		}else{
			i++;
		}
	}
	return found;
}
//Kiem tra su ton tai cua phan tu X co trong tu dien khong
int member(emlement x,dictionary D){
	position P = H(x); //Ham bam
	int i=0,found=0;
	while((i<B) && (D[P]!=empty) && (found == 0)){
		if(D[P] == x){
			found = 1;
		}else{
			(P+=1)%B;
			i++;
		}
	}
	return found;
}
//Them phan tu vao tu dien
void insertDic(emlement x,dictionary D){
	position P;
	if(fullDic( D) == 0){
		printf("Bang bam nay day");
	}else if(!member( x, D)){
		P=H(x);
		int i=0;
		while((i<B) && D[P]!=empty && D[P]!=deleted){
			i++;
			(P+=1)%B;
		}
		D[P]=x;
	}
	else{
		printf("\nPhan tu %d da ton tai\n",x);
	}
}
//Xoa phan tu ra khoi tu dien
void deleteDic(emlement x,dictionary D){
	if(emptyDic(D)==0){
		printf("\nBang bam rong");
	}
	else{
		int i=0;
		position P=H(x);
		while((i<B) && (D[P]!=x) && (D[P]!=empty)){
			i++;
			(P+=1)%B;
		}
		if(D[P]==x){
			D[P] = deleted;
		}
	}
}
void readDic(int n,dictionary A){
	int x,i;
	for(i=0;i<n;i++){
		printf("[%d]: ",i);scanf("%d",&x);
		insertDic(x, A);
	}
}
void printDic(int n,dictionary A){
	int i;
	printf("\nIn:\n");
	for(i=0;i<n;i++){
		if(A[i]!=deleted && A[i]!=empty){
			printf("\n%d: %d",i,A[i]);
		}
	}
}
int main(){
	int n;
	emlement D;
	makeNullDic(&D);
	printf("Nhap so luong phan tu: ");scanf("%d",&n);
	readDic(n, &D);
	printDic( n, &D);
	return 0;
} 
