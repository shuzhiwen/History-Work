#include <iostream>

using namespace std;

template <typename T>
void SWAP(T & A, T & B) {
  T C = A;
  A = B;
  B = C;
}

template <typename T>
void quickSort(T * array, int low, int high) {
  if (high <= low) {
    return;
  }

  int pivot_index, i, j = low, middle;

  if (array[low] >= array[(low + high) / 2] && array[low] <= array[high] ||
      array[low] <= array[(low + high) / 2] && array[low] >= array[high]) {
    pivot_index = low;
  } else if (array[high] >= array[(low + high) / 2] && array[high] <= array[low] ||
             array[high] <= array[(low + high) / 2] && array[high] >= array[low]) {
    pivot_index = high;
  } else {
    pivot_index = (low + high) / 2;
  }

  T pivot = array[pivot_index];

  SWAP(array[low], array[pivot_index]);
  for (i = low + 1; i <= high; i++) {
    if (array[i] < pivot) {
      SWAP(array[++j], array[i]);
    }
  }

  middle = j;
  SWAP(array[middle], array[low]);
  quickSort(array, low, middle - 1);
  quickSort(array, middle + 1, high);
}