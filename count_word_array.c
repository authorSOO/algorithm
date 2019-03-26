#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORDS 1000000
typedef struct array{
	char *word;
	int cnt;
}Array;

static Array array[MAXWORDS];
static int cnt=0;

static int search_(char *word){
	int i,flap;
	flap=0;
	for(i=0;i<cnt;i++){
		if(strcmp(array[i].word,word)==0){
			flap=1;
			break;
		}
	}
	if(flap==0)return-1;
	else return i;
}

void add_word_array_(char *word){
	int index=search_(word);
	if(index<0){
		array[cnt].word=(char*)malloc(sizeof(char)*BUFSIZ);
		strcpy(array[cnt].word,word);
		array[cnt].cnt=1;
		cnt++;
	}
	else array[index].cnt++;
	
}

void print_word_array(){
	int i;
	for(i=0;i<cnt;i++){
		printf("%s\t%d\n",array[i].word,array[i].cnt);
	}
	printf(">>ÃÑ %d°³\n",cnt);
}

