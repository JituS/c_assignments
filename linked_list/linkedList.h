typedef struct element{
    void *value;
    int index;
    struct element *next;
} Element;

typedef struct{
	Element *head;
	Element *tail;
	int length;
} LinkedList;
typedef void (*ElementProcessor)(void *item);
LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);
void * getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *,int);
