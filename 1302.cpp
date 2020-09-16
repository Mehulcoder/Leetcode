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
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int maxLevel = 0, ans = 0;
	void getLevel(TreeNode* root, int lev) {
		if (!root) return;
		maxLevel = max(maxLevel, lev);
		lev++;
		getLevel(root->left, lev);
		getLevel(root->right, lev);

		return;
	}

	void dfs(TreeNode* root, int lev = 0) {
		if (!root) return;

		if (lev == maxLevel) ans += root->val;
		lev++;
		dfs(root->right, lev);
		dfs(root->left, lev);
		return;
	}

	int deepestLeavesSum(TreeNode* root) {
		getLevel(root, 0);
		dfs(root);


		return ans;
	}
};