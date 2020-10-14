#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        if (N == 1) {
            return false;
        }
        if (N == 2) {
            return true;
        }
        if (N == 3) {
            return false;
        }
        vector<int> yinzi;
        for (int i = 1; i <= sqrt(N); i++) {
            if (N % i == 0) {
                yinzi.push_back(i);
                if (i != N / i && N != N / i) {
                    yinzi.push_back(N / i);
                }
            }
        }
        sort(yinzi.begin(), yinzi.end());
        for (int i = 0; i < yinzi.size(); i++) {
            //cout << yinzi[i] << endl;
            return !divisorGame(N - yinzi[i]);
        }
        //divisor(N, yinzi);
        return false;
    }
};

class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};

class Solution {
public:
    bool divisorGame(int N) {
        vector<int> f(N + 5, false);

        f[1] = false;
        f[2] = true;
        for (int i = 3; i <= N; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0 && !f[i - j]) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[N];
    }
};

int main() {
    int N;
    cin >> N;
    Solution s;
    cout << s.divisorGame(N) << endl;
    return 0;
}