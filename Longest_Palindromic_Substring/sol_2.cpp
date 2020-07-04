#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int length = s.length() * 2 + 1;
        char *str = new char[length];
        str[0] = '#';
        for (int i = 0; i < s.length(); ++i) {
            str[2 * i + 1] = s[i];
            str[2 * i + 2] = '#';
        }

        int *p = new int[length]();

        int maxLength = 0;
        int middle = 0;

        for (int i = 0; i < length; ++i) {
            if (i >= maxLength) {
                int front = i - 1, back = i + 1;
                while (front >= 0 && back < length && str[front--] == str[back++])
                    ++p[i];
            } else {
                int mirror = 2 * middle - i;
                p[i] = max(p[mirror], maxLength - i);
            }
            if (p[i] > maxLength) {
                maxLength = p[i];
                middle = i;
            }
        }
        delete[]p;
        if (str[middle] == '#') {

            delete[] str;
            return s.substr(middle / 2 - maxLength / 2, maxLength / 2 * 2);
        }
        delete[] str;
        return s.substr(middle / 2 - maxLength / 2, maxLength / 2 * 2 + 1);

    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("cbbd") << endl;
    cout << s.longestPalindrome("fhiabcdedcbafji");
}
