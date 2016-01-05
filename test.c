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
  return (*item_ % *hint_) == 0;   
};  

void matchTest(){
	int length = 6;
	int typeSize = 4;
	ArrayUtil array = create(typeSize,length);
	int *array1_base = (int *)array.base;
	array1_base[0] = 1;
	array1_base[1] = 2;
  array1_base[2] = 6;
  array1_base[3] = 8;
  int hint = 3;
  int *x = (int *)findFirst(array, &isDivisible, &hint);
  printf("%d\n",*x);
};

int main(void)
{
	createTest();
	areEqualTest();
	resizeTest();
	findIndexTest();
	disposeTest();
  matchTest();
	return 0;
}
