#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int clone_num = num;
        int sum = 0;
        for (int i = 2; i <= clone_num / 2; i++) { // 求因子需要注意这里会超时
            if (clone_num % i == 0) {
                sum = sum + clone_num / i; // 因子的和
                //cout << "sum:" << sum << endl;
            }
        }
        sum = sum + 1; // 加上因子1才是总和
        //cout << num << " " << sum << endl;
        return sum == num;
    }
};

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int clone_num = num;
        int sum = 0;
        for (int i = 2; i <= (int)sqrt(clone_num); i++) { // 求因子需要注意这里会超时
            if (clone_num % i == 0) {
                sum = sum + clone_num / i; // 因子的和
                sum = sum + i; // 不要忘记i，因子成对出现
                //cout << "sum:" << sum << endl;
            }
        }
        sum = sum + 1; // 加上因子1才是总和
        //cout << num << " " << sum << endl;
        return sum == num;
    }
};

int main() {
    Solution s;
    int num;
    cin >> num;
    cout << s.checkPerfectNumber(num) << endl;
    return 0;
}