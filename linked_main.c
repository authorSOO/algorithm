#include "linked_list.c"

int main(){
	List list;
	List_Init(&list);
	Element *addr;
	int *data;
	int *insert_data;
	int *i;
	while(1){
		int result=print_menu();
		switch(result){
			case 1:	printf("INPUT THE DATA : ");	
					if(!(data=(int*)malloc(sizeof(int))));
					memset(data,0,sizeof(data));		
					scanf("%d",data);
					Insert_node(&list,NULL,data);
					break;	
									
			case 2:	Print_node(&list); printf("\nWHITCH OF PLACE INSERT TO DATA PRE :");
					if(!(data=(int*)malloc(sizeof(int))))return -1;
					memset(data,0,sizeof(data));			
					scanf("%d",data);
					i=(int*)malloc(sizeof(int));
					if((addr=Find_node(&list,data,i))==NULL){
						free(data);free(i);break;
					}
					printf("\nINPUT TO THE DATA\n");
					if(!(insert_data=(int*)malloc(sizeof(int))))return -1;
					memset(data,0,sizeof(insert_data));			
					scanf("%d",insert_data);
					if(addr==list.head){
						Element *new_element=(Element*)malloc(sizeof(Element));
						new_element->data = (void *)insert_data;
						new_element->pre=NULL;
						new_element->next=addr;
						list.head=new_element;
					}
					else Insert_node(&list,addr->pre,insert_data);
					free(i);free(data);
					break;		
					
			case 3: Print_node(&list);printf("\nWHITCH OF PLACE INSERT TO DATA NEXT :");
					if(!(data=(int*)malloc(sizeof(int))))return -1;
					memset(data,0,sizeof(data));			
					scanf("%d",data);
					i=(int*)malloc(sizeof(int));
					if((addr=Find_node(&list,data,i))==NULL){
						free(data);free(i);break;
					}
					printf("\nINPUT TO THE DATA\n");
					if(!(insert_data=(int*)malloc(sizeof(int))))return -1;
					memset(data,0,sizeof(insert_data));			
					scanf("%d",insert_data);
					Insert_node(&list,addr,insert_data);
					free(i);free(data);
					break;			
							
			case 4: Print_node(&list);printf("\nINPUT THE DATA TO DELETE : ");
					if(!(data=(int*)malloc(sizeof(int))))return -1;
					memset(data,0,sizeof(data));			
					scanf("%d",data);
					i=(int*)malloc(sizeof(int));
					if((addr=Find_node(&list,data,i))==NULL){
						free(data);free(i);break;
					}
					Delete_node(&list,addr);					
					free(i);free(data);
					break;
					
			case 5: while(list.head){
						Delete_node(&list,list.head);
					}
										
					break;
			
			case 6: printf("\nINPUT THE DATA TO FIND : ");	
					if(!(data=(int*)malloc(sizeof(int))))return -1;
					memset(data,0,sizeof(data));			
					scanf("%d",data);
					i=(int*)malloc(sizeof(int));
					if((addr=Find_node(&list,data,i))==NULL){
						free(data);free(i);break;
					}
					else printf("%dth.EXIST\n",*i);
					free(i);free(data);
					break;	
			case 7: Print_node(&list);break;
			case 0: return -1;
		}	
	}
}

