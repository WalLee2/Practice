#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long FastMaxPairwise(const vector<long long> &numbers) {
	int i, size, max_idx1, max_idx2;

	size = numbers.size();
	max_idx1 = -1;
	for (i = 0; i < size; i++) {
		if (max_idx1 == -1 || numbers[i] > numbers[max_idx1]) {
			max_idx1 = i;
		}
	}
	max_idx2 = -1;
	for (i = 0; i < size; i++) {
		if ((i != max_idx1) && (max_idx2 == -1 ||
		     numbers[i] > numbers[max_idx2])) {
			max_idx2 = i;
		}
	}
	return (numbers[max_idx1] * numbers[max_idx2]);
}

int main(void) {
	int size, i;
	long long result;

	cin >> size;
	vector<long long> numbers(size);
	for (i = 0; i < size; i++) {
		cin >> numbers[i];
	}
	result = FastMaxPairwise(numbers);
	cout << result << "\n";
	return (0);
}
