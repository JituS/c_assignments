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
    ele->index = list->tail->index++;
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
  if(index < 0 || index > list.length - 1) return NULL;
  for(int i=0;i<index;i++){
    list.head = list.head->next;
  };
  return list.head->value;
};

int indexOf(LinkedList list, void *element){
  for(int i=0;i<list.length;i++){
    if(list.head->value == element) return i;
    list.head = list.head->next;
  };  
  return -1;
};
void * deleteElementAt(LinkedList *list, int index){
  if(index > list->length || index < 0) return NULL;
  Element *element = list->head;
  Element *deletedElement;
  if(index == 0) {
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
