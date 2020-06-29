#include "iostream"
#include "vector"
#include "map"
#include "hash_map"
#include "unordered_map"

using namespace std;
using namespace __gnu_cxx;

int main() {

}

/*
 * This is a better solution for two-sum problem.
 * It use map to store the element in the vector.
 * The time complexity of access elements in a map is O(1).
 * The time complexity is O(n) and the space complexity is O(n)
 * Using hash_map to replace map cannot speed up.
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        unordered_map<int, int> map;
//        map<int,int> map;
//        hash_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            int second = target - nums[i];
            if (map.count(second) == 1 && map[second] != i)
                return vector<int>{i, map[second]};
            else
                map[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};
