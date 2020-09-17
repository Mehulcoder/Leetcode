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
	unordered_map<int, int> levels;
	int maxLev = 0;
	vector<int> ans;
	void dfs(TreeNode* root, int lev) {
		if (!root) return;
		maxLev = max(lev + 1, maxLev);
		if (levels.find(lev) != levels.end()) {
			levels[lev] = max(levels[lev], root->val);
		} else {
			levels[lev] = root->val;
		}
		dfs(root->left, lev + 1);
		dfs(root->right, lev + 1);
		return;
	}

	vector<int> largestValues(TreeNode* root) {
		dfs(root, 0);
		ans.resize(maxLev, 0);
		for (int i = 0; i < maxLev; ++i) {
			ans[i] = levels[i];
		}

		return ans;

	}
};