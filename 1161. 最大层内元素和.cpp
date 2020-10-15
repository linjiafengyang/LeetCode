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
 // BFS：使用队列实现的层序遍历
 class Solution {
 public:
     int maxLevelSum(TreeNode* root) {
         queue<TreeNode*> q;
         TreeNode* marker = nullptr; // 空节点作为标记，表示每一层的结尾
         q.push(root);
         q.push(marker);
 
         int cur_level = 1, max_level = 1; // 当前层级和最大累加和的层级为1
         int cur_sum = 0; // 当前累加和为0
         int max_sum = q.front()->val; // 最大累加和为第一层节点的和，即根节点的值
         
         while (q.size() > 0) {
             TreeNode* temp = q.front(); // 队列弹出最顶节点
             q.pop();
 
             if (temp != marker) { // 如果不是标记尾节点，则在当前层继续
                 cur_sum += temp->val; // 更新当前层累加和
                 // 将该节点的子节点入队
                 if (temp->left != nullptr) {
                     q.push(temp->left);
                 }
                 if (temp->right != nullptr) {
                     q.push(temp->right);
                 }
             }
             else { // 如果是标记尾节点，则当前层结束
                 // 更新最大累加和，和最大层级
                 if (cur_sum > max_sum) {
                     max_sum = cur_sum;
                     max_level = cur_level;
                 }
                 cur_sum = 0; // 设置当前累加和为0
                 cur_level++; // 当前层数加1
                 if (!q.empty()) { // 若队列不空，表示后续还有节点需要累加判断（即还有一层），需要加标记尾节点
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

        int cur_level = 1, max_level = 1; // 当前层级和最大累加和的层级为1
        int max_sum = q.front()->val; // 最大累加和为第一层节点的和，即根节点的值

        while (!q.empty()) {
            int q_size = q.size(); // 记录每一层的个数（很灵活，层次遍历时按层需要考虑用这个）
            int cur_sum = 0; // 当前累加和为0
            // 循环该层所有节点，求累加和
            while (q_size > 0) {
                TreeNode* temp = q.front(); // 队列弹出最顶节点
                q.pop();
                cur_sum += temp->val; // 更新当前层累加和
                // 将该节点的子节点入队，用于外层循环
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                q_size--;
            }
            // 更新最大累加和，和最大层级
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                max_level = cur_level;
            }
            cur_level++; // 当前层数加1
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