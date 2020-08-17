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
	auto get(int start, int end) {
		vector<TreeNode*> ans;
		if (start > end) {
			ans.push_back(NULL);
			return ans;
		}

		for (int curr = start; curr <= end; ++curr) {
			auto temp1 = get(start, curr - 1);
			auto temp2 = get(curr + 1, end);

			for (auto l : temp1) {
				for (auto r : temp2) {
					auto root = new TreeNode(curr);
					root->left = l;
					root->right = r;
					ans.push_back(root);
				}
			}
		}

		return ans;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return {};
		return get(1, n);
	}
};