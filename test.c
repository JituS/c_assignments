#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lib.h"

void createTest(){
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

void areEqualTest(){
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

void resizeTest(){
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

void findIndexTest(){
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

void disposeTest(){
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

void findFirstTest(){
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

void findLastTest(){
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

void countTest(){
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

void filterTest(){
	int length = 6;
	int typeSize = 8;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 12012;
	array1_base[1] = 12;
	array1_base[2] = 9;
	array1_base[3] = 33;
	ArrayUtil destination = create(4,length);
	int hint = 3, x;
	x = (int)filter(array, &isDivisible, &hint,&(destination.base),length);
	int **a = (int **)&(destination.base);
	printf("%d\n",*a[0]);
	printf("%d\n",*a[1]);
	printf("%d\n",*a[2]);
	printf("%d\n",*a[3]);
};

int main(void)
{
	createTest();
	areEqualTest();
	resizeTest();
	findIndexTest();
	disposeTest();
	findFirstTest();
	findLastTest();
  countTest();
  filterTest();
	return 0;
}
