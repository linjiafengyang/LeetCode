#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* father1 = nullptr;
    TreeNode* father2 = nullptr;
    int deep_x = 0, deep_y = 0;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, 0, x, y);
        return father1 != father2 && deep_x == deep_y; // 父节点不同且深度相同
    }
    void dfs(TreeNode* root, TreeNode* parent, int deep, int x, int y) {
        if (root == nullptr) {
            return;
        }
        if (root->val == x) {
            father1 = parent; // 记录其父节点
            deep_x = deep; // 记录其深度
            //cout << deep_x << endl;
        }
        else if (root->val == y) {
            father2 = parent;
            deep_y = deep;
            //cout << deep_y << endl;
        }
        else {
            dfs(root->left, root, deep + 1, x, y);
            dfs(root->right, root, deep + 1, x, y);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    int x, y;
    cin >> x >> y;

    Solution s;
    cout << s.isCousins(root, x, y) << endl;
    return 0;
}