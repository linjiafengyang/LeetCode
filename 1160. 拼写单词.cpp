#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int words_size = words.size();

        vector<vector<int>> every_cishu; // ����������е��ʸ�����ĸ���ֵĴ���
        for (string word : words) {
            vector<int> cishu(26, 0); // �������ÿ�����ʸ�����ĸ���ֵĴ���
            for (char ch : word) {
                ++cishu[ch - 'a'];
            }
            every_cishu.push_back(cishu); // ����every_cishu
        }

        vector<int> chars_cishu(26, 0); // �������chars����ĸ���ֵĴ���
        for (char ch : chars) {
            ++chars_cishu[ch - 'a'];
        }

        int res = 0;
        for (int i = 0; i < words_size; i++) { // words_sizeҲ����every_cishu.size()
            bool flag = false;
            for (int j = 0; j < 26; j++) { // 26Ҳ����every_cishu[0].size()
                if (every_cishu[i][j] <= chars_cishu[j]) { // chars����ĸ���ֵĴ������ڵ�������ĸ�ĸ��������п�������
                    if (j == 25) { // ÿ����ĸ���������ˣ����������������Ϊtrue
                        flag = true;
                    }
                }
                else {
                    break; // ������ֱ��break
                }
                if (flag) {
                    //cout << words[i].size() << endl;
                    res += words[i].size(); // ���õ��ʵĳ��ȼ�������
                }
            }
        }
        return res;
    }
};

// �ٷ��ⷨ����ϣ�����
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_cnt; // �������chars����ĸ���ֵĴ���
        for (char ch : chars) {
            ++chars_cnt[ch];
        }

        int res = 0;
        for (string word : words) {
            unordered_map<char, int> word_cnt;
            for (char ch : word) {
                ++word_cnt[ch];
            }
            bool flag = true;
            for (char ch : word) {
                if (chars_cnt[ch] < word_cnt[ch]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res += word.size();
            }
        }
        return res;
    }
};

int main() {
    //vector<string> words({ "cat","bt","hat","tree" });
    vector<string> words({ "hello","world","leetcode" });
    //string chars = "atach";
    string chars = "welldonehoneyr";
    Solution s;
    cout << s.countCharacters(words, chars) << endl;
    return 0;
}