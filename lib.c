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
	char i = 0;
	while(i != (util.typeSize * length)){
		newbase[i] = base[i];
		i++;
	};	
	util.length = length;
	util.base = newbase;
	return util;
};

int findIndex(ArrayUtil array, void *element){
	char *base = (char *)array.base;
	int length = array.length * array.typeSize;
	int i = 0,j = 0;
	while(i < length){
		if(memcmp(base + i,element,array.typeSize) == 0) 
			return j;	
		i += array.typeSize; 
		j++;
	}
	return -1;

	// char *base = (char *)array.base;
	// char *value = (char *)element;
	// int length = array.length;
	// int j = 0;
	// for(int i = 0;i != length; i++){
	// 	int k = 0;
	// 	for(int x = 0;x < array.typeSize; x++){
	// 		if(value[x] == base[j]) {
	// 			k++;
	// 		}
	// 		if(k == array.typeSize) return i;
	// 		j++;
	// 	};
	// };
	// return -1;
};

void dispose(ArrayUtil util){
	free(util.base);
};

void *findFirst(ArrayUtil util, MatchFunc match, void *hint){
  char *base = (char *)util.base;
  int i = 0;
  while(i < util.length * util.typeSize){
    int flag = match(hint, base + i);
    if(flag == 1){
      return base + i;
    }
    i += util.typeSize;
  }
  return NULL;
}
