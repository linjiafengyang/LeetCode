#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string res("");
        int sum = 0;
        int times = 0; // ��¼λ��������pow����������λ��-1
        while (num) {
            int yushu = num % 7; // ����
            sum = sum + yushu * pow(10, times);
            times++;
            num = num / 7;
        }
        res = to_string(sum); // int to string�⺯��
        return res;
    }
};

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string res("");
        bool negative = false;
        if (num < 0) {
            negative = true;
            num = -num; // ����תΪ��������
        }
        while (num) {
            int yushu = num % 7;
            char yushu2char = yushu + '0'; // intת��char
            res.push_back(yushu2char);
            num = num / 7;
        }
        if (negative) {
            res.push_back('-'); // ������-
        }
        reverse(res.begin(), res.end()); // ��string�⺯��
        return res;
    }
};

int main() {
    Solution s;
    int num;
    cin >> num;
    cout << s.convertToBase7(num) << endl;

    return 0;
}