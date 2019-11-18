
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    TreeNode* r;
    void finde(TreeNode* root) {
        if (root == NULL) return ;
        if (root->left != NULL) root->left->val = root->val * 2 + 1;
        if (root->right != NULL) root->right->val = root->val * 2 + 2;
        finde(root->left);
        finde(root->right);
        return ;
    }
    FindElements(TreeNode* root) 
    {
        r = root;
        root -> val = 0;
        finde(root);
    }

    bool find(int target) {
        int v = target;
        TreeNode *root = r;
        stack<int> stk;
        while (v > 0) {
            if (v % 2 == 0) stk.push(1);
            else stk.push(0);
            v = (v-1) / 2;
        }
        while (!stk.empty()) {
            v = stk.top();
            stk.pop();
            if (root == NULL) return false;
            if (v == 0) root = root->left;
            else root = root->right;
        }
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */