#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct group_A{
	int *data;
	struct group_A *next;
}Group_A;

typedef struct group_B{
	int *data;
	struct group_B *next;
}Group_B;

typedef struct group_C{
	int *data;
	struct group_C *next;
}Group_C;

typedef struct list_A{
	Group_A *head;
	Group_A *tail;
	int size;
}List_A;

typedef struct list_B{
	Group_B *head;
	Group_B *tail;
	int size;
}List_B;

typedef struct list_C{
	Group_C *head;
	Group_C *tail;
	int size;
}List_C;

typedef struct list_group{
	List_A list_a;
	List_B list_b;
	List_C list_c;	
}List_Group;

/*
//헤드테일 초기화 (전체초기,..) 
int Init_group(List_Group *list_group){
	list_group->list_a.head=NULL;
	list_group->list_b.head=NULL;
	list_group->list_c.head=NULL;
	list_group->list_a.tail=NULL;
	list_group->list_b.tail=NULL;
	list_group->list_c.tail=NULL;
	list_group->list_a.size=0;
	list_group->list_b.size=0;
	list_group->list_c.size=0;
	return 0;
}*/

int Init_group(List_A *list_a,List_B *list_b,List_C *list_c){
	if(list_a){
		list_a->head=NULL;
		list_a->tail=NULL;
		list_a->size=0;
	}
	if(list_b){
	
	list_b->head=NULL;
	list_b->tail=NULL;
	list_b->size=0;
	}
	
	if(list_c){
	list_c->head=NULL;
	list_c->tail=NULL;
	list_c->size=0;
	}
	return 0;
}

	//인서트 (그룹a,그룹b,그룹c, c의 data) 
int Insert_data(List_A *list_a,List_B *list_b,List_C *list_c,int *data_c){
	if(list_c)goto go;
	
	int *data;
	data=(int*)malloc(sizeof(int));
	
	printf("\ninput the data to insert in : ");	
	scanf("%d",data);
	go:
//	printf("check\n");
	if(list_a){
		Group_A *new_element;
		new_element = (Group_A*)malloc(sizeof(Group_A));
		new_element->data=data;
		
		if(list_a->size==0){
			list_a->head=new_element;
			list_a->tail=new_element;
			list_a->tail->next=NULL;
		}
		
		else{
			list_a->tail->next=new_element;
			list_a->tail=new_element;
			new_element->next=NULL;
			
		}
	//	printf("%d\n",list_a->size);
		list_a->size++;
	//	printf("%d\n",list_b->size);
		return 0;
	}

	
	else if(list_b){
		
		Group_B *new_element;
		
		new_element = (Group_B*)malloc(sizeof(Group_B));
		new_element->data=data;
	//	printf("%d\n",list_b->size);
		if(list_b->size==0){
			list_b->head=new_element;
			list_b->tail=new_element;
			list_b->tail->next=NULL;
		}
		
		else{
			list_b->tail->next=new_element;
			list_b->tail=new_element;
			new_element->next=NULL;
			
		}
		
		list_b->size++;
		return 0;
	} 
	
	else if(list_c){

		Group_C *new_element;
		
		new_element = (Group_C*)malloc(sizeof(Group_C));
		new_element->data=data_c;
	//	printf("%d\n",list_b->size);
		if(list_c->size==0){
			list_c->head=new_element;
			list_c->tail=new_element;
			list_c->tail->next=NULL;
		}
		
		else{
			list_c->tail->next=new_element;
			list_c->tail=new_element;
			new_element->next=NULL;
			
		}
		
		list_c->size++;
		return 0;
	} 
	
	return 0;

} 

int Print_data(List_A *list_a,List_B *list_b,List_C *list_c){
	int cnt=0;
	//A출력 
	printf("====<A GROUP>====\n");
	if(list_a->head){
		Group_A *tr=list_a->head;
		while(1){
			printf("[%d]%2d\n",++cnt,*(tr->data));
			tr=tr->next;
			if(!tr)break;
		}
	
	}
	else printf("LIST A is empty\n");
	//B출력 
	printf("====<B GROUP>====\n");
	cnt=0;
	if(list_b->head){
		Group_B *tr=list_b->head;
		while(1){
			printf("[%d]%2d\n",++cnt,*(tr->data));
			tr=tr->next;
			if(!tr)break;
		}
	
	}
	else printf("LIST B is empty\n");
	//C출력 
	printf("====<C GROUP>====\n");
	cnt=0;
	if(list_c->head){
		Group_C *tr=list_c->head;
		while(1){
			printf("[%d]%2d\n",++cnt,*(tr->data));
			tr=tr->next;
			if(!tr)break;
		}
	
	}
	else printf("LIST C is empty\n");

	
	return 0;
}

int Diff(List_A *list_a,List_B *list_b,List_C *list_c){
	Group_A *tr_a=list_a->head;
	Group_B *tr_b=list_b->head;
	int j,flap;
	
	
	while(1){
		flap=0;
		for(j=0;j<list_b->size;j++){
			if(*tr_a->data!=*tr_b->data){
				flap=1;
			}
		}
		if(flap==1){
			Insert_data(NULL,NULL,list_c,tr_a->data);
		}
		tr_a=tr_a->next;
		if(!tr_a)break;
	
	}	
	printf("DIFF IS COMPLETED\n");
	
	
	
	return 0;
}

 
int Union(List_A *list_a, List_B *list_b, List_C *list_c){
	Group_A *tr_a=list_a->head;
	Group_B *tr_b=list_b->head;
	int j,flap;
	
	
	while(1){
		flap=0;
		for(j=0;j<list_b->size;j++){
			if(*tr_a->data!=*tr_b->data){
				flap=1;
			}
		}
		if(flap==1){
			Insert_data(NULL,NULL,list_c,tr_a->data);
		}
		tr_a=tr_a->next;
		if(!tr_a)break;
	
	}
	tr_b=list_b->head;
	while(1){
		Insert_data(NULL,NULL,list_c,tr_b->data);
		tr_b=tr_b->next;
		if(!tr_b)break;
	}
	
	printf("UNION IS COMPLETED\n");
	
	return 0;
}
 
int Intersection(List_A *list_a, List_B *list_b, List_C *list_c){
	Group_A *tr_a=list_a->head;
	Group_B *tr_b=list_b->head;
	int j;
	

	while(1){
	
		for(j=0;j<list_b->size;j++){
			if(*tr_a->data==*tr_b->data){
	//			printf("c\n");
				Insert_data(NULL,NULL,list_c,tr_a->data);
			}
			tr_b=tr_b->next;
			if(!tr_b)goto go;
		}
		printf("888\n");
		tr_a=tr_a->next;
		if(!tr_a)break;
		printf("888\n");
	}
	go:
	printf("INTERSECTION IS COMPLETED\n");
	return 0;
}
