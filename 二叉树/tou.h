#pragma once
typedef int HeapDataType;//数据类型
typedef struct Heap
{
	HeapDataType* a;//数组首地址
	int size;//数组个数
	int capacity;//数组容量
}Heap;
void HeapSwap(HeapDataType* n1, HeapDataType* n2);
void HeapPrint(Heap* ph);
void HeapInit(Heap* ph);
void HeapDestory(Heap* ph);
void HeapPush(Heap* ph, HeapDataType x);
void HeapPop(Heap* ph);
HeapDataType HeapTop(Heap* ph);
bool HeapEmpty(Heap* ph);
int HeapSize(Heap* ph);
void AdjustDown(HeapDataType* a, int parent, int size);
void AdjustUp(HeapDataType* a, int child);
void HeapSort(HeapDataType* a, int size);