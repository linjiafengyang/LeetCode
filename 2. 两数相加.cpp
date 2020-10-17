#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
* �޷�ͨ��
* terminate called after throwing an instance of 'std::out_of_range'
  what():  stoll
*/
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        string num_l1 = "", num_l2 = "";
//        while (l1 != nullptr) {
//            num_l1.append(to_string(l1->val)); // �������е�ֵתΪ�ַ���
//            l1 = l1->next;
//        }
//        while (l2 != nullptr) {
//            num_l2.append(to_string(l2->val));
//            l2 = l2->next;
//        }
//        //cout << num_l1 << " " << num_l2 << endl;
//        reverse(num_l1.begin(), num_l1.end()); // ���ַ���
//        reverse(num_l2.begin(), num_l2.end());
//        //cout << num_l1 << " " << num_l2 << endl;
//        long long num_l1_long = stoll(num_l1); // �ַ���תlong long
//        long long num_l2_long = stoll(num_l2);
//        cout << num_l1_long << " " << num_l2_long << endl;
//        long long sum = num_l1_long + num_l2_long; // �����
//        //cout << sum << endl;
//        if (sum == 0) { // ��Ӧ��������ֻ��һ���ڵ㣬�ҽڵ�ֵΪ0�����
//            return new ListNode(0);
//        }
//        ListNode* res = new ListNode(0);
//        ListNode* last = res;
//        while (sum != 0) {
//            int yushu = sum % 10;
//            sum = sum / 10;
//            //cout << yushu << " ";
//            ListNode* temp = new ListNode(yushu);
//            last->next = temp;
//            last = temp;
//        }
//
//        return res->next;
//    }
//};

// �����벹�㣬������Ϊ������ sum(����ÿ��λ�ĺ͵Ľ��)���ϣ����ǽ�λ
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* last = res; // �ƶ�ָ��
        int sum = 0; // ÿ��λ�ļӺͽ��
        bool carry = false; // ��λ��־
        while (l1 != nullptr || l2 != nullptr) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry) { // 666
                sum++;
            }
            last->next = new ListNode(sum % 10);
            last = last->next;
            carry = sum >= 10 ? true : false;
        }
        if (carry) { // ���һλ��Ҫ��λ����1
            last->next = new ListNode(1);
        }
        return res->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(4);
    l1->next = new ListNode(8);
    l1->next->next = new ListNode(6);

    ListNode* l2 = new ListNode(6);
    l2->next = new ListNode(7);
    l2->next->next = new ListNode(8);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}