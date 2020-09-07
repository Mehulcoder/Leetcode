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

	void getAllElements(TreeNode* root, vector<int> &ans) {
		if (root == NULL) return;
		getAllElements(root->left, ans);
		ans.push_back(root->val);
		getAllElements(root->right, ans);
		return;
	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

		vector<int> l1, r1, l2, r2, ans1, ans2, ans3;
		if (root1 != NULL) {
			getAllElements(root1->left, l1);
			getAllElements(root1->right, r1);
			l1.push_back(root1->val);
		}
		if (root2 != NULL) {
			getAllElements(root2->left, l2);
			getAllElements(root2->right, r2);
			l2.push_back(root2->val);
		}

		ans1.resize(l1.size() + l2.size(), 0);
		ans2.resize(r1.size() + r2.size(), 0);
		ans3.resize(ans1.size() + ans2.size(), 0);

		merge(l1.begin(), l1.end(), l2.begin(), l2.end(), ans1.begin());
		merge(r1.begin(), r1.end(), r2.begin(), r2.end(), ans2.begin());
		merge(ans1.begin(), ans1.end(), ans2.begin(), ans2.end(), ans3.begin());

		return ans3;
	}
};