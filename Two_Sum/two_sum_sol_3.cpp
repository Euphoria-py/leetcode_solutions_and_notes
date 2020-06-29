#include "iostream"
#include "vector"

using namespace std;
using namespace __gnu_cxx;

int main() {

}

/*
 * This time we use double pointers to solve this problem.
 * Firstly do a sorting on the vector of number.
 * The complexity for sorting is O(nlogn).
 * The time complexity is O(nlogn) and the space complexity is O(n)
 * The double pointers approach need a new map or array to store the rank of vector before sorting.
 * Thus,it is not the best solution.
 * The best solution is two_sum_sol_2.cpp.
 */

class Solution {
public:
    // !!!!!! UNFINISHED.
    vector<int> twoSum(vector<int> &nums, int target) {

        int tmp1 = 0;
        int tmp2 = nums.size() - 1;

        // here we need to set a map to record the indices.
        // I'm too lazy to do that.
        int *pInt1 = &nums[0];
        int *pInt2 = &nums[nums.size() - 1];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (*pInt1 + *pInt2 < target) {
                ++pInt1;
                ++tmp1;
            } else if (*pInt1 + *pInt2 > target) {
                --pInt2;
                --tmp2;
            } else {
                return vector<int>{tmp1,tmp2};
            }
        }
        return vector<int>{-1,-1};
    }
};
