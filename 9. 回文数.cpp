#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) { // ��������Ϊ0���ɱ�10����������λ����0��
            return false;
        }
        int reverse_x = 0;
        while (x > reverse_x) {
            reverse_x = reverse_x * 10 + x % 10;
            x = x / 10;
        }
        //cout << x << " " << reverse_x << endl;
        return x == reverse_x || x == reverse_x / 10; // λ��Ϊ����ʱ����Ҫ�ж�x == reverse_x / 10
    }
};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.isPalindrome(x) << endl;
    return 0;
}