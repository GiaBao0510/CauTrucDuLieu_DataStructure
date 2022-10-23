#include"C:\BasicProgramming\BinarySearchTree\ThuVienBST.cpp"
int n,a[50];
void read_bst(BST *T){
	int i;
	keytype X;
	printf("Nhap so luong phan tu: ");scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap[%d]: ",i);scanf("%d",&X);
		insert_node(X,T);
		a[i]=X;
	}
}
BST getparent(keytype X,BST T){
	BST parent=NULL;//cho P = T va parent = NULL
	while(!empty_bst(T)){
		if(T->key==X){//Neu P tro den key == X thi tra ve parent
			return parent;
		}
		parent=T;// Nguoc la cap nhat parent = P
		if(T->key>X){
			T=left_child(T);
		}
		else T=right_child(T);
	}
	return NULL;// Neu tren cay khong co nut khoa X can tim tra ve NULL
}
int main(){
	BST T,P;
	makenull_bst(&T);
	read_bst(&T);
	printf("Duyet tien tu: ");preorder(T);
	printf("\nDuyet trung tu: ");inorder(T);
	printf("\nDuyet hau tu: ");posorder(T);
	for(int i=0;i<n;i++){
		P=getparent(a[i],T);
		if(P!=NULL){
			printf("\nCha cua nut %d la %d",a[i],P->key);
		}
		else{
			printf("\nKhong tim thay cha cua nut %d tren cay",a[i]);
		}
	}
}
