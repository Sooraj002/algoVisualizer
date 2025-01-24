#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void quickSort(void);
void quickSortRecursive(int* arr, int low, int high, int size);
int partition(int* arr, int low, int high, int size);

#endif // QUICK_SORT_H 