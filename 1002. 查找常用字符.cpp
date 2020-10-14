#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int A_size = A.size();
        vector<vector<int>> n_times; // 用来存放字符串数组中每个字符串的字母个数
        for (int i = 0; i < A_size; i++) {
            vector<int> times(26, 0); // 用于单个字符串26个字母统计，初始化为0
            for (int j = 0; j < A[i].size(); j++) {
                times[A[i][j] - 97] += 1; // A[i][j] - 97转化成数字下标，对字母计数
            }
            n_times.push_back(times); // 放入n_times
        }
        // 用于调试
        //for (int i = 0; i < n_times.size(); i++) {
        //    for (int j = 0; j < n_times[0].size(); j++) {
        //        cout << n_times[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        vector<string> res; // 结果字母串数组：用于存放结果字母
        for (int j = 0; j < 26; j++) {
            bool flag = false; // 标记该字母在所有字符串是否已循环结束
            int min = INT_MAX; // 记录字母次数最小值
            for (int i = 0; i < A_size - 1; i++) {
                if (n_times[i][j] > 0 && n_times[i + 1][j] > 0) { // 26个字母逐列比较，若等于0，即表明有字符串没有该字母，直接退出此次循环
                    int temp = n_times[i][j] >= n_times[i + 1][j] ? n_times[i + 1][j] : n_times[i][j];
                    if (min > temp) {
                        min = temp; // 更新最小次数，即表明所有字符串中这个字母只有min次出现，结果字符串数组中需要push这min次个字母
                    }
                    if (i + 1 == A_size - 1) { // 该字母在所有字符串已循环结束
                        flag = true;
                    }
                }
                else {
                    flag = false;
                    break;
                }
                if (flag) { // 该字母在所有字符串已循环结束，需要push到结果字符串数组中
                    for (int k = 0; k < min; k++) {
                        res.push_back(string(1, j + 97)); // 结果字符串数组中需要push这min次个字母
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minfreq(26, INT_MAX);
        for (const string& word : A) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; i++) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minfreq[i]; j++) {
                res.push_back(string(1, i + 'a'));
                //res.emplace_back(1, i + 'a');
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> A({ "dbaabcba","cabcdbab","cdbcbdad","abadbacc","bdddddaa","daddabab","baaaddaa","dccdaabd" });
    vector<string> res = s.commonChars(A);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}