#include <iostream>

using namespace std;

// definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 其实要注意是二叉搜索树的特性，二叉搜索树中序遍历得到的值序列是递增有序的
    /*
    * 朴素的方法是经过一次中序遍历将值保存在一个数组中再进行遍历求解，
    * 我们也可以在中序遍历的过程中用 pre 变量保存前驱节点的值，这样即能边遍历边更新答案，不再需要显式创建数组来保存，
    * 需要注意的是 pre 的初始值需要设置成任意负数标记开头，下文代码中设置为-1
    */
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pre = -1;
        inorder(root, pre, res);
        return res;
    }
private:
    void inorder(TreeNode* root, int& pre, int& res) {
        if (root == NULL) {
            return;
        }
        // 中序遍历
        inorder(root->left, pre, res);
        if (pre == -1) {
            pre = root->val; // pre保存前驱节点的值
        }
        else {
            res = min(res, abs(root->val - pre));
            pre = root->val; // pre保存前驱节点的值
        }
        inorder(root->right, pre, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);

    Solution s;
    cout << s.getMinimumDifference(root) << endl;

    return 0;
}