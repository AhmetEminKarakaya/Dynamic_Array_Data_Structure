# Dynamic Array Data Structure

This repository contains the implementation of a dynamic array data structure in C. Dynamic arrays are resizable arrays that provide the benefits of array-based data structures with the flexibility to resize at runtime.

## Features

- **Dynamic resizing:** Automatically expands and contracts as elements are added or removed.
- **Efficient access:** Provides constant-time access to elements by index.
- **Easy to use:** Simple API for common array operations.

API Reference

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
