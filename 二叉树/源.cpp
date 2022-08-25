#include<iostream>
#include<string>
#include <assert.h>
#include"tou.h"
#define max 1000
using namespace std;
//Դ�ļ�
void HeapSwap(HeapDataType* n1, HeapDataType* n2)//�����ڵ�����
{
	assert(n1 && n2);
	HeapDataType temp = *n1;
	*n1 = *n2;
	*n2 = temp;

}
void HeapPrint(Heap* ph)  //��ӡ
{
	assert(ph);
	for (int i = 0; i < ph->size; i++)
	{
		cout << ph->a[i] << endl;
	}
	cout << "\n" << endl;
}
void HeapInit(Heap* ph)// ��ʼ��
{
	assert(ph);
	ph->a == NULL;
	ph->size = ph->capacity = 0;

}
void HeapDestory(Heap* ph)//����
{
	assert(ph);
	if (ph->a)
	{
		free(ph->a);
		ph->a = NULL;
		ph->size = ph->capacity = 0;
	}

}
void HeapPush(Heap* ph, HeapDataType x)//���
{
	assert(ph);
	if (ph->size == ph->capacity)
	{
		int newcapacity = ph->capacity == 0 ? 4 : ph->capacity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(ph->a, sizeof(HeapDataType) * newcapacity);
		if (!tmp)
		{
			perror("realloc fail\n");
			return;
		}
		ph->a = tmp;
		ph->capacity = newcapacity;
	}
	ph->a[ph->size++] = x;
	AdjustUp(ph->a, ph->size - 1);

}
void HeapPop(Heap* ph)//����
{
	assert(!HeapEmpty(ph));//r�����Ϊ�ղ��ܳ���
	assert(ph);
	HeapSwap(&(ph->a[0]), &(ph->a[ph->size - 1]));
	ph->size--;
	AdjustDown(ph->a, 0, ph->size);
}
HeapDataType HeapTop(Heap* ph)//��ȡ�Ѷ�����
{
	assert(!HeapEmpty(ph));//��ȡ��������
	assert(ph);
	return ph->a[0];

}
bool HeapEmpty(Heap* ph)//����Ϊ�շ���true����Ϊ�շ���fals
{
	assert(ph);
	return ph->size == 0;


}
int HeapSize(Heap* ph)//�ѵ����ݸ�����
{
	assert(ph);
	return ph->size;

}
void AdjustDown(HeapDataType* a, int parent, int size)//���µ���
{
	assert(a);
	int child = parent * 2 + 1;//��ú��ӽ��
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			HeapSwap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;


	}
}
void AdjustUp(HeapDataType* a, int child)//���ϵ���
{
	assert(a);
	int parent = (child - 1) / 2;//��ȡ˫�׽���±�
	while (child > 0)
	{
		if (a[child] >= a[parent])
		{
			HeapSwap(&(a[child]), &(a[parent]));
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}


}
void HeapSort(HeapDataType* a, int size)//������   �����
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, size);
	}

	// ���� O(N*logN)
	int end = size - 1;
	while (end > 0)
	{
		HeapSwap(&(a[0]), &(a[end]));
		AdjustDown(a, 0, end);
		end--;
	}

}



