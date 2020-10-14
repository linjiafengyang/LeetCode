#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) { // 0不需要走下面，直接返回1
            return 1;
        }

        string res = "";
        while (N) {
            int yushu = N % 2;
            N = N / 2;
            if (yushu == 1) { // 10->1010, 5->010
                res = res + "0";
            }
            else if (yushu == 0) {
                res = res + "1";
            }
        }
        reverse(res.begin(), res.end()); // 10->0101, 5->010

        int ans = 0;
        for (int i = 0; i < res.size(); i++) {
            ans = ans * 2 + res[i] - '0'; // 再转成2进制int
        }
        return ans;
    }
};

int main() {
    Solution s;
    int N;
    cin >> N;
    cout << s.bitwiseComplement(N) << endl;
    return 0;
}