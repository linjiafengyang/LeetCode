#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.empty()) {
            return vector<string>();
        }
        vector<int> sort_nums = nums;
        sort(sort_nums.begin(), sort_nums.end()); // ����
        reverse(sort_nums.begin(), sort_nums.end()); // ����vector
        vector<string> res;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < sort_nums.size(); ++j) {
                if (nums[i] == sort_nums[j]) { // ˫��ѭ���ж�
                    if (j == 0) {
                        res.push_back("Gold Medal");
                    }
                    else if (j == 1) {
                        res.push_back("Silver Medal");
                    }
                    else if (j == 2) {
                        res.push_back("Bronze Medal");
                    }
                    else {
                        res.push_back(to_string(j + 1)); // ����û��0��Ҫ��1
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string int2str(int n) {
        if (n == 1) return "Gold Medal";
        if (n == 2) return "Silver Medal";
        if (n == 3) return "Bronze Medal";
        return to_string(n);
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> result(n);
        map<int, int> m; // ����map���Զ���������
        for (int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }
        for (const auto& it : m) {
            // cout << it.first << " " << it.second << endl;
            result[it.second] = int2str(n); // ����map�Ǵ�С�����˳�򣬴�������sizeֵ��������Ϊ���
            n--; // ����sizeֵ��1��������ǰ��
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums({ 5, 4, 6, 2, 1 });
    vector<string> res = s.findRelativeRanks(nums);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}