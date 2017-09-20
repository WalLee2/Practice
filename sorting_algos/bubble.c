#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * The algorithm repeatedly steps through the array until it is sorted.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t temp_size, i, j;
	int temp;

	temp_size = size;
	for (i = 0; i < size; i++) {
		for (j = 0; j < (temp_size - 1); j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			print_array(array, size);
		}
		temp_size--;
	}
}
