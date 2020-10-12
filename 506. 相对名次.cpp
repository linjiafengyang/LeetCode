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
        sort(sort_nums.begin(), sort_nums.end()); // 排序
        reverse(sort_nums.begin(), sort_nums.end()); // 倒置vector
        vector<string> res;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < sort_nums.size(); ++j) {
                if (nums[i] == sort_nums[j]) { // 双重循环判断
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
                        res.push_back(to_string(j + 1)); // 名次没有0，要加1
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
        map<int, int> m; // 利用map的自动排序特性
        for (int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }
        for (const auto& it : m) {
            // cout << it.first << " " << it.second << endl;
            result[it.second] = int2str(n); // 由于map是从小到大的顺序，传入数组size值，即名次为最后
            n--; // 数组size值减1，名次往前移
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