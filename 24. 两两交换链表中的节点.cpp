#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
 // ����
 class Solution {
 public:
     ListNode* swapPairs(ListNode* head) {
         ListNode* clone_head = new ListNode(0);
         clone_head->next = head; // clone_head->1->2->3->4
         ListNode* temp = clone_head; // clone_head->1->2->3->4
         while (temp->next != nullptr && temp->next->next != nullptr) { // temp����û�нڵ����ֻ��һ���ڵ㣬���轻��������ѭ��
             ListNode* node1 = temp->next; // ��һ���ڵ�
             ListNode* node2 = temp->next->next; // �ڶ����ڵ㣬��temp->node1->node2
             temp->next = node2;
             node1->next = node2->next;
             node2->next = node1; // temp->node1->node2ת��temp->node2->node1
             temp = node1; // node1��node2����ɽ�������������node1��ʼ
         }
         return clone_head->next; // �����������ͷ�ڵ�
     }
 };
 // �ݹ�
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { // û�нڵ����ֻ��һ���ڵ㣬���轻��
            return head;
        }
        ListNode* newHead = head->next; // �������ͷ�ڵ㣬Ϊԭʼ����ĵڶ����ڵ�
        head->next = swapPairs(newHead->next); // ������ڵ���������������������µ�ͷ�ڵ�Ϊhead->next
        newHead->next = head; // ������ĵڶ����ڵ㣬Ϊԭʼ�����ͷ�ڵ�
        return newHead; // �����������ͷ�ڵ�
    }
};

int main() {
    // 1->2->3->4
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* four = new ListNode(4);
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = nullptr;

    Solution s;
    ListNode* res = s.swapPairs(first);
    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}