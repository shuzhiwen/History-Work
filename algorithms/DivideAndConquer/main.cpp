#include <iostream>
#include <cstdlib>

#include "quickSort.cpp"

using namespace std;

int main () {
  int capacity[10] = {100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 1024000};
  
  for (int i = 0; i < 10; i++) { //test for qsort
    int array[capacity[i]];

    srand(time(0));
    for (int j = 0; j < capacity[i]; j++) {
      array[j] = rand();
    }

    quickSort<int>(array, 0, capacity[i]);
    for (int j = 1; j < capacity[i]; j++) {
      if (array[j] < array[j - 1]) {
        cout << "The array is not sorted with capacity" << capacity[i] << endl;
        break;
      }
    }
  }
}