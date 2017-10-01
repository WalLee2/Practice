#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::cout;
using std::vector;

void sortedGroups(double *arr, map<double, vector<double> > groups, const size_t size) {
	size_t i, j;

	for (i = 0; i < size; ++i) {
		for (j = i; j <= (arr[j] + 1); ++j) {
			groups.insert(std::make_pair(arr[i], vector<double>(arr[j + 1])));
		}
		while (i < size && i <= arr[i] + 1) {
			++i;
		}
	}
}

int main(void) {
	double arr[] = {5, 5.1, 5.3, 5.4, 5.5, 6, 6.3, 7, 7.7, 7.8, 7.9, 8};
	map<double, vector<double> > groups;
	size_t size;

	size = sizeof(arr) / sizeof(arr[0]);
	sortedGroups(arr, groups, size);
/*
	auto it = groups.begin();
	cout << it->first << " : ";
	auto it2 = it->second.begin();
	cout << *it2 << "\n";
*/
	for (auto it = groups.begin(); it != groups.end(); ++it) {
		cout << it->first << " : ";
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			cout << *it2 << ", ";
		}
	}
	cout << "\n";
}
