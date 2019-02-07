
typedef struct element{
	void *data;
	struct element *pre;
	struct element *next;
}Element;

typedef struct list{
	Element *head;
	Element *tail;
	int size;
}List;

