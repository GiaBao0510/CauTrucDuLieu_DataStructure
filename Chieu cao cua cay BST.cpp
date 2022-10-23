#include"C:\BasicProgramming\BinarySearchTree\ThuVienBST.cpp"
int n, a[50];
void readbst(BST *T){
	keytype X;
	printf("Nhap so luong nut: ");scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Nhap nut: ",i);scanf("%d",&X);
		insert_node(X,T);
		a[i]=X;
	}
}
//Ham tim chieu cao cua 1 nut
int hnode(keytype x,BST T){
	if(T==NULL) return -1;//Neu T= NULL thi tra ve -1
	if(T->key==x){
		if(T->left==NULL&&T->right==NULL){
			return 0;//Neu T la nut la thi tra ve khong
		}
		int l=0,r=0;
		if(T->left!=NULL){
			l=hnode(T->left->key,T->left);//L la chieu cao cua nut con trai trong cay con trai
		}
		if(T->right!=NULL){
			r=hnode(T->right->key,T->right);//R la chieu cao cua nut con phai trong cay con phai
		}
		return (l>r? l:r)+1;//so sanh L va R neu L > R tra ve L + 1 va nguoc lai
	}
	else if(T->key>x){//tra ve chieu cao cay con trai
		hnode(x,T->left);
	}
	else hnode(x,T->right);//Nguoc lai tra ve chieu cao cay con phai
}
int main(){
	BST T;
	makenull_bst(&T);
	readbst(&T);
	printf("duyet tien tu: ");preorder(T);
	for(int i=0;i<n;i++){
		printf("\nchieu cao cua %d la %d",a[i],hnode(a[i],T));
	}
	return 0;
}
