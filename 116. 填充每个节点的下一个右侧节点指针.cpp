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
        Node* left_most = root; // �Ӹ��ڵ㿪ʼ
        while (left_most->left != NULL) {
            // ������һ��ڵ���֯�ɵ�����Ϊ��һ��Ľڵ����nextָ��
            Node* head = left_most;
            while (head != NULL) {
                // ��һ����������ڵ���ͬ
                head->left->next = head->right;
                // �ڶ�����������ڵ����ڣ�����next��ϵ�����ݸ��ڵ�Ĺ�ϵ���ɵ�ǰ�ڵ��next��ϵ
                if (head->next != NULL) {
                    head->right->next = head->next->left;
                }
                // ָ������ƶ�
                head = head->next;
            }
            // ������һ�������ڵ�
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
        // ��ʼ������ͬʱ����һ��ڵ��������У������ڵ�
        queue<Node*> Q;
        Q.push(root);

        // ���ѭ���������ǲ���
        while (!Q.empty()) {
            // ��¼��ǰ���д�С
            int size = Q.size();
            // ������һ�����нڵ�
            for (int i = 0; i < size; i++) {
                // �Ӷ���ȡ��Ԫ�أ�������ڵ�
                Node* node = Q.front();
                Q.pop();
                // ����
                if (i < size - 1) {
                    node->next = Q.front();
                }
                // ��չ��һ��ڵ�
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