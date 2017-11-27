#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using std::cout;
using std::sort;
using std::unordered_set;
using std::vector;

size_t binary_search(vector<int> longer, size_t low, size_t high, int target) {
	size_t mid;

	if (low <= high) {
		mid = low + (high - low) / 2;
		if (longer[mid] == target) {
			return (mid);
		} else if (longer[mid] > target) {
			return (binary_search(longer, low, (mid - 1), target));
		} else {
			return (binary_search(longer, (mid + 1), high, target));
		}
	}
	return (-1);
}

void search_insert(vector<int>longer, vector<int>shorter, unordered_set<int> &no_dup) {
	int idx;
	size_t i, size, start_idx;

	size = longer.size();
	start_idx = 0;
	if (!longer.empty() && !shorter.empty()) {
		for (i = 0; i < size; i++) {
			idx = binary_search(longer, start_idx, (size - 1), shorter[i]);
			cout << "value of idx: " << idx << '\n';
			if (idx != -1) {
				start_idx = (size_t)idx + 1;
				no_dup.insert(longer[idx]);
				auto itr = no_dup.find(longer[idx]);
				cout << "no_dup value: " << *itr << '\n';
			}
		}
	}

}

vector<int> intersection(vector<int> &num1, vector<int> &num2) {
	vector<int> result;
	unordered_set<int> no_dup;

	sort(num1.begin(), num1.end());
	for (size_t i = 0; i < (num1.size() - 1); i++) {
		cout << num1[i] << ", ";
	}
	cout << '\n';
	sort(num2.begin(), num2.end());
	for (size_t i = 0; i < (num2.size() - 1); i++) {
		cout << num2[i] << ", ";
	}
	cout << '\n';
	if (num1.size() > num2.size()) {
		search_insert(num1, num2, no_dup);
	} else {
		search_insert(num2, num1, no_dup);
	}
	if (!no_dup.empty()) {
		result.insert(result.end(), no_dup.begin(), no_dup.end());
	}
	return (result);
}

int main(void) {
	vector<int> num1, num2, result;

	num1.insert(num1.end(), {6,27,25,20,71,43,68,36,46,50});
	num2.insert(num2.end(), {82,5,78,62,23,31,75});
	result = intersection(num1, num2);
	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i < result.size() - 1) {
			cout << ", ";
		}
	}
	cout << '\n';
	return (0);
}
