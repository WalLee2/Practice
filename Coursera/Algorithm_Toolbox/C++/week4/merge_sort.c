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
	printf("arr[z]: ");
	for (z = low; i < lh && j < uh; z++) {
		if (lower_half[i] <= upper_half[j]) {
			arr[z] = lower_half[i];
			printf("%d ", arr[z]);
			i++;
		} else {
			arr[z] = upper_half[j];
			printf("%d ", arr[z]);
			j++;
		}
	}
	printf("\n");
	while (i < lh) {
		arr[z] = lower_half[i];
		printf("appending lower_half: %d ", lower_half[i]);
		i++;
		z++;
	}
	while (j < uh) {
		arr[z] = upper_half[j];
		printf("appending upper_half: %d ", upper_half[j]);
		j++;
		z++;
	}
	printf("\n");
}

void merge_sort(int arr[], size_t low, size_t high) {
	size_t middle;


	printf("Outside low: %lu\n", low);
	printf("Outside high: %lu\n\n", high);
	if (low < high) {
		middle = low + (high - low) / 2;
		printf("First recursion low: %lu\n", low);
		printf("First recursion high: %lu\n\n", high);
		merge_sort(arr, low, middle);
		printf("Second recursion low: %lu\n", low);
		printf("Second recursion high: %lu\n\n", high);
		merge_sort(arr, (middle + 1), high);
		printf("I'm going to merge!\n\n");
		merge(arr, low, middle, high);
		printf("Low after merge: %lu\n", low);
		printf("High after merge: %lu\n\n", high);
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
