#include <iostream>
#include <vector>
#include <ctime>
#include "MassQueue.h"

using namespace std;

//void MergeMas(int mergMas[], int mergMas1[], unsigned int size1, int mergMas2[], unsigned int size2)
//{
//	unsigned int k = 0;
//	unsigned int i = 0;
//	unsigned int j = 0;
// 	while ((i < size1) && (j < size2))
//	{
//		if (mergMas1[i] <= mergMas2[j])
//		{
//			mergMas[k] = mergMas1[i];
//			++k;
//			++i;
// 		}
//		else
//		{
//			mergMas[k] = mergMas2[j];
//			++k;
//			++j;
//		}
// 	}
//	for (i; i < size1; i++)
//	{
//		mergMas[k] = mergMas1[i];
//		++k;
//	}
//	for (j; j < size2; j++)
//	{
//		mergMas[k] = mergMas2[j];
//		++k;
//	}
//}
//

//void MergeSort(int sortMas[],  unsigned int size)
//{
//	vector<int> mergMas(size);
//	for (unsigned int i = 0; i < size; i++)
//	{
//		mergMas[i] = sortMas[i];
//	}
//	for (unsigned int i = 0; i < size; i++)
//	{
//		mergMas[i] = sortMas[i];
//		cout << mergMas[i] << " ";
//	}
//	for (unsigned int k = 1; k < size; k *= 2)
//	{
//		cout << endl;
//		bool flag = true;
//		for (unsigned int i = 0; i < size / 2 + size % 2; i += k)
//		{
//			if (k >= size / 2 + size % 2)
//			{
//				MergeMas(&sortMas[0], &mergMas[0], k, &mergMas[k], size - k);
//				break;
//			}
//			if (k + i <= size / 2)
//			{
//				if (flag)
//				{
//					MergeMas(&sortMas[i], &mergMas[i], k, &mergMas[size - k - i], k);
//					flag = not flag;
//				}
//				else
//				{
//					MergeMas(&sortMas[size - i - k], &mergMas[i], k, &mergMas[size - k - i], k);
//					flag = not flag;
//				}
//			}
//			else
//			{
//				if (flag)
//				{
//					unsigned int tmpSize = size - 2 * i;
//					MergeMas(&sortMas[i], &mergMas[i], tmpSize / k * k, &mergMas[i + tmpSize / k * k], tmpSize % k);
//					flag = not flag;
//				}
//				else
//				{
//					unsigned int tmpSize = size - 2 * i;
//					MergeMas(&sortMas[i + k], &mergMas[i], tmpSize / k * k, &mergMas[i + tmpSize / k * k], tmpSize % k);
//					flag = not flag;
//				}
//			}
//		}
//		for (unsigned int i = 0; i < size; i++)
//		{
//			mergMas[i] = sortMas[i];
//			cout << mergMas[i] << " ";
//		}
//	}
//}


void MergeMas(MassQueue &queue, int firstElemMain, int firstElem1, unsigned int size1, int firstElem2, unsigned int size2)
{
	unsigned int k = firstElemMain;
	unsigned int i = firstElem1;
	unsigned int j = firstElem2;
	while ((i < size1 + firstElem1) && (j < size2 + firstElem2))
	{
		if (queue.getValue(i) <= queue.getValue(j))
		{
			queue.insert(k, queue.getValue(i));
			++k;
			++i;
		}
		else
		{
			queue.insert(k, queue.getValue(j));
			++k;
			++j;
		}
	}
	for (i; i < size1 + firstElem1; i++)
	{
		queue.insert(k, queue.getValue(i));
		++k;
	}
	for (j; j < size2 + firstElem2; j++)
	{
		queue.insert(k, queue.getValue(j));
		++k;
	}
}

void MergeSort(MassQueue &queue)
{
	unsigned int sizeReal = queue.getSize();
	queue.SetTmpQueue();
	for (unsigned int k = 1; k < sizeReal; k *= 2)
	{
		//std::cout << std::endl;
		bool flag = true;
		for (unsigned int i = 0; i < sizeReal / 2 + sizeReal % 2; i += k)
		{
			if (k >= sizeReal / 2 + sizeReal % 2)
			{
				MergeMas(queue, 0, sizeReal, k, sizeReal + k, sizeReal - k);
				break;
			}
			if (k + i <= sizeReal / 2)
			{
				if (flag)
				{
					MergeMas(queue, i, sizeReal + i, k, sizeReal + sizeReal - k - i, k);
					flag = not flag;
				}
				else
				{
					MergeMas(queue, sizeReal - i - k, sizeReal + i, k, sizeReal + sizeReal - k - i, k);
					flag = not flag;
				}
			}
			else
			{
				if (flag)
				{
					unsigned int tmpSize = sizeReal - 2 * i;
					MergeMas(queue, i, sizeReal + i, tmpSize / k * k, sizeReal + i + tmpSize / k * k, tmpSize % k);
					flag = not flag;
				}
				else
				{
					unsigned int tmpSize = sizeReal - 2 * i;
					MergeMas(queue, i + k, sizeReal + i, tmpSize / k * k, sizeReal + i + tmpSize / k * k, tmpSize % k);
					flag = not flag;
				}
			}
		}
		for (unsigned int i = 0; i < sizeReal; i++)
		{
			queue.insert(sizeReal + i, queue.getValue(i));
		}
		//queue.Show();
		//std::cout << std::endl;
	}
	queue.DeleteTmpQueue();
}

int main()
{
	unsigned int n;
	setlocale(LC_ALL, "rus");
	std::cout << "Введите длину массива: ";
	std::cin >> n;
	std::vector<int> mas(2*n);
	srand(time(0));
	for (unsigned int i = 0; i < n; i++)
	{
		mas[i] = rand()%100;
	}
	
	MassQueue* queue = new MassQueue(n);
	for (int i = n - 1; i >= 0; i--)
	{
		queue->push(mas[i]);
	}
	//for (unsigned int i = 0; i < 2*n; i++)
	//{
	//	std::cout << mas[i] << " ";
	//}
	//std::cout << std::endl;
	//queue->MergeSort();

	//queue->insert(1, 3144);
	queue->Show();

	MergeSort(*queue);

	queue->Show();

	delete queue;
	//MergeSort(&mas[0], n);

	return 0;
}