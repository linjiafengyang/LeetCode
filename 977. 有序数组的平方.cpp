#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& A) {
//        vector<int> res;
//        for (int i = 0; i < A.size(); i++) {
//            res.push_back(A[i] * A[i]);
//        }
//        sort(res.begin(), res.end());
//        return res;
//    }
//};

// Ë«Ö¸Õë
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int A_size = A.size();
        vector<int> res(A_size);
        for (int i = 0, j = A_size - 1, pos = A_size - 1; i <= j;) {
            if (A[i] * A[i] > A[j] * A[j]) {
                res[pos] = A[i] * A[i];
                ++i;
            }
            else {
                res[pos] = A[j] * A[j];
                --j;
            }
            --pos;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> A = { -4, -1, 0, 3, 10 };
    vector<int> res = s.sortedSquares(A);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}