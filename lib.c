#include <stdio.h>
#include <string.h>
#include "lib.h"
#include <stdlib.h>


ArrayUtil create(int typeSize,int length){
	ArrayUtil newArray;
	newArray.typeSize = typeSize;
	newArray.length = length;
	newArray.base = calloc(length,typeSize);
	return newArray;
};

int areEqual(ArrayUtil array1, ArrayUtil array2){
	if(array1.length != array2.length) return 0;
	char *array1_base = (char *)array1.base;
	char *array2_base = (char *)array2.base;
	for(char i = 0;i < array1.length;i++)
		if(array1_base[i] != array2_base[i]) return 0;
	return 1;
};

ArrayUtil resize(ArrayUtil util, int length){
	char *base = (char *)util.base;
	char *newbase = calloc(util.typeSize, length);
  for(char i = 0;i < util.typeSize * length;i++){
		newbase[i] = base[i];
  };
	util.length = length;
	util.base = newbase;
  free(base);
	return util;
};

int findIndex(ArrayUtil array, void *element){
	char *base = (char *)array.base;
	int length = array.length * array.typeSize;
	int i = 0,j = 0;
  	for(int i = 0;i < length;i+=array.typeSize){
		if(memcmp(base + i,element,array.typeSize) == 0) return j;	
		j++;
  	};
	return -1;
};

void dispose(ArrayUtil util){
	free(util.base);
};

void *findFirst(ArrayUtil util, MatchFunc match, void *hint){
	char *base = (char *)util.base;
  	for(int i = 0; i<util.length*util.typeSize; i+=util.typeSize){
		int flag = match(hint, base + i);
		if(flag == 1) return base + i;
 	}
	return NULL;
}

void *findLast(ArrayUtil util, MatchFunc match, void *hint){
	char *base = (char *)util.base;
	int l = (util.length * util.typeSize) - util.typeSize;
	for(int i = l; i >= 0; i-=util.typeSize){
		int flag = match(hint, base + i);
		if(flag == 1) return base + i;
 	}
  return NULL;
};

int count(ArrayUtil util, MatchFunc match, void *hint){
	char *base = (char *)util.base;
	int counter = 0;
  for(int i=0;i < util.length * util.typeSize;i+=util.typeSize){
		int flag = match(hint, base + i);
		if(flag == 1) counter++;
  };
  return counter;
}
int filter(ArrayUtil util, MatchFunc match, void* hint, void **destination, int maxItems ){
	char *base = (char *)util.base;
	int counter = 0;
	for(int i=0;i < util.length * util.typeSize;i+=util.typeSize){
		if(match(hint, base + i) == 1){
			*(destination + counter) = base + i;
			counter++;
		};
	};
	return counter;
}
