#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elmt{
	int *data;
	struct Elmt *left;
	struct Elmt *right;
	struct Elmt *parent;
}Elmt_tree;

typedef struct tree{
	Elmt_tree *root;
	int size;
}Tree;

Tree *Init_tree(){
	Tree *tree;
	tree=(Tree*)malloc(sizeof(Tree));
	tree->root=NULL;
	tree->size=0;
	return tree;
}

void insert_data(Tree *tree,int *data){
	Elmt_tree *x;
	x=tree->root;
	Elmt_tree *y=NULL;
	Elmt_tree *new_element;
	
	new_element=(Elmt_tree*)malloc(sizeof(Elmt_tree));
	new_element->data=data;
	new_element->left=NULL;
	new_element->right=NULL;
	new_element->parent=NULL;
		
	while(x!=NULL){
		y=x;
		
		if(new_element->data>x->data)x=x->right;
		else x=x->left;
		
	}
	
	new_element->parent=y;
	
	if(y==NULL)tree->root=new_element;
	else if(y->data>new_element->data) y->left=new_element;
	else y->right=new_element; 
	
		
	tree->size++;
	
}
void print_data(Elmt_tree *node){
	if(!node)return;
	static int i=0;		//Áß¿ä !!
	print_data(node->left);
	printf("[%d]%d\n",++i,*node->data);
	print_data(node->right);
}

Elmt_tree *const search(Elmt_tree *node,int search_data){
	//if(node==NULL)return node;
	
	if(*node->data==search_data) return node;
	else if(*node->data>search_data) return search(node->left,search_data);
	else return search(node->right,search_data);
}
void trans_(Tree *tree, Elmt_tree *u, Elmt_tree *v){
	if(u->parent==NULL){
		tree->root=v;
	}
	else if(u==u->parent->left){
		u->parent->left=v;
	}
	else{
		u->parent->right=v;
	}
	if(v!=NULL){
		v->parent=u->parent;
	}
}

Elmt_tree *min_node_(Elmt_tree *node){
	while(node->left){
		node=node->left;
	}
	return node;
}

void remove_data(Elmt_tree *node_delete,Tree *tree){
	Elmt_tree *min_node;
	if(node_delete->left==NULL){
		trans_(tree,node_delete,node_delete->right);
	}
	else if(node_delete->right==NULL){
		trans_(tree,node_delete,node_delete->left);
	}
	else{
		min_node=min_node_(node_delete->right);
		if(min_node->parent!=node_delete){
			trans_(tree,min_node,min_node->right);
			min_node->right=node_delete->right;
			min_node->right->parent=min_node;
		}
		trans_(tree,node_delete,min_node);
		min_node->left=node_delete->left;
		min_node->left->parent=min_node;
		
	}
	
	
	free(node_delete->data);
	free(node_delete);
}

main(){
	Tree *tree;
	tree=Init_tree();
	Elmt_tree *addr;
	int *data;
	int search_data; 
	int i=0;
	
	while(i<5){
		printf("input integer : ");
		data=(int*)malloc(sizeof(int));
		scanf("%d",data);
		insert_data(tree,data);
		
		i++;
	}
//	printf("%d",tree->root->right->data);
	print_data(tree->root);
	printf("input data to delete : ");
	scanf("%d",&search_data);
//	printf("qwer");
//	if(tree->root->data==search_data)printf("yes");
//	else printf("no");
	addr=search(tree->root,search_data);
	remove_data(addr,tree);
	print_data(tree->root);
	
}
