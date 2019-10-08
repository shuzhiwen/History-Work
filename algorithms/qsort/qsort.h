#pragma once

#include <iostream>

using namespace std;

template <typename T>
class QuickSort {
public:
  QuickSort(T * array, int size);
  void branch1(T * array, int low, int high);
  void branch2(T * array, int low, int high);
  void branch3(T * array, int low, int high);

private:
  long long count[3];
};

template class QuickSort<int>;
template class QuickSort<double>;