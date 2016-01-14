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

typedef int MatchFunc(void* hint, void* item);
typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);
typedef void *Reducer(void* hint, void* previousItem, void* item);

typedef void (*ElementProcessor)(void *item);
LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);
void * getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *,int);
int asArray(LinkedList, void **, int maxElements);
LinkedList filter(LinkedList, MatchFunc, void *hint);
LinkedList reverse(LinkedList list);
LinkedList map(LinkedList, ConvertFunc, void * );
void *reduce(LinkedList, Reducer, void *hint, void *initialValue);
