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
class Solution {
public:
	TreeNode* firstStart = NULL;
	TreeNode* secondEnd = NULL;
	TreeNode* prev = NULL;
	void get(TreeNode* root) {
		if (!root) return;

		get(root->left);
		if (prev && prev->val > root->val) {
			if (firstStart == NULL) {
				firstStart = prev;
			}
			secondEnd = root;
		}

		prev = root;
		get(root->right);

		return;
	}


	void recoverTree(TreeNode* root) {
		get(root);
		swap(firstStart->val, secondEnd->val);
		return;
	}
};