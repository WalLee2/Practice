#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
	long long result = 0;
	int n = numbers.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (((long long)(numbers[i])) * numbers[j] > result) {
				result = ((long long)(numbers[i])) * numbers[j];
			}
		}
	}
	return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
	int n = numbers.size();

	int max_idx1 = -1;
	for (int i = 0; i < n; ++i) {
		if ((max_idx1 == -1) || (numbers[i] > numbers[max_idx1])) {
			max_idx1 = i;
		}
	}

	int max_idx2 = -1;
	for (int j = 0; j < n; ++j) {
		if ((j != max_idx1) && ((max_idx2 == -1 ||
		    (numbers[j] > numbers[max_idx2])))) {
			max_idx2 = j;
		    }
	}
/*	cout << max_idx1 << ' ' << max_idx2 << "\n";*/
	return ((long long)(numbers[max_idx1]) * numbers[max_idx2]);
}

int main() {
/*	while (true) {
		int n = rand() % 10 + 2;
		cout << n << "\n";
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			a.push_back(rand() % 10000);
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << "\n";
		long long res1 = MaxPairwiseProduct(a);
		long long res2 = MaxPairwiseProductFast(a);
		if (res1 != res2) {
			cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
			break;
		}
		else {
			cout << "OK\n";
		}
	}
*/
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	long long result = MaxPairwiseProductFast(numbers);
	cout << result << "\n";
	return 0;
}
