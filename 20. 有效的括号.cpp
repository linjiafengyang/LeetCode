#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> cstack;
        for (auto c : s) {
            if (c == '[') {
                cstack.push(']');
            }
            else if (c == '(') {
                cstack.push(')');
            }
            else if (c == '{') {
                cstack.push('}');
            }
            else if (cstack.empty() || c != cstack.top()) { // �пգ���һ���ַ�Ϊ)]}����һ������Ϊfalse
                return false;
            }
            else {
                cstack.pop();
            }
        }
        return cstack.empty();
    }
};

int main() {
    Solution s;
    string str;
    cin >> str;
    cout << s.isValid(str) << endl;
    return 0;
}