#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<long long>& numbers) {
	int i, j, size;
	int64_t result;

	result = 0;
	size = numbers.size();
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (numbers[i] * numbers[j] > result) {
				result = numbers[i] * numbers[j];
			}
		}
	}
	return (result);
}
int main(void) {
	int num, i;
	long long result;

	cin >> num;
	vector<long long> numbers(num);
	for (i = 0; i < num; i++) {
		cin >> numbers[i];
	}
	result = MaxPairwiseProduct(numbers);
	cout << result << "\n";
	return (0);
}
