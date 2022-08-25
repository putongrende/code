#pragma once
typedef int HeapDataType;//��������
typedef struct Heap
{
	HeapDataType* a;//�����׵�ַ
	int size;//�������
	int capacity;//��������
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