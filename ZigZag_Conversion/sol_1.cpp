#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;
        int size =  (numRows << 1)- 2;

        string str;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.length(); j += size) {
                str += s[j];
                if (i != 0 && i != numRows - 1) {
                    int now = j + size - (i << 1);
                    if (now >= s.size()) break;
                    str += s[now];
                }
            }
        }
        return str;
    }
};

int main() {
    Solution solution;

    cout << solution.convert("ABC", 3);
}