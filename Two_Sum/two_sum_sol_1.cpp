#include "iostream"
#include "vector"

using namespace std;

int main() {

}

/*
 * This is the regular solution for two-sum problem.
 * It scan every elements in the vector.
 * The time complexity is O(n^2) and space complexity is O(n)
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
              if (nums[i] + nums[j] == target && i != j)
                return vector<int>{i, j};
            }
        }
        return vector<int>{-1,-1};

    }
};
