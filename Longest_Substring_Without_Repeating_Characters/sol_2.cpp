#include <cstring>
#include "iostream"

using namespace std;

#include "string"


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int tmp,tmp2,front,maxSize = 0;
        int map[128];
        memset(map, -1, 512);

        for (int back = 0; back < s.length(); ++back) {
            tmp2 = (int)s[back];
            tmp = map[tmp2];
            if (tmp != -1)
                front = tmp >= front && tmp < back ? tmp + 1 : front;
            map[tmp2] = back;
            maxSize = maxSize > back - front + 1 ? maxSize : back - front + 1;
        }

        return maxSize;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("auauaud");
}
