class Solution {
public:
    map<int, int> mp;

    TreeNode* helper(int posStart, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder) {
        if (posStart < 0 || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[posStart]);
        int index = mp[root->val];

        root->left = helper(posStart - (inEnd - index) - 1, inStart, index - 1, inorder, postorder);
        root->right = helper(posStart - 1, index + 1, inEnd, inorder, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = NULL;
        if (inorder.size() == 0)
            return root;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return helper(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};