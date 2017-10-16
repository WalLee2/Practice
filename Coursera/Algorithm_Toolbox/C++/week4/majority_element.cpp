#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

/**
 * merge - Void function that merges two array elements together where the first
 * element is smaller than the second element.
 * @a: The vector of numbers to be evaluated
 * @low: Variable that holds the low index
 * @mid: Variable that holds the middle index of the vector
 * @high: Variable that holds the high index
 */
void merge(vector<int> &a, size_t low, size_t mid, size_t high) {
	size_t lh = mid - low + 1;
	size_t uh = high - mid;
	size_t i, j, z;
	std::vector<int>lower_half(lh);
	std::vector<int>upper_half(uh);

	for (i = 0; i < lh; ++i) {
		lower_half[i] = a[i + low];
	}
	for (j = 0; j < uh; ++j) {
		upper_half[j] = a[j + mid + 1];
	}
	i = j = 0;
	z = low;
	while (i < lh && j < uh) {
		if (lower_half[i] < upper_half[j]) {
			a[z] = lower_half[i];
			++i;
		} else {
			a[z] = upper_half[j];
			++j;
		}
		++z;
	}
	while (i < lh) {
		a[z] = lower_half[i];
		++i;
		++z;
	}
	while (j < uh) {
		a[z] = upper_half[j];
		++j;
		++z;
	}
}

/**
 * merge_sort - Function that recursively breaks down the left and right side
 * of the array into their individual elements and merges from low to high
 * values
 * @array: Vector to be sorted
 * @low: Variable that holds the low index of the vector
 * @high: Variable that holds the high index of the vector
 */
void merge_sort(vector<int> &array, size_t low, size_t high) {
	size_t mid;

	if (low < high) {
		mid = low + (high - low) / 2;
		merge_sort(array, low, mid);
		merge_sort(array, (mid + 1), high);
		merge(array, low, mid, high);
	}
}
/**
 * binary_search - Inefficient binary search algorithm
 * @a: Vector to be evaluated
 * @value: The value to find
 * @index: Variable that holds the index of value to make sure
 * I'm not considering the same number
 * Return: Return 1 on finding the number 0 otherwise
 */
int binary_search(vector<int> &a, int value, int index) {
	int mid, i, low, high;

	low = 0;
	high = ((int)a.size() - 1);
	mid = low + (high - low) / 2;
	if (value > a[mid]) {
		for (i = mid + 1; i < high; ++i) {
			if (value == a[i] && index != i) {
				a.erase(a.begin() + i);
				return (1);
			}
		}
	} else if (value < a[mid]) {
		for (i = 0; i < mid; ++i) {
			if (value == a[i] && index != i) {
				a.erase(a.begin() + i);
				return (1);
			}
		}
	} else if (value == a[mid] && index != mid) {
		return (1);

	}
	return (0);
}
/**
 * get_majority_element - Sort and find the majority element in the vector
 * @a: Vector to be evaluated
 * Return: 1 if the majority element exceeds the majority, -1 if there is no
 * element that exceeds the majority
 */
int get_majority_element(vector<int> &a) {
	size_t result, i, count;
	merge_sort(a, 0, (a.size() - 1));
	count = 1;
	for (i = 0; i < a.size(); ++i) {
		result = binary_search(a, a[i], i);
		if (result) {
			count += 1;
		} else {
			count = 1;
		}
		if (count > (a.size() / 2)) {
			return (1);
		}
	}
	return (-1);
}
/**
 * main - Take user input and store the input into a vector
 * Return: Always 0
 */
int main(void) {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a) != -1) << '\n';
	return (0);
}
