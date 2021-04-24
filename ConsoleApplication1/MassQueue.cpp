#include "MassQueue.h"
#include<vector>
#include<iostream>

MassQueue::MassQueue(unsigned int n)
{
	maxSize = 2*n;
	queue = new int[maxSize];
	size = 0;
	for (int i = 0; i < maxSize; i++)
	{
		queue[i] = -1;
	}
}

MassQueue::~MassQueue()
{
	delete[] queue;
}

void MassQueue::push(int lastElement)
{
	if (size < maxSize)
	{
		for (int i = size; i > 0; i--)
		{
			queue[i] = queue[i - 1];
		}
		queue[0] = lastElement;
		++size;
	}
	else
	{
		std::cout << "Очередь переполнена!" << std::endl;
	}
}

void MassQueue::pop()
{
	if (!empty())
	{
		queue[size - 1] = -1;
		--size;
	}
}

void MassQueue::insert(unsigned int i, int value)
{
	if (i < size)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			if (j == i)
			{
				pop();
				push(value);
			}
			else
			{
				int tmp = getBackValue();
				pop();
				push(tmp);
			}
		}
	}
	else
	{
		std::cout << "Индекс больше количества элементов в очереди." << std::endl;
	}
}

int MassQueue::getValue(unsigned int i)
{
	int ans = -1;
	if (i < size)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			if (j == i)
			{
				ans = getBackValue();
			}
			int tmp = getBackValue();
			pop();
			push(tmp);
		}
	}
	else
	{
		std::cout << "Индекс больше количества элементов в очереди." << std::endl;
	}
	return ans;
}

void MassQueue::SetTmpQueue()
{
	MassQueue* tmpQueue = new MassQueue(size);
	for (int i = 0; i < size; i++)
	{
		int tmp = getBackValue();
		pop();
		push(tmp);
		tmpQueue->push(tmp);
	}
	for (int i = getSize() - 1; i >= 0; i--)
	{
		int tmp = tmpQueue->getBackValue();
		tmpQueue->pop();
		tmpQueue->push(tmp);
		push(tmp);
	}
	delete tmpQueue;
}

void MassQueue::DeleteTmpQueue()
{
	if (size > maxSize / 2)
	{
		for (int i = size; i > maxSize / 2; i--)
		{
			pop();
		}
	}
	else
	{
		std::cout << "Временная очередь пустая" << std::endl;
	}
}

int MassQueue::getBackValue()
{
	return queue[size - 1];
}

int MassQueue::getFrontValue()
{
	return queue[0];
}

int MassQueue::getSize()
{
	return size;
}

bool MassQueue::empty()
{
	return size == 0;
}

//void MassQueue::MergeMas(int firstElemMain, int firstElem1, unsigned int size1, int firstElem2, unsigned int size2)
//{
//	unsigned int k = firstElemMain;
//	unsigned int i = firstElem1;
//	unsigned int j = firstElem2;
//	while ((i < size1) && (j < size2))
//	{
//		if (getValue(i) <= getValue(j))
//		{
//			insert(k, getValue(i));
//			++k;
//			++i;
//		}
//		else
//		{
//			insert(k, getValue(j));
//			++k;
//			++j;
//		}
//	}
//	for (i; i < size1; i++)
//	{
//		insert(k, getValue(i));
//		++k;
//	}
//	for (j; j < size2; j++)
//	{
//		insert(k, getValue(j));
//		++k;
//	}
//}

//void MassQueue::MergeSort()
//{
//	unsigned int sizeReal = size / 2;
//	for (unsigned int i = 0; i < sizeReal; i++)
//	{
//		//insert(i + sizeReal, getValue(i));
//		std::cout << getValue(i + sizeReal) << " ";
//	}
//	for (unsigned int k = 1; k < sizeReal; k *= 2)
//	{
//		std::cout << std::endl;
//		bool flag = true;
//		for (unsigned int i = 0; i < sizeReal / 2 + sizeReal % 2; i += k)
//		{
//			if (k >= sizeReal / 2 + sizeReal % 2)
//			{
//				MergeMas(0, sizeReal, k, sizeReal + k, sizeReal - k);
//				break;
//			}
//			if (k + i <= sizeReal / 2)
//			{
//				if (flag)
//				{
//					MergeMas(i, sizeReal + i, k, sizeReal + sizeReal - k - i, k);
//					flag = not flag;
//				}
//				else
//				{
//					MergeMas(sizeReal - i - k, sizeReal + i, k, sizeReal + sizeReal - k - i, k);
//					flag = not flag;
//				}
//			}
//			else
//			{
//				if (flag)
//				{
//					unsigned int tmpSize = sizeReal - 2 * i;
//					MergeMas(i, sizeReal + i, tmpSize / k * k, sizeReal + i + tmpSize / k * k, tmpSize % k);
//					flag = not flag;
//				}
//				else
//				{
//					unsigned int tmpSize = sizeReal - 2 * i;
//					MergeMas(i + k, sizeReal + i, tmpSize / k * k, sizeReal + i + tmpSize / k * k, tmpSize % k);
//					flag = not flag;
//				}
//			}
//		}
//		for (unsigned int i = 0; i < sizeReal; i++)
//		{
//			insert(sizeReal + i, getValue(i));
//			std::cout << getValue(sizeReal + i) << " ";
//		}
//	}
//}

void MassQueue::Show()
{
	MassQueue *tmpQueue = new MassQueue(size);
	for (int i = 0; i < size; i++)
	{
		tmpQueue->push(getFrontValue());
		for (int j = size - 1; j > 0; j--)
		{
			int tmp = getBackValue();
			pop();
			push(tmp);
		}
	}
	for (int i = size - 1; i >= 0; i--)
	{
		int tmp = tmpQueue->getBackValue();
		tmpQueue->pop();
		tmpQueue->push(tmp);
		std::cout << tmp << " ";
	}
	std::cout << std::endl;
	delete tmpQueue;
}

