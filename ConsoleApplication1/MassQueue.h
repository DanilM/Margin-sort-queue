#pragma once
#include<vector>

class MassQueue
{
private:
	int size;
	int *queue;
	int maxSize;
	//void MergeMas(int firstElemMain, int firstElem1, unsigned int size1, int firstElem2, unsigned int size2);
public:
	MassQueue(unsigned int n);
	~MassQueue();
	void push(int lastElement);
	void pop();
	void insert(unsigned int i, int value);
	void SetTmpQueue();
	void DeleteTmpQueue();
	bool empty();
	int getSize();
	int getFrontValue();
	int getBackValue();
	int getValue(unsigned int i);
	//void MergeSort();
	void Show();
};

