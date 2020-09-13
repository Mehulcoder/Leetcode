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
	unordered_map<int, int> mi;
	TreeNode* get(vector<int> &preorder, vector<int> &inorder, int lp, int rp, int li, int ri) {
		if (lp > rp || li > ri) return NULL;
		if (lp == rp) return (new TreeNode(preorder[lp]));

		int root = preorder[lp];
		TreeNode* roott = new TreeNode(root);
		int index = mi[root];

		int lCount = index - li;
		roott->left = get(preorder, inorder, lp + 1, lp + lCount, li, index - 1);
		roott->right = get(preorder, inorder, lp + lCount + 1, rp, index + 1, ri);

		return roott;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < preorder.size(); ++i) {
			mi[inorder[i]] = i;
		}

		return get(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};