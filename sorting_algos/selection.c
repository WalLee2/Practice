#include "sort.h"
/**
 *
 *
 *
 *
 */
void selection_sort(int *arr, size_t size)
{
	int saved, swap, state;
	size_t i, j, index;

	state = 0;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (state == 0 && arr[i] > arr[j]) {
				saved = arr[j];
				index = j;
				state = 1;
			}
			else if (state == 1 && saved > arr[j]) {
				saved = arr[j];
				index = j;
			}
		}
		if (state == 1 && arr[i] > arr[index]) {
			swap = arr[i];
			arr[i] = arr[index];
			arr[index] = swap;
			state = 0;
			print_array(arr, size);
		}
	}
}
