#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int A_size = A.size();
        vector<vector<int>> n_times; // ��������ַ���������ÿ���ַ�������ĸ����
        for (int i = 0; i < A_size; i++) {
            vector<int> times(26, 0); // ���ڵ����ַ���26����ĸͳ�ƣ���ʼ��Ϊ0
            for (int j = 0; j < A[i].size(); j++) {
                times[A[i][j] - 97] += 1; // A[i][j] - 97ת���������±꣬����ĸ����
            }
            n_times.push_back(times); // ����n_times
        }
        // ���ڵ���
        //for (int i = 0; i < n_times.size(); i++) {
        //    for (int j = 0; j < n_times[0].size(); j++) {
        //        cout << n_times[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        vector<string> res; // �����ĸ�����飺���ڴ�Ž����ĸ
        for (int j = 0; j < 26; j++) {
            bool flag = false; // ��Ǹ���ĸ�������ַ����Ƿ���ѭ������
            int min = INT_MAX; // ��¼��ĸ������Сֵ
            for (int i = 0; i < A_size - 1; i++) {
                if (n_times[i][j] > 0 && n_times[i + 1][j] > 0) { // 26����ĸ���бȽϣ�������0�����������ַ���û�и���ĸ��ֱ���˳��˴�ѭ��
                    int temp = n_times[i][j] >= n_times[i + 1][j] ? n_times[i + 1][j] : n_times[i][j];
                    if (min > temp) {
                        min = temp; // ������С�����������������ַ����������ĸֻ��min�γ��֣�����ַ�����������Ҫpush��min�θ���ĸ
                    }
                    if (i + 1 == A_size - 1) { // ����ĸ�������ַ�����ѭ������
                        flag = true;
                    }
                }
                else {
                    flag = false;
                    break;
                }
                if (flag) { // ����ĸ�������ַ�����ѭ����������Ҫpush������ַ���������
                    for (int k = 0; k < min; k++) {
                        res.push_back(string(1, j + 97)); // ����ַ�����������Ҫpush��min�θ���ĸ
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