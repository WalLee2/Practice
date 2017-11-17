#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

int b_search(vector<int> &nums, int target) {
	int low, high, mid;

	low = 0;
	high = (nums.size() - 1);
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (nums[mid] == target) {
			return (mid);
		} else if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return (-1);
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> returned_arr;
	int index;
	size_t i;

	if (nums1.empty() || nums2.empty()) {
		return (returned_arr);
	}
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	i = 0;
	while (i < nums1.size() && i < nums2.size()) {
		if (nums1.size() > nums2.size()) {
			index = b_search(nums1, nums2[i]);
			if (index != -1) {
				returned_arr.push_back(nums1[index]);
				i++;
			} else {
				i++;
			}
		} else {
			index = b_search(nums2, nums1[i]);
			if (index != -1) {
				returned_arr.push_back(nums1[index]);
				i++;
			} else {
				i++;
			}
		}
	}
	return (returned_arr);
}
int main(void) {
        vector<int> nums1, nums2;
        nums1.insert(nums1.end(), {1, 2, 2, 1});
        nums2.insert(nums2.end(), {1, 2, 2});
        vector<int> intersection(2);
        size_t i;

        intersection = intersect(nums1, nums2);
        for (i = 0; i < intersection.size(); i++) {
                cout << intersection[i];
		if (i < intersection.size() - 1) {
			cout << ", ";
		}
        }
	cout << '\n';
        return (0);
}
