#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

int print_menu(void){
	int num;
	printf("\n\nDouble Linked List Menu\n");
	printf("1. Insert Node\n");
	printf("2. Insert prev node\n");
	printf("3. Insert next node\n");
	printf("4. Delete node\n");
	printf("5. Delete All node\n");
	printf("6. Find node\n");
	printf("7. Print all node\n");
	printf("0. Exit\n");
	printf("INPUT THE NUMBER : ");
	scanf("%d",&num);
	
	return num;
}

void List_Init(List *list){
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
}

void Insert_node(List *list,Element *insert_element,void *data){
	Element *new_element;
	new_element=(Element*)malloc(sizeof(Element));
	new_element->data=(void *)data;
	
	if(insert_element){
		new_element->pre=insert_element;
		new_element->next=insert_element->next;
		if(insert_element!=list->tail)insert_element->next->pre=new_element;
		insert_element->next=new_element;
	}	
	else{
			
	if(list->size==0){
		new_element->next=NULL;
		new_element->pre=NULL;
		list->head=new_element;
		list->tail=new_element;
	}
	else {
		new_element->next=NULL;
		new_element->pre=list->tail;
		new_element->pre->next=new_element;
		list->tail=new_element;
		}
	}
	list->size++;
}

void Print_node(List *list){
	Element *tr=list->head;
	int i=0;
	while(tr){
		printf("[%2d]%d\n",++i,*(int *)tr->data);
		tr=tr->next;
	}
}

Element *Find_node(List *list,void *data,int *i){
	Element *tr=list->head;
	*i=1;
	while(tr){
		if(*(int *)(tr->data)==*(int *)data) {
			return tr;
		}
		else {
			*i=*i+1;tr=tr->next;
		}
	}
	return NULL;
}

void Delete_node(List *list,Element *addr){
	if(addr==list->head){
		list->head=addr->next;
	}
	else addr->pre->next=addr->next;
	if(addr==list->tail){
		list->tail=addr->pre;
	}
	else addr->next->pre=addr->pre;
	free(addr->data);
	free(addr);
	list->size--;
}

