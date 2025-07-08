#include <stdio.h>
#include <time.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i = 0, j = 0, k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = M[j++];
    }
  }

  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = M[j++];
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int size;

  printf("Enter number of elements: ");
  scanf("%d", &size);

  int arr[size];

  printf("Enter %d integers:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  clock_t start = clock();

  mergeSort(arr, 0, size - 1);

  clock_t end = clock();

  printf("Sorted array:\n");
  printArray(arr, size);

  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time taken to sort: %f seconds\n", time_taken);

  return 0;
}

