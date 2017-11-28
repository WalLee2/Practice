#include <vector>
#include <iostream>
/**
 * find_median - Find the middle number given two vectors
 * @nums1: Vector containing n elements
 * @nums2: Vector containing n elements
 * Return: The middle number or average of the two middle numbers
 */
using std::vector;
using std::cout;

double find_median(vector<int>& nums1, vector<int>& nums2) {
	double result;
	vector<double> merged;
	size_t i, j, idx;

	result = 0;
	i = j = 0;
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] < nums2[j]) {
			merged.push_back((double)nums1[i]);
			i++;
		} else {
			merged.push_back((double)nums2[j]);
			j++;
		}
	}
	while (i < nums1.size()) {
		merged.push_back((double)nums1[i]);
		i++;
	}
	while (j < nums2.size()) {
		merged.push_back((double)nums2[j]);
		j++;
	}
	if (!merged.empty()) {
		if (merged.size()) {
			idx = (merged.size() - 1) / 2;
		}
		if (merged.size() % 2 == 0) {
			result = ((merged[idx] + merged[idx + 1]) / 2);
		} else {
			result = merged[idx];
		}
	}
	return (result);
}
/**
 * main - Used for testing find_median function.
 *
 */
int main(void) {
	vector<int> vec1, vec2, vec3, vec4;
	double result;

	vec1.insert(vec1.end(), {1, 2, 3, 5, 6});
	vec2.insert(vec2.end(), {});
	result = find_median(vec1, vec2);
	cout << result << '\n';
	vec3.insert(vec3.end(), {1, 2, 3});
	vec4.insert(vec4.end(), {4, 5, 6, 7, 8, 9, 10});
	result = find_median(vec3, vec4);
	cout << result << '\n';
	return (0);
}
