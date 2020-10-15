#include <iostream>
#include <queue>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        Node* left_most = root; // 从根节点开始
        while (left_most->left != NULL) {
            // 遍历这一层节点组织成的链表，为下一层的节点更新next指针
            Node* head = left_most;
            while (head != NULL) {
                // 第一种情况：父节点相同
                head->left->next = head->right;
                // 第二种情况：父节点相邻，即有next关系，根据父节点的关系连成当前节点的next关系
                if (head->next != NULL) {
                    head->right->next = head->next->left;
                }
                // 指针向后移动
                head = head->next;
            }
            // 来到下一层的最左节点
            left_most = left_most->left;
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        // 初始化队列同时将第一层节点加入队列中，即跟节点
        queue<Node*> Q;
        Q.push(root);

        // 外层循环迭代的是层数
        while (!Q.empty()) {
            // 记录当前队列大小
            int size = Q.size();
            // 遍历这一层所有节点
            for (int i = 0; i < size; i++) {
                // 从队首取出元素，即最左节点
                Node* node = Q.front();
                Q.pop();
                // 连接
                if (i < size - 1) {
                    node->next = Q.front();
                }
                // 拓展下一层节点
                if (node->left != NULL) {
                    Q.push(node->left);
                }
                if (node->right != NULL) {
                    Q.push(node->right);
                }
            }
        }
        return root;
    }
};


void print_next(Node* root) {
    Node* left_most = root;
    while (left_most != NULL) {
        Node* head = left_most;
        while (head != NULL) {
            cout << head->val << " ";
            if (head->next == NULL) {
                cout << "#" << " ";
            }
            head = head->next;
        }
        left_most = left_most->left;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    Node* res = s.connect(root);
    print_next(res);
    return 0;
}