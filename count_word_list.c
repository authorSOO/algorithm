#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list{
	char *word;
	struct list *next;
	struct list *pre;
	int cnt;
}List;

static List *head;
static List *tail;

static void list_init(){
	head=NULL;
	tail=NULL;
}

static List *search_list(char *word){
	List *tr=head;
	while(tr){
		if(strcmp(tr->word,word)==0)return tr;
		tr=tr->next;	
	}
	return tr;
}
static List *create_(List *new_elmt,char *word){
	new_elmt=(List*)malloc(sizeof(List));
	new_elmt->cnt=0;
	new_elmt->next=NULL;
	new_elmt->pre=NULL;
	new_elmt->word=(char*)malloc(sizeof(char)*BUFSIZ);
	strcpy(new_elmt->word,word);
	return new_elmt;
}
void add_word_list_(char *word){
	List *new_elmt=search_list(word);
	if(!new_elmt){
		new_elmt=create_(new_elmt,word);
		if(head==NULL){
			head=new_elmt;
			tail=new_elmt;
		}
		else{
			new_elmt->pre=tail;
			tail->next=new_elmt;
			tail=new_elmt;
		}
		new_elmt->cnt++;
		
	}
	else new_elmt->cnt++;
	
	
}


void print_word_list(){
	List *tr=head;
	int cnt=0;
	while(tr){
		cnt++;
		printf("%s\t%d\n",tr->word,tr->cnt);
		tr=tr->next;
	}
	printf("รั : %d\n",cnt);
}
