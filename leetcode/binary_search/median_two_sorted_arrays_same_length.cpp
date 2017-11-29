#include <iostream>
#include <vector>

using std::vector;

int max(int a, int b) {
        return (a > b ? a : b);
}

int min(int a, int b) {
        return (a < b ? a : b);
}

int median(vector<int> , int); /* to get median of a sorted array */

int getMedian(vector<int> v1, vector<int> v2, int n)
{
	vector<int>::iterator ptr_v1;
	vector<int>::iterator ptr_v2;
	/* return -1  for invalid input */
	if (n <= 0)
		return -1;
	if (n == 1)
		return (v1[0] + v2[0] / 2);
	if (n == 2)
		return (max(v1[0], v2[0]) + min(v1[1], v2[1]) / 2);

	int m1 = median(v1, n);
	int m2 = median(v2, n);

	if (m1 == m2)
		return (m1);
	/* if m1 < m2 then median must exist in ar1[m1....] and
	   ar2[....m2] */
	if (m1 < m2)
	{
		if (n % 2 == 0)
			return (getMedian(ptr_v1 + (n / 2) - 1, v2, n - (n / 2) + 1));
		return (getMedian(ptr_v1 + (n / 2), v2, n - n/2));
	}
	if (n % 2 == 0)
		return (getMedian(ptr_v2 + (n / 2) - 1, v1, n - (n / 2) + 1));
	return (getMedian(ptr_v2 + (n / 2), v1, n - (n / 2)));
}

int median(vector<int> v, int n)
{
	if (n % 2 == 0)
		return (v[n/2] + v[n/2-1])/2;
	else
		return v[n/2];
}
int main()
{
	vector<int> v1, v2;
	v1.insert(v1.begin(), {1, 2, 3, 6});
	v2.insert(v2.begin(), {4, 6, 8, 10});
	if (v1.size() == v2.size())
		printf("Median is %d", getMedian(v1, v2, (int)v1.size()));
	else
		printf("Doesn't work for arrays of unequal size");
	return 0;
}
