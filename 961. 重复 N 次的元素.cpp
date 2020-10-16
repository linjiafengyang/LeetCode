#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int A_size = A.size();
        vector<int> freq(10000, 0);
        for (int i = 0; i < A_size; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == A_size / 2) {
                return A[i];
            }
        }
        return 0;
    }
};

int main() {
    vector<int> A = { 1, 2, 3, 3 };
    Solution s;
    cout << s.repeatedNTimes(A) << endl;
    return 0;
}