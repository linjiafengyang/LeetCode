#include <iostream>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 };
 // BFS��ʹ�ö���ʵ�ֵĲ������
 class Solution {
 public:
     int maxLevelSum(TreeNode* root) {
         queue<TreeNode*> q;
         TreeNode* marker = nullptr; // �սڵ���Ϊ��ǣ���ʾÿһ��Ľ�β
         q.push(root);
         q.push(marker);
 
         int cur_level = 1, max_level = 1; // ��ǰ�㼶������ۼӺ͵Ĳ㼶Ϊ1
         int cur_sum = 0; // ��ǰ�ۼӺ�Ϊ0
         int max_sum = q.front()->val; // ����ۼӺ�Ϊ��һ��ڵ�ĺͣ������ڵ��ֵ
         
         while (q.size() > 0) {
             TreeNode* temp = q.front(); // ���е�����ڵ�
             q.pop();
 
             if (temp != marker) { // ������Ǳ��β�ڵ㣬���ڵ�ǰ�����
                 cur_sum += temp->val; // ���µ�ǰ���ۼӺ�
                 // ���ýڵ���ӽڵ����
                 if (temp->left != nullptr) {
                     q.push(temp->left);
                 }
                 if (temp->right != nullptr) {
                     q.push(temp->right);
                 }
             }
             else { // ����Ǳ��β�ڵ㣬��ǰ�����
                 // ��������ۼӺͣ������㼶
                 if (cur_sum > max_sum) {
                     max_sum = cur_sum;
                     max_level = cur_level;
                 }
                 cur_sum = 0; // ���õ�ǰ�ۼӺ�Ϊ0
                 cur_level++; // ��ǰ������1
                 if (!q.empty()) { // �����в��գ���ʾ�������нڵ���Ҫ�ۼ��жϣ�������һ�㣩����Ҫ�ӱ��β�ڵ�
                     q.push(marker);
                 }
                 //cout << max_sum << " " << max_level << endl;
             }
         }
         return max_level;
     }
 };

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int cur_level = 1, max_level = 1; // ��ǰ�㼶������ۼӺ͵Ĳ㼶Ϊ1
        int max_sum = q.front()->val; // ����ۼӺ�Ϊ��һ��ڵ�ĺͣ������ڵ��ֵ

        while (!q.empty()) {
            int q_size = q.size(); // ��¼ÿһ��ĸ�����������α���ʱ������Ҫ�����������
            int cur_sum = 0; // ��ǰ�ۼӺ�Ϊ0
            // ѭ���ò����нڵ㣬���ۼӺ�
            while (q_size > 0) {
                TreeNode* temp = q.front(); // ���е�����ڵ�
                q.pop();
                cur_sum += temp->val; // ���µ�ǰ���ۼӺ�
                // ���ýڵ���ӽڵ���ӣ��������ѭ��
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                q_size--;
            }
            // ��������ۼӺͣ������㼶
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                max_level = cur_level;
            }
            cur_level++; // ��ǰ������1
        }
        return max_level;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    root->right->left = new TreeNode(9);

    cout << s.maxLevelSum(root) << endl;
    return 0;
}