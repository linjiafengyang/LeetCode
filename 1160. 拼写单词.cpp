#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int words_size = words.size();

        vector<vector<int>> every_cishu; // 用来存放所有单词各个字母出现的次数
        for (string word : words) {
            vector<int> cishu(26, 0); // 用来存放每个单词各个字母出现的次数
            for (char ch : word) {
                ++cishu[ch - 'a'];
            }
            every_cishu.push_back(cishu); // 放入every_cishu
        }

        vector<int> chars_cishu(26, 0); // 用来存放chars中字母出现的次数
        for (char ch : chars) {
            ++chars_cishu[ch - 'a'];
        }

        int res = 0;
        for (int i = 0; i < words_size; i++) { // words_size也就是every_cishu.size()
            bool flag = false;
            for (int j = 0; j < 26; j++) { // 26也就是every_cishu[0].size()
                if (every_cishu[i][j] <= chars_cishu[j]) { // chars中字母出现的次数大于单词中字母的个数，即有可能满足
                    if (j == 25) { // 每个字母都遍历过了，即满足条件，标记为true
                        flag = true;
                    }
                }
                else {
                    break; // 不满足直接break
                }
                if (flag) {
                    //cout << words[i].size() << endl;
                    res += words[i].size(); // 将该单词的长度加入结果中
                }
            }
        }
        return res;
    }
};

// 官方解法：哈希表计数
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_cnt; // 用来存放chars中字母出现的次数
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