#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::cout;
using std::unordered_map;

vector<int> intersection(vector<int> &num1, vector<int> &num2) {
	unordered_map<int, int> my_map;
	vector<int> returned;
	size_t i;

	for (i = 0; i < num1.size(); i++) {
		if (my_map.find(num1[i]) == my_map.end()) {
			my_map[num1[i]] = 1;
		} else {
			my_map[num1[i]]++;
		}
	}
	for (i = 0; i < num2.size(); i++) {
		if (my_map.find(num2[i]) != my_map.end() && my_map[num2[i]] > 0) {
			returned.push_back(num2[i]);
			my_map[num2[i]]--;
		}
	}
	return (returned);
}

int main(void) {
	vector<int> num1, num2, intersected(2);
	size_t i;

	num1.insert(num1.end(), {1, 2, 2, 1});
	num2.insert(num2.end(), {2, 2});
	intersected = intersection(num1, num2);
	for (i = 0; i < intersected.size(); i++) {
		cout << intersected[i];
		if (i < intersected.size() - 1) {
			cout << ", ";
		}
	}
	cout << '\n';
	return (0);
}
