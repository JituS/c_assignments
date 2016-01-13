#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <assert.h>

void test_createList(void){
	LinkedList list = createList();
  assert(list.head == NULL);
  assert(list.tail == NULL);
  assert(list.length == 0);
};

void test_add_to_list(void){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  *a = 1;
  *b = 2;
  *c = 3;
  assert(add_to_list(&list, a)==1);
  assert(add_to_list(&list, b)==2);
  assert(add_to_list(&list, c)==3);
  assert(list.length == 3);
  assert(*(int *)list.head->value == 1);
  assert(*(int *)list.tail->value == 3);
  assert(*(int *)list.head->next->value == 2);
  assert(list.tail->next==NULL);
};

void test_add_to_list_char(void){
  LinkedList list = createList();
  char *a = (char *)malloc(sizeof(char));
  char *b = (char *)malloc(sizeof(char));
  char *c = (char *)malloc(sizeof(char));
  *a='a';
  *b='b';
  *c='c';
  assert(add_to_list(&list, a)==1);
  assert(add_to_list(&list, b)==2);
  assert(add_to_list(&list, c)==3);
  assert(list.length == 3);
  assert(*(char *)list.head->value == 'a');
  assert(*(char *)list.tail->value == 'c');
  assert(*(char *)list.head->next->value == 'b');
  assert(list.tail->next==NULL);
};

void test_get_first_element(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  *a=1;
  *b=2;
  *c=3;
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  assert(*(int *)get_first_element(list)==1);
};

void test_get_first_element_char(){
  LinkedList list = createList();
  char *a = (char *)malloc(sizeof(char));
  char *b = (char *)malloc(sizeof(char));
  char *c = (char *)malloc(sizeof(char));
  *a='a';
  *b='b';
  *c='c';
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  assert(*(char *)get_first_element(list)=='a');
};

void test_get_last_element(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  *a=1;
  *b=2;
  *c=3;
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  assert(*(int *)get_last_element(list)==3);
};

void test_get_last_element_char(){
  LinkedList list = createList();
  char *a = (char *)malloc(sizeof(char));
  char *b = (char *)malloc(sizeof(char));
  char *c = (char *)malloc(sizeof(char));
  *a='a';
  *b='b';
  *c='c';
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  assert(*(char *)get_last_element(list)=='c');
};

void increment(void *item){
  *(int *)item = *(int *)item + 1;
};

void test_forEach(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  *a=1;
  *b=2;
  *c=3;
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  forEach(list, &increment);
  assert(*(int *)list.head->value == 2);
  assert(*(int *)list.tail->value == 4);
  assert(list.length == 3);
};

void test_getElementAt(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  *a=1;
  *b=2;
  *c=3;
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  assert(*(int *)getElementAt(list,1) == 2);
  assert(*(int *)getElementAt(list,0) == 1);
  assert(*(int *)getElementAt(list,2) == 3);
  assert(getElementAt(list,3) == 0);
};

void test_indexOf(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  int *d = (int *)malloc(sizeof(int));
  *a=19;
  *b=20;
  *c=24;
  *d=24243;

  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);

  assert(indexOf(list,c) == 2);
  assert(indexOf(list,a) == 0);
  assert(indexOf(list,b) == 1);
  assert(indexOf(list,d) == -1);
};

void test_deleteElementAt(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  int *d = (int *)malloc(sizeof(int));
  int *e = (int *)malloc(sizeof(int));
  *a=19;
  *b=20;
  *c=24;
  *d=9;
  *e=2;
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  add_to_list(&list, d);
  add_to_list(&list, e);
  assert(*(int *)deleteElementAt(&list, 0) == 19);
  assert(*(int *)deleteElementAt(&list, 3) == 2);
  assert(*(int *)deleteElementAt(&list, 0) == 20);
  assert(*(int *)deleteElementAt(&list, 0) == 24);
  assert(*(int *)list.head->value == 9);
  assert(*(int *)list.tail->value == 9);
  assert(list.length == 1);
};

int main(void){
  test_createList();
  test_add_to_list();
  test_add_to_list_char();
  test_get_first_element();
  test_get_first_element_char();
  test_get_last_element();
  test_get_last_element_char();
  test_forEach();
  test_getElementAt();
  test_indexOf();
  test_deleteElementAt();
};
