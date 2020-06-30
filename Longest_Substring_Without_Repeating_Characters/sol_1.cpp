#include "string"
#include "unordered_map"
#include "iostream"

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int front = 0;
        int maxSize = 0;
        unordered_map<char, int>::iterator it;
        for (int back = 0; back < s.length(); ++back) {
            it = map.find(s[back]);
            if (it != map.end())
                if (it->second >= front && it->second < back)
                    front = it->second + 1;

            map[s[back]] = back;
            maxSize = maxSize > back - front + 1 ? maxSize : back - front + 1;
        }
        return maxSize;

    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("au");
}
