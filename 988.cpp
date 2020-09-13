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
	string smallestFromLeaf(TreeNode* r, string s = "") {
		if (r == nullptr) return "|";
		s = string(1, 'a' + r->val) + s;
		return r->left == r->right ? s : min(smallestFromLeaf(r->left, s), smallestFromLeaf(r->right, s));
	}
};