#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        vector<vector<int>> dp(length, vector<int>(length));
        int maxLen = 1;
        int startPoint = 0;
        for (int i = 0; i < length; ++i) {
            dp[i][i] = 1;
        }
        for (int j = 1; j < length; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j]) {
                    if (j - i + 1 > maxLen) {
                        startPoint = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startPoint, maxLen);
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("cbbd");

}