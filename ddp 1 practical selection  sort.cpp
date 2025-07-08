#include <stdio.h>
#include <time.h>

// Function to swap the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Selection Sort implementation
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

// Function to print an array
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

  selectionSort(data, size);

  end = clock();

  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Sorted array in Ascending Order:\n");
  printArray(data, size);

  printf("Time taken to sort: %f seconds\n", time_taken);

  return 0;
}

