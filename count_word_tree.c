#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treenode{
	struct treenode *left;
	struct treenode *right;
	struct treenode *parent;
	char *word;
	int cnt;
}Treenode;

static Treenode *root;


static void tree_init(){
	root=NULL;
}

static Treenode *create_node(char *word){
	Treenode *new_node;
	new_node=(Treenode*)malloc(sizeof(Treenode));
	
	new_node->cnt=0;
	new_node->left=NULL;
	new_node->right=NULL;
	new_node->parent=NULL;
	new_node->word=(char*)malloc(sizeof(char)*BUFSIZ);
	strcpy(new_node->word,word);
	
	return new_node;
}

static Treenode *search_node_(char *word){
	Treenode *tr=root;
	
	while(tr){
		if(strcmp(tr->word,word)==0)return tr;
		else if(strcmp(tr->word,word)<0)tr=tr->right;
		else tr=tr->left;
	}
	
	return tr;	
}

static void add_word_tree_(char *word){
	Treenode *tr=search_node_(word);
//	printf("asdf");
	
	if(!tr){
	
		Treenode *tmp=NULL;
		Treenode *parent_node=root;
		Treenode *new_node;
		new_node=create_node(word);
		
		while(parent_node){
			tmp=parent_node;
			if(strcmp(parent_node->word,word)<0)parent_node=parent_node->right;
			else parent_node=parent_node->left;
		}
		
		new_node->parent=tmp;
		
		if(tmp==NULL) root=new_node;
		else if(strcmp(new_node->word,tmp->word)<0) tmp->left=new_node;
		else tmp->right=new_node;
		
		new_node->cnt++;		
	}
		
	else{
		tr->cnt++;
	}
			
}



static void print_tree_node(Treenode *node,int *cnt){
	if(!node)return;
	print_tree_node(node->left,cnt);
	printf("%s\t%d\n",node->word,node->cnt);
	++(*cnt);
	print_tree_node(node->right,cnt);	
}

static void print_word_tree(){
	int cnt=0;
	print_tree_node(root,&cnt);
	printf(">>>ÃÑ ´Ü¾î °³¼ö : %d",cnt);
}

