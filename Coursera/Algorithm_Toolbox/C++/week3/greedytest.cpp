#include <iostream>
#include <map>

using std::map;
using std::cout;


void sortedGroups(double *arr, map<double, double> returnedSet, const size_t size) {
	size_t i, j;

	for (i = 0; i < size; ++i) {
		for (j = i; j <= (arr[j] + 1); ++j) {
			returnedSet.insert(map<double, double>::value_type(arr[i], arr[j + 1]));
		}
		while (i < size && i <= arr[i] + 1) {
			++i;
		}
	}
}

int main(void) {
	double arr[] = {5, 5.1, 5.3, 5.4, 5.5, 6, 6.3, 7, 7.7, 7.8, 7.9, 8};
	map<double, double> returnedSet;
	map<double, double>::const_iterator it;
	size_t size;

	size = sizeof(arr) / sizeof(arr[0]);
	sortedGroups(arr, returnedSet, size);
	for (it = returnedSet.begin(); it != returnedSet.end(); ++it) {
		cout << it->first << " " << it->second << '\n';
	}
}
