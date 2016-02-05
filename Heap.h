#ifndef MAXSIZE
#define MAXSIZE 100

typedef int elemtype;

class Heap
{
private:
	elemtype data[MAXSIZE];
	int length;
	int heap_size;
	int LEFT(int i){
		return 2*i;
	}
	int RIGHT(int i){
		return 2*1+1;
	}
	int PARENT(int i){
		return i/2;
	}
public:
	Heap(elemtype a[],int len,int size);
	void maxHeapify(int s);
	void buildMaxHeap(int size);
	void heapSort();
};

#endif
