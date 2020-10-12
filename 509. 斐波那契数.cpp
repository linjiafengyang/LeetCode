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
        for (int i = 2; i <= clone_num / 2; i++) { // ��������Ҫע������ᳬʱ
            if (clone_num % i == 0) {
                sum = sum + clone_num / i; // ���ӵĺ�
                //cout << "sum:" << sum << endl;
            }
        }
        sum = sum + 1; // ��������1�����ܺ�
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
        for (int i = 2; i <= (int)sqrt(clone_num); i++) { // ��������Ҫע������ᳬʱ
            if (clone_num % i == 0) {
                sum = sum + clone_num / i; // ���ӵĺ�
                sum = sum + i; // ��Ҫ����i�����ӳɶԳ���
                //cout << "sum:" << sum << endl;
            }
        }
        sum = sum + 1; // ��������1�����ܺ�
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