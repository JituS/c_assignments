#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList linked_list;
	linked_list.head = NULL;
	linked_list.tail = NULL;
	linked_list.length= 0;
	return linked_list;
};

int add_to_list(LinkedList *list,void *element){
  Element *ele = (Element *)calloc(1,sizeof(Element));
  ele->value = element;
  if(list->length == 0){
    ele->index = 0;
    ele->next = NULL;
    list->head = ele;
    list->tail = ele;
  }else{
    ele->index = list->length;
    list->tail->next = ele;
    list->tail = ele;
  };
  list->length++;
  return list->length;
};

void *get_first_element(LinkedList list){
  return list.head->value;
};

void *get_last_element(LinkedList list){
 return list.tail->value;
};

void forEach(LinkedList list, ElementProcessor e){
  for(int i = 0; i < list.length; i++){
    e(list.head->value);
    list.head = list.head->next;
  };
};

void * getElementAt(LinkedList list, int index){
  Element *node = list.head;
  if(index < 0 || index > list.length - 1) return NULL;
  for(int i=0;i<index;i++){
    node = node->next;
  };
  return node->value;
};

int indexOf(LinkedList list, void *element){
  Element *node = list.head;
  for(int i=0;i<list.length;i++){
    if(node->value == element) return i;
    node = node->next;
  };  
  return -1;
};

void *deleteElementAt(LinkedList *list, int index){
  if(index > list->length || index < 0) return NULL;
  Element *element = list->head;
  Element *deletedElement;
  if(index == 0){
    deletedElement = list->head;
    list->head = list->head->next;
  }else{
    for(int i = 0;i < index - 1; i++){
      element = element->next;
    };
    if(index == list->length-1){
      deletedElement = element->next;
      list->tail = element;
    }else{
      deletedElement = element->next;
      element->next = element->next->next;
    }
  }
  list->length--;
  free(deletedElement);
  return deletedElement->value;
};

int asArray(LinkedList list, void **array, int maxElements){
  int limit = (maxElements < list.length) ? maxElements : list.length; 
  Element *node = list.head;
  for(int i = 0;i < limit; i++){
    array[i] = node->value;
    node = node->next;
  };
  return limit;
};

LinkedList filter(LinkedList list, MatchFunc match, void *hint){
  LinkedList filtered = createList();
  Element *node = list.head;
  for(int i=0; i<list.length; i++){
    if(match(hint, node->value))
      add_to_list(&filtered, node->value);
    node = node->next;
  };
  return filtered;
};

LinkedList reverse(LinkedList list){
  LinkedList reversed = createList();
  void *arrayUtil = calloc(8,list.length);
  void **array = arrayUtil;
  asArray(list, array, list.length);
  for(int i = list.length-1; i >= 0; i--){
    add_to_list(&reversed, array[i]);
  };
  return reversed;
};

LinkedList map(LinkedList list, ConvertFunc convert, void *hint){
  Element *element = list.head;
  LinkedList destination = createList();
  for(int i = 0; i < list.length; i++){
    void *ele;
    ele = (void *)malloc(8);
    convert(hint, element->value, ele);
    element = element->next;
    add_to_list(&destination, ele);
  };
  return destination;
};


void *reduce(LinkedList list, Reducer reduce, void *hint, void *initialValue){
  Element *element = list.head;
  for(int i = 0; i < list.length; i++){
    initialValue = reduce(hint, initialValue, element->value);
    element = element->next;
  };
  return initialValue;
};


