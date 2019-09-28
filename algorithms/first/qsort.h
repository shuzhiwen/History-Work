#pragma once

template <typename T>
class QuickSort {
public:
  QuickSort(T * & array, int size);

private:
  long long count[3];
};

template class QuickSort<int>;
template class QuickSort<double>;