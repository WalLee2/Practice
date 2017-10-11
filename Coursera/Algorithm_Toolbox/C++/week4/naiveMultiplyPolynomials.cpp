#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> multiplyPoly(vector<int> &A, vector<int> &B, vector<int> &C, int n) {
	int i, j;

	for (i = 0; i < (n - 1); ++i) {
		for (j = 0; j < (n - 1); ++j) {
			C[i + j] += (A[i] * B[j]);
		}
	}
	return (C);
}

int main(void) {
	int n, i, sum;

	cin >> n;
	sum = n + n - 1;
	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(sum);

	for (i = 0; i < n; ++i) {
		cin >> A[i];
	}
	for (i = 0; i < n; ++i) {
		cin >> B[i];
	}
	for (i = 0; i < sum; ++i) {
		C[i] = 0;
	}
	C = multiplyPoly(A, B, C, sum);
	for (i = 0; i < sum; ++i) {
		cout << C[i];
		if (i < sum - 1) {
			cout << ", ";
		}
	}
	cout << '\n';
	return (0);
}
