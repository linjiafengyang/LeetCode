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
    // ��ʵҪע���Ƕ��������������ԣ�������������������õ���ֵ�����ǵ��������
    /*
    * ���صķ����Ǿ���һ�����������ֵ������һ���������ٽ��б�����⣬
    * ����Ҳ��������������Ĺ������� pre ��������ǰ���ڵ��ֵ���������ܱ߱����߸��´𰸣�������Ҫ��ʽ�������������棬
    * ��Ҫע����� pre �ĳ�ʼֵ��Ҫ���ó����⸺����ǿ�ͷ�����Ĵ���������Ϊ-1
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
        // �������
        inorder(root->left, pre, res);
        if (pre == -1) {
            pre = root->val; // pre����ǰ���ڵ��ֵ
        }
        else {
            res = min(res, abs(root->val - pre));
            pre = root->val; // pre����ǰ���ڵ��ֵ
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