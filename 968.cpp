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
# define hasCamera 1
# define noNeed 2
# define needCamera 3

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int ans = 0;
	int dfs(TreeNode* root) {
		if (root == NULL) return noNeed;

		auto l = dfs(root->left);
		auto r = dfs(root->right);

		if (l == needCamera || r == needCamera) {
			ans++;
			return hasCamera;
		} else if (l == hasCamera || r == hasCamera) {
			return noNeed;
		} else {
			return needCamera;
		}
	}

	int minCameraCover(TreeNode* root) {
		if (dfs(root) == needCamera) ans++;
		return ans;
	}
};