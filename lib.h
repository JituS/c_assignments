typedef struct Array_Util
{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (*MatchFunc)(void *hint, void *item);

ArrayUtil create(int typeSize,int length);
void createTest();
int areEqual(ArrayUtil array1, ArrayUtil array2);
void areEqualTest();
ArrayUtil resize(ArrayUtil util, int length);
void resize_test();

int findIndex(ArrayUtil array, void *element);
void find_index_test();

void dispose(ArrayUtil util);

void *findFirst(ArrayUtil util, MatchFunc match, void* hint);

void *findLast(ArrayUtil util, MatchFunc match, void *hint);
int isDivisible(void *hint, void *item);
int count(ArrayUtil util, MatchFunc match, void* hint);
int filter(ArrayUtil util, MatchFunc match, void* hint, void** destination, int maxItems );


