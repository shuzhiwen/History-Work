#include <iostream>
#include <cstdlib>

#include "qsort.h"

using namespace std;

int main () {
  int capacity[10] = {100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 1024000};
  
  for (int i = 0; i < capacity[i]; i++) {
    int array[capacity[i]];

    srand(time(0));
    for (int j = 0; j < capacity[i]; j++) {
      array[j] = rand();
    }

    QuickSort<int>(array, capacity[i]);
  }
}