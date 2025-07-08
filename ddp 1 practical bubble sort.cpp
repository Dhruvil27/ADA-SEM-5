#include <stdio.h>
#include <time.h>

void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int size;

  printf("Enter number of elements: ");
  scanf("%d", &size);

  int data[size];  
  printf("Enter %d integers:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &data[i]);
  }

  clock_t start, end;
  start = clock();

  bubbleSort(data, size);

  end = clock();

  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Sorted Array in Ascending Order:\n");
  printArray(data, size);

  printf("Time taken to sort: %f seconds\n", time_taken);

  return 0;
}

