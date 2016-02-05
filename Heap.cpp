#include "Heap.h"

Heap::Heap(elemtype a[],int len,int size){
	length = len;
	heap_size = size;
	for (int i = 1; i < len; ++i)
	{
		this->data[i] = a[i];
	}

	buildMaxHeap(size);
}

void Heap::maxHeapify(int s){
	int l = LEFT(s);
	int r = RIGHT(s);
	elemtype temp;
	int largest = s;
	if (l <= heap_size && data[s] < data[l])
	{
		largest = l;
	}

	if (r <= heap_size && data[largest] < data[r])
	{
		largest = r;
	}

	if (largest != s)
	{
		temp = data[s];
		data[s] = data[largest];
		data[largest] = temp;
		maxHeapify(largest);
	}
}

void Heap::buildMaxHeap(int size){
	heap_size = size;
	for (int i = size/2; i >= 1; --i)
	{
		maxHeapify(i);
	}
}

void Heap::heapSort(){
	buildMaxHeap(length);
	for (int i = length; i > 0; --i)
	{
		elemtype temp;
		temp = data[1];
		data[1] = data[i];
		data[i] = temp;
		maxHeapify(length-1);
	}
}


