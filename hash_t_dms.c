#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListElmt_ {

void               *data;
struct ListElmt_   *next;
struct ListElmt_	*pre;
} ListElmt;

typedef struct List_ {

int                size;

//int                (*match)(const void *key1, const void *key2);
//void               (*destroy)(void *data);

ListElmt           *head;
ListElmt           *tail;

} List;

typedef struct CHTbl_ {

int                buckets;

int                (*h)(const void *key);
//int                (*match)(const void *key1, const void *key2);
//void               (*destroy)(void *data);

int                size;
List               *table;

} CHTbl;

void list_init(List *list){
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
}

void Init_(CHTbl *Tb,int bucket,int (*h)(const void *data)){
	int i;
	Tb->table=(List*)malloc(bucket*sizeof(List));
	Tb->buckets=bucket;
	Tb->h=h;
	Tb->size=0;
	for(i=0;i<Tb->buckets;i++){
		list_init(Tb->table+i);
	}
}
void Insert_table(List *list,void *data){
	
	ListElmt *new_elmt;
	new_elmt=(ListElmt*)malloc(sizeof(ListElmt));
	new_elmt->data=(void *)data;
	
	if(list->size==0){
		list->head=new_elmt;
		list->tail=new_elmt;
		list->tail->next=NULL;
		list->tail->pre=NULL;
	}
	else{
		list->tail->next=new_elmt;
		new_elmt->pre=list->tail;
		list->tail=new_elmt;
		new_elmt->next=NULL;
	}
	
	list->size++;
	
}

void Insert_data_(CHTbl *Tb,void *data){
	int index;
	index=Tb->h(data);
	
	Insert_table(&Tb->table[index],data);//
	printf("BUCKET %d에 입력\n",index+1);
}
print_menu_(){
	printf("1. INSERT\n");
	printf("2. FIND\n");
	printf("3. PRINT\n");
}
int print_bucket(int bucket){
	printf("select\n");
	int i=0;
	while(i++<bucket){
		printf("[no.%d] ",i);
	}
	int input;
	scanf("%d",&input);
	return input;
}
void print_data(CHTbl *Tb,int index){
	ListElmt *tr=Tb->table[index].head;
	int i;
	if(Tb->table[index].size==0){
		printf("NOTHING\n");return;
	}
	
	//i=0;
	
	while(tr){
//		printf("check\n");
		printf("[%d]->%d\n",++i,*(int *)tr->data);
		tr=tr->next;
	}
}

void find_data_(CHTbl *Tb,int index,int data){
	int i,flap=0;
	while(i++<index){
		ListElmt *tr=Tb->table[i].head;
		printf("[%d번 bucket에]",i);
		flap=0;
		while(tr){
			if(*(int *)(tr->data)==data){
				flap++;
			}
			tr=tr->next;
		}
		printf("%d개있음\n",flap);
		printf("\n");
	}
}

main(){
	CHTbl Tb;
	
	printf("input num of buckets : ");
	int bucket;
	scanf("%d",&bucket);
	int *data;
	
		
	int h(const void *data){
		return (*(int *)data)%bucket;
	}
	Init_(&Tb,bucket,h);
	int num,bucket_num;
	int find_data;
	while(1){
	
		print_menu_();
		printf(">>select :");
		scanf("%d",&num);
		switch(num){
			case 1 :
					data=(int*)malloc(sizeof(int));
					printf("INPUT DATA : ");
					scanf("%d",data);
					Insert_data_(&Tb,data);
					break;
				
			case 2 :printf("찾을데이터입력 : ");
					scanf("%d",&find_data); 
					find_data_(&Tb,bucket-1,find_data);
					break;
					
			case 3 : bucket_num=print_bucket(bucket);
					 print_data(&Tb,bucket_num-1);
					 break;
		}
	
	}
	
}


