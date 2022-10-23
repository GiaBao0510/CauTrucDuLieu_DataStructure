#include"C:\BasicProgramming\BinarySearchTree\ThuVienBST.cpp"
void read(BST *T){
	int n,i,k;
	keytype X;
	printf("Nhap so luong nut trong cay: "); scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap nut[%d]: ",i);scanf("%d",&X);
		insert_node(X,T);
	}
	printf("\nNhap 1 nut de tim kiem: ");scanf("%d",&k);
	if(search(k,*T)){
		printf("Co nut %d trong cay tim kiem nhi phan",k);
	}
	else{
		printf("khong co nut %d trong cay tim kiem nhi phan",k);
	}
}
int maxnode(BST T){
	keytype x;
	while(!empty_bst(T)){
		x=T->key;
		T=right_child(T);
	}
	return x;
}
int minnode(BST T){
	keytype x;
	while(!empty_bst(T)){
		x=T->key;
		T=left_child(T);
	}
	return x;
}
int NumberOfLeafNode(BST T){
	if(T==NULL){
		return 0;
	}
	if(T->left==NULL&&T->right==NULL){
		return 1;
	}
	return NumberOfLeafNode(left_child(T))+NumberOfLeafNode(right_child(T));
}
int chieucao(BST T){
	int l=0,r=0;
	if(T==NULL) return 0;
	l=chieucao(T->left);
	r=chieucao(T->right);
	return (l>r? l:r)+1;//IF(l>R) return L+1; else return R+1;
}
int main(){
	BST T;
	makenull_bst(&T);
	read(&T);
	printf("\nDuyet tien tu: ");
	preorder(T);
	printf("\nDuyet trung tu: ");
	inorder(T);
	printf("\nDuyet hau tu: ");
	posorder(T);
	printf("\nSo nut khoa trong cay %d.",nb_node(T));
	printf("\nNut lon nhat trong cay %d.",maxnode(T));
	printf("\nNut nho nhat trong cay %d.",minnode(T));
	printf("\nCo tong cong co %d nut la trong cay.",NumberOfLeafNode(T));
	printf("\nChieu cao cua cay tren la: %d",chieucao(T));
}
