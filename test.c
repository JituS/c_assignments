#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lib.h"

void test_create(){
	int length = 6;
	int typeSize = 1;
	ArrayUtil array = create(typeSize,length);
	int *base = (int *)array.base;
	base[0] = 1;
	base[1] = 2;
	assert(base[0]==1);
	assert(base[1]==2);
	assert(base[2]==0);
	assert(array.length==6);
};

void test_areEqual(){
	int length = 2;
	int typeSize = 4;
	ArrayUtil array1 = create(typeSize,length);
	int *array1_base = (int *)array1.base;
	array1_base[0] = 1;
	array1_base[1] = 2;

	ArrayUtil array2 = create(typeSize,length);
	int *array2_base = (int *)array2.base;
	array2_base[0] = 1;
	array2_base[1] = 2;
	assert(areEqual(array1,array2));
};	

void test_resize(){
	int length = 3;
	int typeSize = 4;
	ArrayUtil array1 = create(typeSize,length);
	int *array1_base = (int *)array1.base;
	array1_base[0] = 1;
	array1_base[1] = 2;
	array1_base[2] = 3;
	ArrayUtil resized = resize(array1, 2);
	assert(resized.length == 2);
	int *base = resized.base;
	assert(base[0] == 1);
	assert(base[1] == 2);
	assert(base[2] == 0);
};

void test_findIndex(){
	int length = 6;
	int typeSize = 4;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 1;
	array1_base[1] = 3;
	array1_base[2] = 2;
	array1_base[5] = 1024;
	int x = 1;
	int y = 3;
	int z = 2;
	int l = 8;
	int p = 1024;
	assert(findIndex(array,&x) == 0);
	assert(findIndex(array,&y) == 1);
	assert(findIndex(array,&z) == 2);
	assert(findIndex(array,&l) == -1);
	assert(findIndex(array,&p) == 5);
};

void test_dispose(){
	int length = 6;
	int typeSize = 4;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 1;
	array1_base[1] = 3;
	array1_base[2] = 2;
	array1_base[5] = 1024;
	dispose(array);
};

int isDivisible(void *hint, void *item){
  int *hint_ = (int *)hint;  
  int *item_ = (int *)item;
  if(*item_ == 0) return 0;
  return (*item_ % *hint_ == 0);   
};  

void test_findFirst(){
	int length = 6;
	int typeSize = 4;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 3;
	array1_base[1] = 3;
	array1_base[2] = 6;
	array1_base[3] = 8;
	int hint = 8, *x;
	x = (int *)findFirst(array, &isDivisible, &hint);
	assert(*x == 8);
	hint = 3;
	x = (int *)findFirst(array, &isDivisible, &hint);
	assert(*x == 3);
	hint = 2;
	x = (int *)findFirst(array, &isDivisible, &hint);
	assert(*x == 6);
	hint = 5;
	x = findFirst(array, &isDivisible, &hint);
	assert(x == NULL);
};

void test_findLast(){
	int length = 6;
	int typeSize = 4;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 3;
	array1_base[1] = 9;
	array1_base[2] = 6;
	array1_base[3] = 8;
	int hint = 8, *x;
	x = (int *)findLast(array, &isDivisible, &hint);
	assert(*x == 8);
	hint = 3;
	x = (int *)findLast(array, &isDivisible, &hint);
	assert(*x == 6);
	hint = 2;
	x = (int *)findLast(array, &isDivisible, &hint);
	assert(*x == 8);
	hint = 5;
	x = findLast(array, &isDivisible, &hint);
	assert(x == NULL);

}

void test_count(){
	int length = 6;
	int typeSize = 4;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 3;
	array1_base[1] = 9;
	array1_base[2] = 6;
	array1_base[3] = 8;
	int hint = 8, x;
	x = (int)count(array, &isDivisible, &hint);
	assert(x == 1);
	hint = 3;
	x = (int)count(array, &isDivisible, &hint);
	assert(x == 3);
	hint = 2;
	x = (int)count(array, &isDivisible, &hint);
	assert(x == 2);
	hint = 5;
	x = count(array, &isDivisible, &hint);
	assert(x == 0);
}

void test_filter(){
	int length = 7;
	int typeSize = 4;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 6;
	array1_base[1] = 12;
	array1_base[2] = 9;
	array1_base[3] = 33;
	array1_base[4] = 31;
	array1_base[5] = 30;
	array1_base[6] = 30;
	ArrayUtil destination = create(8,7);
  void **desBase = destination.base;
	int hint = 3;
	filter(array, &isDivisible, &hint,desBase,7);
	int **a = (int **)desBase;
  assert(*a[0] == 6);
  assert(*a[1] == 12);
  assert(*a[2] == 9);
  assert(*a[3] == 33);
  assert(*a[4] == 30);
};

void  multiply(void *hint, void *sourceItem, void *destinationItem){
  int *source = (int *)sourceItem;
  int *dest = (int *)destinationItem;
  *dest = *source * *(int *)hint;
};

void test_map(){
	int length = 4;
	int typeSize = 4;
	ArrayUtil source = create(typeSize,length);
	ArrayUtil destination = create(typeSize,length);
  int *s_base = (int *)source.base;
  int *d_base = (int *)destination.base;
	s_base[0] = 6;
	s_base[1] = 1;
	s_base[2] = 9;
	s_base[3] = 3;
  int hint = 2;
  map(source, destination, &multiply, &hint);
  assert(d_base[0] == 12);
  assert(d_base[1] == 2);
  assert(d_base[2] == 18);
  assert(d_base[3] == 6);
};  

void  add1(void *hint, void *item){
  int *item_ = (int *)item;
  int *hint_ = (int *)hint;
  *item_ = *item_ + *hint_;
};

void test_forEach(){
	int length = 4;
	int typeSize = 4;
	ArrayUtil util = create(typeSize,length);
  int *u_base = (int *)util.base;
	u_base[0] = 6;
	u_base[1] = 1;
	u_base[2] = 9;
	u_base[3] = 3;
  int hint = 1;
  forEach(util, &add1, &hint);
  assert(u_base[0] == 7);
  assert(u_base[1] == 2);
  assert(u_base[2] == 10);
  assert(u_base[3] == 4);
};

void* addAll(void* hint, void* previousItem, void* item){
  int *previousItem_ = (int *)previousItem;
  int *item_ = (int *)item;
  *previousItem_ = *previousItem_ + *item_;
  return previousItem_;
};

void test_reduce(){
	int length = 4;
	int typeSize = 4;
	ArrayUtil util = create(typeSize,length);
  int *u_base = (int *)util.base;
	u_base[0] = 6;
	u_base[1] = 1;
	u_base[2] = 9;
	u_base[3] = 3;
  int hint = 1;
  int a = 0;
  int *out = (int *)reduce(util, &addAll, &hint, &a);
  assert(*out == 19);
};

int main(void)
  {
    test_create();
    test_areEqual();
    test_resize();
    test_findIndex();
    test_dispose();
    test_findFirst();
    test_findLast();
    test_count();
    test_filter();
    test_map();
    test_forEach();
    test_reduce();
    return 0;
  }
