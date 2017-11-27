#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using std::cout;
using std::sort;
using std::unordered_set;
using std::vector;

int binary_search(vector<int> longer, int low, int high, int target) {
	int mid;

	if (low <= high) {
		mid = low + (high - low) / 2;
		if (longer[mid] == target) {
			return (mid);
		}
		if (longer[mid] > target) {
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
			if (idx != -1) {
				start_idx = idx;
				no_dup.insert(longer[idx]);
			}
		}
	}

}

vector<int> intersection(vector<int> &num1, vector<int> &num2) {
	vector<int> result;
	unordered_set<int> no_dup;

	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end());
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

	num1.insert(num1.end(), {3, 1, 2});
	num2.insert(num2.end(), {1});
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
