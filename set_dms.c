#include "set_h.h"


int print_menu(){
	printf("========MENU========\n");
	printf("1.INSERT DATA TO GROUP A\n");
	printf("2.INSERT DATA TO GROUP B\n");
	printf("3.INTERSECTION SET\n");
	printf("4.UNION SET\n");
	printf("5.DIFFERENCE SET\n");
	printf("6.PRINT GROUP\n");
	printf("0.exit\n");
	printf("\nINPUT NUMBER : ");
	int input;
	scanf("%d",&input);
	return input;
}

main(){
	List_A list_a;
	List_B list_b;
	List_C list_c;
//	List_Group list_group;
		
	int input;
	
//	if(Init_group(&list_group)!=0); 


	
	Init_group(&list_a,&list_b,&list_c);//초기화 
		
	while(1){
		input=print_menu();
		if(input>7||input<0)return;
	//	printf("%d\n",list_a.size);
		switch(input){	
					//(그룹a,그룹b,그룹c, c의 data) 
			case 1:	if(Insert_data(&list_a,NULL,NULL,NULL)!=0)return;break;
			case 2:	if(Insert_data(NULL,&list_b,NULL,NULL)!=0)return;break;
			
			case 3:	Init_group(NULL,NULL,&list_c);
					if(Intersection(&list_a,&list_b,&list_c)!=0)return;
					break;
			
			case 4:	Init_group(NULL,NULL,&list_c);
					if(Union(&list_a,&list_b,&list_c)!=0)return;
					break;
					
			case 5:	Init_group(NULL,NULL,&list_c);
					if(Diff(&list_a,&list_b,&list_c)!=0)return;break;
					
			case 6:if(Print_data(&list_a,&list_b,&list_c)!=0)return;break;
			case 0:return;
			default : printf("INPUT AGAIN\n\n");break;
				
		}
		
		
		
	}
	
	
}


