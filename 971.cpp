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
	int i = 0;
	vector<int> ans;
	bool get(TreeNode* root, vector<int> &voyage) {
		if (root == NULL) return 1;

		if (root->val != voyage[i]) return 0;

		auto l = root->left;
		auto r = root->right;

		i++;
		if (l != NULL && voyage[i] != l->val) {
			ans.push_back(root->val);
			swap(l, r);
		}

		return get(l, voyage) && get(r, voyage);

	}

	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		if (get(root, voyage)) return ans;
		else return { -1};
	}
};