#include <iostream>
#include <vector>

using namespace std;

/*
// 超级烂的超时解法，自己都不想看了
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        if (x == 1 && y == 1 && (bound == 0 || bound == 1)) {
            return res;
        }
        if (x == 1 && y == 1) {
            return vector<int>(1, 2);
        }
        if (x == 1) {
            for (int num = 2; num <= bound; num++) {
                int i = 0;
                while (pow(y, i) < num) {
                    if (pow(y, i) + 1 == num) {
                        res.push_back(num);
                    }
                    i++;
                }
            }
        }
        if (y == 1) {
            for (int num = 2; num <= bound; num++) {
                int i = 0;
                while (pow(x, i) < num) {
                    if (pow(x, i) + 1 == num) {
                        //cout << num << endl;
                        res.push_back(num);
                    }
                    i++;
                    //cout << num << endl;
                }
            }
        }

        if (x != 1 && y != 1) {
            if (x < y) {
                int temp = x;
                x = y;
                y = temp;
            }
            int x_pow = 0, y_pow = 0;
            int x_mi = 0, y_mi = 0;
            while (x_pow <= bound) {
                x_pow = pow(x, x_mi++);
                //cout << x_pow << endl;
            }
            while (y_pow <= bound) {
                y_pow = pow(y, y_mi++);
            }
            x_mi = x_mi - 2;
            y_mi = y_mi - 2;
            //cout << x_mi << " " << y_mi << endl;
            for (int num = 2; num <= bound; num++) {
                for (int i = 0; i <= x_mi; i++) {
                    for (int j = 0; j <= y_mi; j++) {
                        if (pow(x, i) + pow(y, j) == num) {
                            if (!res.empty()) {
                                vector<int>::iterator it = find(res.begin(), res.end(), num);
                                if (it == res.end()) {
                                    res.push_back(num);
                                }
                            }
                            else {
                                res.push_back(num);
                            }
                        }
                        else if (pow(x, i) + pow(y, j) > num) {
                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
};
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        // 0 <= bound <= 10^6：2^19<10^6<2^20
        for (int i = 0; i < 20 && pow(x, i) <= bound; i++) {
            for (int j = 0; j < 20 && pow(y, j) <= bound; j++) {
                int num = pow(x, i) + pow(y, j);
                if (num <= bound) {
                    if (!res.empty()) {
                        // 用的是vector，需要去重（可以用set）
                        vector<int>::iterator it = find(res.begin(), res.end(), num);
                        if (it == res.end()) {
                            res.push_back(num); // vector中还没有该数，则push
                        }
                    }
                    else {
                        res.push_back(num);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    int x, y, bound;
    cin >> x >> y >> bound;
    Solution s;
    vector<int> res = s.powerfulIntegers(x, y, bound);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}