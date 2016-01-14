#include <stdio.h>
#include <string.h>
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

void test_add_to_list_struct(void){
  LinkedList list = createList();
  Students jitu;
  Students minni;
  strcpy(jitu.name,"jitu");
  strcpy(minni.name,"minni");
  jitu.std = 8;
  minni.std = 8;
  assert(add_to_list(&list, &jitu)==1);
  assert(add_to_list(&list, &minni)==2);
  assert(list.length == 2);
  assert(list.head->value == &jitu);
  assert(list.tail->value == &minni);
  assert(list.head->next->value == &minni);
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

void test_deleteElementAtChar(){
  LinkedList list = createList();
  char *a = (char *)malloc(sizeof(char));
  char *b = (char *)malloc(sizeof(char));
  char *c = (char *)malloc(sizeof(char));
  char *d = (char *)malloc(sizeof(char));
  char *e = (char *)malloc(sizeof(char));
  *a='a';
  *b='b';
  *c='c';
  *d='e';
  *e='f';
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  add_to_list(&list, d);
  add_to_list(&list, e);
  assert(*(char *)deleteElementAt(&list, 0) == 'a');
  assert(*(char *)deleteElementAt(&list, 3) == 'f');
  assert(*(char *)deleteElementAt(&list, 0) == 'b');
  assert(*(char *)deleteElementAt(&list, 0) == 'c');
  assert((char *)deleteElementAt(&list, 3) == NULL);
  assert(*(char *)list.head->value == 'e');
  assert(*(char *)list.tail->value == 'e');
  assert(*(char *)deleteElementAt(&list, 0) == 'e');
  add_to_list(&list, a);
  assert(list.length == 1);
};

void test_asArray(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  int *d = (int *)malloc(sizeof(int));
  int *e = (int *)malloc(sizeof(int));
  char *f = (char *)malloc(sizeof(int));
  *a=19;
  *b=20;
  *c=24;
  *d=9;
  *e=2;
  *f='a';
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  add_to_list(&list, d);
  add_to_list(&list, e);
  add_to_list(&list, f);
  void *arrayUtil = calloc(8,6);
  void **array = arrayUtil;
  assert(asArray(list, array, 7) == 6);
  int **p = (int **)array;
  assert(p[0] == a);
  assert(p[1] == b);
  assert(p[2] == c);
  assert(p[3] == d);
  assert(p[4] == e);
};


int divisibleByHint(void *hint, void *item){
  return  *(int *)item % *(int *)hint == 0;
};

void test_filter(){
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
  int hint = 2;
  LinkedList filtered = filter(list, &divisibleByHint, &hint);
  assert(*(int *)filtered.head->value == 20);
  assert(*(int *)filtered.head->next->value == 24);
  assert(*(int *)filtered.tail->value == 2);
  assert(filtered.length == 3);
};

void test_reverse(){
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
  LinkedList reversed = reverse(list);
  assert(reversed.head->value == list.tail->value);
  assert(reversed.tail->value == list.head->value);
  assert(reversed.head->next->value == d);
  assert(list.head->value == a);
  assert(reversed.length == 5);
  assert(list.length == 5);
};

void addHint(void* hint, void* sourceItem, void* destinationItem){
  *(int *)destinationItem = *(int *)sourceItem + *(int *)hint;
};

void test_map(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  int *d = (int *)malloc(sizeof(int));
  *a=19;
  *b=20;
  *c=24;
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  LinkedList l = list;
  int hint = 2;
  LinkedList mapped = map(list, &addHint, &hint);
  assert(*(int *)mapped.head->value == 21);
  assert(*(int *)mapped.head->next->value == 22);
  assert(*(int *)mapped.tail->value == 26);
  assert(mapped.length == 3);
};

void *mutiplyAll(void* hint, void* previousItem, void* item){ 
  *(int *)item = *(int *)item * *(int *)previousItem;
  return item;
};

void test_reduce(){
  LinkedList list = createList();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  int *d = (int *)malloc(sizeof(int));
  *a = 2;
  *b = 2;
  *c = 2;
  *d = 2;
  add_to_list(&list, a);
  add_to_list(&list, b);
  add_to_list(&list, c);
  add_to_list(&list, d);
  int hint = 1;
  int redusedValue = *(int *)reduce(list, &mutiplyAll, &hint, &hint);
  assert(redusedValue == 16);
};

int main(void){
  test_add_to_list_struct();
};

