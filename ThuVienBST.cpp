#include<stdio.h>
#include<malloc.h>
typedef int keytype;//Quy dinh kieu cua khoa
typedef struct Node{
	keytype key;//Luu tru Gia tri cua khoa
	struct Node* left;
	struct Node* right;
}Node;
typedef Node *BST;
//Khoi tao cay BST rong
void makenull_bst(BST *root){
	(*root)=NULL;
}  
//Kiem tra cay rong
int empty_bst(BST root){
	return root==NULL;
}
//Con trai 
BST left_child(BST n){
	if(n!=NULL){
		return n->left;
	}
	else return NULL;
}
//Con phai 
BST right_child(BST n){
	if(n!=NULL){
		return n->right;
	}
	else return NULL;
}
//kiem tra nut la
int leaf(BST n){
	if(n!=NULL){
		return(left_child(n)==NULL)&&(right_child(n)==NULL);
	}
	else return NULL;
}
//Xac dinh so nut trong cay
int nb_node(BST T){
	if(!empty_bst(T)){
		return 1+nb_node(left_child(T))+nb_node(right_child(T));
	}
	else return 0;
}
//Tim nut khoa X trong cay BST
BST search(keytype X,BST root){
	if(root==NULL){
		return NULL;//khong tim thay x
	}
	else if(root->key==X){
		return root;//tim thay x
	}
	else if(X>root->key){
		return search(X,root->right);//Tim kiem ben cay con phai
	}
	else{
		return search(X,root->left);//Tim kiem ben cay con trai
	}
}
//Them nut khoa X vao cay BST
void insert_node(keytype X,BST *T){
	//Neu nut goc bang NUll
	if((*T)==NULL){
		(*T)=(Node*)malloc(sizeof(Node));//cap phat bo nho
		(*T)->key=X;
		(*T)->left=NULL;
		(*T)->right=NULL;
	}
	//Neu gia tri tai nut goc bang X
	else if((*T)->key==X){
		printf("\nCay da co %d. \n",X);
	}
	//Neu gia tri X > nut goc
	else if(X>(*T)->key){
		insert_node(X,&(*T)->right);
	}
	//Neu gia tri X < nut goc
	else if(X<(*T)->key){
		insert_node(X,&(*T)->left);
	}
} 
//Xoa 1 nut khoa X khoi cay 
keytype deletemin(BST root){
	keytype k;
	if(root->left==NULL){
		k=root->key;
		root=root->right;
		return k;
	}
	else deletemin(root->left);
}
void delete_node(keytype x,BST *T){
	//Tim kiem cay khong rong
	if(*T!=NULL){
		if(x>(*T)->key){
			delete_node(x,&(*T)->right);//Hy vong X nam ben cay con phai
		}
		else if(x<(*T)->key){
			delete_node(x,&(*T)->left);//Hy vong X nam ben cay con trai
		}
		//N la nut la 
		else if(((*T)->left==NULL)&&((*T)->right==NULL)){
			(*T)=NULL;//gan gia tri nut la bang NULL 
		}
		//N co 1 cay con
		else if((*T)->left==NULL){
			(*T)=(*T)->right;//Chac chan con phai 
		}
		else if((*T)->right==NULL){
			(*T)=(*T)->left;//Chac chan con trai
		}
		//N co 2 cay con
		else (*T)->key=deletemin((*T)->right);
	}
}
//Duyet tien tu (N,L,R)
void preorder(BST n){
	printf("%d ",n->key);
	if(left_child(n)!=NULL){
		preorder(left_child(n));
	}
	if(right_child(n)!=NULL){
		preorder(right_child(n));
	}
}
//duyet trung tu (L,N,R)
void inorder(BST n){
	if(left_child(n)!=NULL){
		inorder(left_child(n));
	}
	printf("%d ",n->key);
	if(right_child(n)!=NULL){
		inorder(right_child(n));
	}
}
//duyet hau tu (L,R,N)
void posorder(BST n){
	if(left_child(n)!=NULL){
		posorder(left_child(n));
	}
	if(right_child(n)!=NULL){
		posorder(right_child(n));
	}
	printf("%d ",n->key);
}
