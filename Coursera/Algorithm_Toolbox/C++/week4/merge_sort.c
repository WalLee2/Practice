#include <stdio.h>

void merge(int arr[], size_t low, size_t mid, size_t hi) {
	size_t i, j, z;
	size_t lh = (mid - low) + 1;
	size_t uh = hi - mid;

	int upper_half[uh], lower_half[lh];

	for (i = 0; i < lh; i++) {
		lower_half[i] = arr[low + i];
	}
	for (j = 0; j < uh; j++) {
		upper_half[j] = arr[mid + 1 + j];
	}

	i = j = 0;
	for (z = low; i < lh && j < uh; z++) {
		if (lower_half[i] <= upper_half[j]) {
			arr[z] = lower_half[i];
			i++;
		} else {
			arr[z] = upper_half[j];
			j++;
		}
	}
	while (i < lh) {
		arr[z] = lower_half[i];
		i++;
		z++;
	}
	while (j < uh) {
		arr[z] = upper_half[j];
		j++;
		z++;
	}
}

void merge_sort(int arr[], size_t low, size_t high) {
	size_t middle;


	if (low < high) {
		middle = low + (high - low) / 2;
		merge_sort(arr, low, middle);
		merge_sort(arr, (middle + 1), high);
		merge(arr, low, middle, high);
	}
}
void printArray(int A[], size_t size)
{
	size_t i;

	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(void) {
	int array[] = {19, 48, 99, 71, 13, 52, 96, 86, 7};
	size_t size;

	size = sizeof(array) / sizeof(array[0]);
	printArray(array, size);
	merge_sort(array, 0, (size - 1));
	printArray(array, size);
	return (0);
}
