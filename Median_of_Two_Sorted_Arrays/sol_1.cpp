#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        if ((n + m) % 2 == 0)
            return (getK(nums1, 0, nums2, 0, (n + m) / 2) + getK(nums1, 0, nums2, 0, (n + m - 1) / 2)) / 2;
        return getK(nums1, 0, nums2, 0, (n + m) / 2);
    }

    double getK(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k) {
        int length1 = nums1.size(), length2 = nums2.size();

        if (k == 0) {
            if (length1 - start1 <= 0) return nums2[start2];
            if (length2 - start2 <= 0) return nums1[start1];
            return nums1[start1] > nums2[start2] ? nums2[start2] : nums1[start1];
        }

        if (k == 1) {
            double tmp[4];
            tmp[0] = length1 - start1 >= 1 ? nums1[start1] : INT_MAX;
            tmp[1] = length2 - start2 >= 1 ? nums2[start2] : INT_MAX;
            tmp[2] = length1 - start1 >= 2 ? nums1[start1 + 1] : INT_MAX;
            tmp[3] = length2 - start2 >= 2 ? nums2[start2 + 1] : INT_MAX;
            sort(tmp, tmp + 4);
            return tmp[1];
        }
        if (length1 - start1 <= k / 2) return getK(nums1, start1, nums2, start2 + k / 2, k - k / 2);
        if (length2 - start2 <= k / 2) return getK(nums1, start1 + k / 2, nums2, start2, k - k / 2);
        if (nums1[start1 + k / 2] == nums2[start2 + k / 2]) return nums1[start1 + k / 2];

        if (nums1[start1 + k / 2] < nums2[start2 + k / 2])
            return getK(nums1, start1 + k / 2, nums2, start2, k - k / 2);

        return getK(nums1, start1, nums2, start2 + k / 2, k - k / 2);

    }

};

int main() {
    vector<int> nums1{};
    vector<int> nums2{2};
    Solution a;

    cout << a.findMedianSortedArrays(nums1, nums2);
}

