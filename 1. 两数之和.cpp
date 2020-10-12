#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ����
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>({ i, j });
                }
            }
        }
        return vector<int>();
    }
};

/*
* ����һ����ϣ������ÿһ�� x���������Ȳ�ѯ��ϣ�����Ƿ���� target - x��Ȼ�� x ���뵽��ϣ���У����ɱ�֤������ x ���Լ�ƥ�䡣
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return vector<int>({ it->second, i });
            }
            hashtable[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main() {
    Solution s;
    vector<int> nums({ 2, 7, 11, 15 });
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}