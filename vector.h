#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY	8
#define VECTOR_CAP_INCREASE 2

typedef int valueType;

typedef struct
{
	valueType* pArray;
	int capacity;
	int size;
}Vector,*HndVector; // *HndVector = Vector*

HndVector initVector();
HndVector initVectorCapacity(int capacity);
int getSize(HndVector hnd);
int getCapacity(HndVector hnd);
int pushBack(HndVector hnd, valueType val);
int getAt(const HndVector hnd, int index);
int isEmpty(const HndVector hnd);
void destroyVector(HndVector hnd);
void display(const HndVector hnd);
int insertAt(HndVector hnd, int index, int val);
int removeAt(HndVector hnd, int index);
void popback(HndVector hnd);
void swapVectorIndex(HndVector hnd, valueType index1, valueType index2);
