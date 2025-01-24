#ifndef MERGE_SORT_H

#define MERGE_SORT_H

void mergeSort(void);
void mergeSortRecursive(int* arr, int left, int right, int size);
void merge(int* arr, int left, int mid, int right, int size);

#endif // MERGE_SORT_H 