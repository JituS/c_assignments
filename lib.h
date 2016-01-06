typedef struct Array_Util
{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (*MatchFunc)(void *hint, void *item);
typedef void (*ConvertFunc)(void *hint, void *sourceItem, void *destinationItem);
typedef void OperationFunc(void* hint, void* item);
typedef void* ReducerFunc(void* hint, void* previousItem, void* item);

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
int filter(ArrayUtil util, MatchFunc match, void* hint, void** destination, int maxItems);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc convert, void* hint);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
void *reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);
