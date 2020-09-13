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
	pair<int, int> get(TreeNode* root) {
		if (root == NULL) return {0, 0};
		auto temp3 = get(root->left);
		auto temp4 = get(root->right);

		//Take the root
		int temp1 = root->val;
		//Do not take the child
		temp1 += (temp3.second + temp4.second);

		//Do not take the root
		int temp2 = 0;
		//Take or not take left
		temp2 = max(temp3.first, temp3.second);
		//Take or not take right
		temp2 += max(temp4.first, temp4.second);

		return {temp1, temp2};
	}

	int rob(TreeNode* root) {
		auto temp = (get(root));
		return max(temp.first, temp.second);
	}
};