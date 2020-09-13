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
	using ll = long long int;

	ll getMax(TreeNode* root, ll maxx = -4557430888798830399ll) {
		if (root == NULL) return maxx;
		maxx = max(maxx, (ll)root->val);
		return getMax(root->right, maxx);
	}

	ll getMin(TreeNode* root, ll minn = 4557430888798830399ll) {
		if (root == NULL) return minn;
		minn = min(minn, (ll)root->val);
		return getMin(root->left, minn);
	}

	bool isValidBST(TreeNode* root) {
		if (root == NULL) return 1;
		ll maxiL = getMax(root->left);
		ll miniR = getMin(root->right);
		ll val = root->val;

		bool checkChild = (isValidBST(root->left)) && (isValidBST(root->right));
		return (maxiL < val && miniR > val && checkChild);
	}
};