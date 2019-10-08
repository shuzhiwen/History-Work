#include "qsort.h"

using namespace std;

template <typename T>
void SWAP(T & A, T & B) {
  T C = A;
  A = B;
  B = C;
}

template <typename T>
QuickSort<T>::QuickSort(T * array, int size) {
  count[0] = count[1] = count[2] = 0;

  branch1(array, 0, size - 1);
  branch2(array, 0, size - 1);
  branch3(array, 0, size - 1);

  cout << "branch1:" << endl;
  cout << count[0] << " comparisons for the array of size " << size << endl;
  cout << "branch2:" << endl;
  cout << count[1] << " comparisons for the array of size " << size << endl;
  cout << "branch3:" << endl;
  cout << count[2] << " comparisons for the array of size " << size << endl;
}

template <typename T>
void QuickSort<T>::branch1(T * array, int low, int high) {
  if (high > low) {
    T pivot = array[low];

    int i, j = low, middle;
    
    for (i = low + 1; i <= high; i++) {
      count[0]++;
      if (array[i] < pivot) {
        SWAP(array[++j], array[i]);
      }
    }

    middle = j;
    SWAP(array[middle], array[low]);
    branch1(array, low, middle - 1);
    branch1(array, middle + 1, high);
  }
}

template <typename T>
void QuickSort<T>::branch2(T * array, int low, int high) {
  if (high > low) {
    srand(time(0));
    int pivot_index = rand() % (high - low + 1) + low;
    T pivot = array[pivot_index];
    SWAP(array[low], array[pivot_index]);

    int i, j = low, middle;

    for (i = low + 1; i <= high; i++) {
      count[1]++;
      if (array[i] < pivot) {
        SWAP(array[++j], array[i]);
      }
    }

    middle = j;
    SWAP(array[middle], array[low]);
    branch2(array, low, middle - 1);
    branch2(array, middle + 1, high);
  }
}

template <typename T>
void QuickSort<T>::branch3(T * array, int low, int high) {
  if (high > low) {
    int pivot_index;
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

    int i, j = low, middle;
    
    for (i = low + 1; i <= high; i++) {
      count[2]++;
      if (array[i] < pivot) {
        SWAP(array[++j], array[i]);
      }
    }

    middle = j;
    SWAP(array[middle], array[low]);
    branch3(array, low, middle - 1);
    branch3(array, middle + 1, high);
  }
}