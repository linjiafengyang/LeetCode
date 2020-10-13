#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long temp = x; // 越界溢出陷阱
        int weishu = 0;
        while (temp) {
            int yushu = temp % 10;
            temp = temp / 10;
            weishu++; // 求位数
        }
        weishu = weishu - 1; // 位数-1，用于pow
        long long res = 0; // 越界溢出陷阱
        while (x) {
            int yushu = x % 10;
            x = x / 10;
            res = res + yushu * pow(10, weishu);
            weishu--;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : (int)res; // 越界溢出陷阱
    }
};

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res < INT_MIN || res > INT_MAX) ? 0 : (int)res;
    }
};

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);//C++11
        if (s[0] == '-') std::reverse(s.begin() + 1, s.end());
        else std::reverse(s.begin(), s.end());
        long long int res = stoll(s);// C++11: stoi = string to int; stol = string to long; stoll = string to long long
        if (res > INT_MAX || res < INT_MIN) return 0;
        return (int)res;
    }
};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.reverse(x) << endl;
    return 0;
}