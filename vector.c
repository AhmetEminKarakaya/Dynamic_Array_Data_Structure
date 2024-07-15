#include "vector.h"

HndVector initVectorCapacity(int capacity)
{
	HndVector pVector = (HndVector)malloc(sizeof(HndVector));
	if (pVector == NULL)
	{
		printf("Not enough memory for handle...");
	}

	pVector->pArray = (valueType*)malloc(capacity * sizeof(valueType));

	if (pVector->pArray == NULL)
	{
		printf("Not enough memory for capacity...");
		free(pVector);
		return NULL;
	}

	pVector->capacity = capacity;
	pVector->size = 0;

	return pVector;
}


HndVector initVector()
{
	return initVectorCapacity(INITIAL_CAPACITY);
}

int getSize(HndVector hnd)
{
	return hnd->size;
}

int getCapacity(HndVector hnd)
{
	return hnd->capacity;
}

static int setCapacity(HndVector hnd)
{
	int memorySizeBytes = hnd->capacity * VECTOR_CAP_INCREASE * sizeof(int);

	valueType* pnewArray = (valueType*)realloc(hnd->pArray, memorySizeBytes);

	if (pnewArray == NULL)
	{
		printf("Not enough memory for set capacity...");
		return -1;
	}
	hnd->capacity = hnd->capacity * VECTOR_CAP_INCREASE;
	hnd->pArray = pnewArray;

	return hnd->pArray;
}

int pushBack(HndVector hnd, valueType val)
{
	if (hnd->size >= hnd->capacity)
		if (setCapacity(hnd) == -1)
			return -1;

	hnd->pArray[hnd->size++] = val;
	
	return hnd->size - 1;
}

int getAt(const HndVector hnd, int index)
{
	if (index < 0 || index > hnd->size)
		return -1;

	return hnd->pArray[index];
}

int isEmpty(const HndVector hnd)
{
	return hnd->size == 0;
}

void destroyVector(HndVector hnd)
{
	free(hnd->pArray);
	free(hnd);
}

void display(const HndVector hnd)
{
	for (int i = 0; i < getSize(hnd); i++)
		printf("%d ", hnd->pArray[i]);
}

int insertAt(HndVector hnd, int index, int val)
{
	if (index < 0 || index > hnd->size)
		return -1;

	if (hnd->size >= hnd->capacity)
		if (setCapacity(hnd) == -1)
			return -1;

	memmove(&hnd->pArray[index + 1], &hnd->pArray[index], (hnd->size - index) * sizeof(valueType));
	hnd->pArray[index] = val;
	hnd->size++;

	return index;
}

int removeAt(HndVector hnd, int index)
{
	if (index < 0 || index > hnd->size)
		return -1;

	memmove(&hnd->pArray[index], &hnd->pArray[index+1], (hnd->size - index-1) * sizeof(valueType));
	hnd->size--;

	return index;
}

void popback(HndVector hnd)
{
	removeAt(hnd, hnd->size);
}

void swapVectorIndex(HndVector hnd, valueType index1, valueType index2)
{
	valueType temp;

	temp = hnd->pArray[index1];
	hnd->pArray[index1] = hnd->pArray[index2];
	hnd->pArray[index2] = temp;
}