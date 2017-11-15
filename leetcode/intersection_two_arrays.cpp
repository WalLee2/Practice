#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

int b_search(vector<int> &nums, int target, vector<int> &found_idx) {
	int low, high, mid, i;

	low = i = 0;
	high = (nums.size() - 1);
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (nums[mid] == target && found_idx[i] != mid) {
			found_idx.push_back(mid);
			return (mid);
		} else if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
		i++;
	}
	return (-1);
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> returned_arr;
	vector<int> found_idx;
	int index;
	size_t i;

	if (nums1.empty() || nums2.empty()) {
		return (returned_arr);
	}
	sort(nums1.begin(), nums2.end());
	sort(nums2.begin(), nums2.end());
	i = 0;
	while (i < nums1.size() && i < nums2.size()) {
		if (nums1.size() > nums2.size()) {
			index = b_search(nums1, nums2[i], found_idx);
			if (index != -1) {
				returned_arr.push_back(nums1[index]);
				i++;
			} else {
				i++;
			}
		} else {
			index = b_search(nums2, nums1[i], found_idx);
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
        nums1.insert(nums1.end(), {1});
        nums2.insert(nums2.end(), {1, 1});
        vector<int> intersection(1);
        size_t i;

        intersection = intersect(nums1, nums2);
        for (i = 0; i < intersection.size(); i++) {
                cout << "Number in array" << intersection[i] << '\n';
        }
        return (0);
}
