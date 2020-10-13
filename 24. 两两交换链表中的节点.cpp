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
 
 // 迭代
 class Solution {
 public:
     ListNode* swapPairs(ListNode* head) {
         ListNode* clone_head = new ListNode(0);
         clone_head->next = head; // clone_head->1->2->3->4
         ListNode* temp = clone_head; // clone_head->1->2->3->4
         while (temp->next != nullptr && temp->next->next != nullptr) { // temp后面没有节点或者只有一个节点，无需交换，结束循环
             ListNode* node1 = temp->next; // 第一个节点
             ListNode* node2 = temp->next->next; // 第二个节点，即temp->node1->node2
             temp->next = node2;
             node1->next = node2->next;
             node2->next = node1; // temp->node1->node2转成temp->node2->node1
             temp = node1; // node1和node2已完成交换，接下来从node1后开始
         }
         return clone_head->next; // 返回新链表的头节点
     }
 };
 // 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { // 没有节点或者只有一个节点，无需交换
            return head;
        }
        ListNode* newHead = head->next; // 新链表的头节点，为原始链表的第二个节点
        head->next = swapPairs(newHead->next); // 将其余节点进行两两交换，交换后新的头节点为head->next
        newHead->next = head; // 新链表的第二个节点，为原始链表的头节点
        return newHead; // 返回新链表的头节点
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