#include <iostream>
#include <vector>

using namespace std;

// 超时
//class Solution {
//public:
//    int numPairsDivisibleBy60(vector<int>& time) {
//        int res = 0;
//        for (int i = 0; i < time.size() - 1; i++) {
//            for (int j = i + 1; j < time.size(); j++) {
//                //cout << time[i] + time[j] << endl;
//                if ((time[i] + time[j]) % 60 == 0) {
//                    res++;
//                }
//            }
//        }
//        return res;
//    }
//};
/*
* 整数对60取模，可能有60种余数。故初始化一个长度为60的数组，统计各余数出现的次数。
* 遍历time数组，每个值对60取模，并统计每个余数值（0 - 59）出现的个数。因为余数部分需要找到合适的cp组合起来能被60整除。
* 余数为0的情况，只能同余数为0的情况组合（如60s、120s等等）。0的情况出现k次，则只能在k中任选两次进行两两组合。本题解单独写了个求组合数的方法，也可以用k * (k - 1) / 2表示。
* 余数为30的情况同上。
* 其余1与59组合，2与58组合，故使用双指针分别从1和59两头向中间遍历。1的情况出现m次，59的情况出现n次，则总共有m * n种组合。

作者：keen0126
链接：https ://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/solution/java-2ms-ji-bai-10000-by-keen0126/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> yushu_cishu(60, 0);
        for (int i = 0; i < time.size(); i++) {
            yushu_cishu[time[i] % 60] += 1;
        }
        //cout << yushu_cishu[0] << " " << yushu_cishu[30] << endl;
        int res = 0;
        res += yushu_cishu[0] * (yushu_cishu[0] - 1) / 2;
        res += yushu_cishu[30] * (yushu_cishu[30] - 1) / 2;
        int i = 1, j = 59;
        while (i < j) {
            res += yushu_cishu[i] * yushu_cishu[j];
            i++;
            j--;
        }

        return res;
    }
};

int main() {
    Solution s;
    //vector<int> time = { 30, 20, 150, 100, 40 };
    vector<int> time = { 309,148,402,199,180,170,293,72,165,318,178,444,105,265,311,223,242,11,341,232,37,90,214,73,15,431,82,323,291,296,234,32,21,156,235,379,275,273,69,91,275,93,281,212,478,365,126,457,268,85,217,144,325,376,357,457,129,189,140,384,21,342,416,34,252,216,311,228,380,149,123,276,458,225,271,489,125,377,440,459,428,52,372,337,55,1,183,214,42,174,193,196,230,144,213,292,34,8,61,432,23,24,128,416,136,196,290,406,103,394,408,97,222,418,122,94,171,214,418,458,141,356,212,217,428,183,488,471,29,441,190,133,152,448,390,40,180,28,156,43,299,
        251,250,48,423,437,417,303,81,284,448,459,30,273,141,111,61,366,157,434,155,114,208,423,56,8,95,461,351,448,244,244,121,112,374,267,26,176,203,24,142,98,372,208,438,335,432,456,161,157,353,161,235,395,389,208 };
    //vector<int> time = { 30, 40, 90, 30, 90 };
    cout << s.numPairsDivisibleBy60(time) << endl;
    return 0;
}