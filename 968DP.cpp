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

	// 0->I do not place here
	// 1->I place here
	unordered_map<TreeNode*, int> dp;
	int get(TreeNode* root, bool state) {
		if (root == NULL) {
			if (state == 1) return 10000;
			else return 0;
		}

		if (!(root->left) && !(root->right)) {
			if (!state) {
				return 0;
			} else {
				return 1;
			}
		}

		if (dp.find(root) != dp.end()) return dp[root];

		int ans;
		if (!state) {
			int poss1 = get(root->left, 1) + min(get(root->right, 0), get(root->right, 1));
			int poss2 = get(root->left, 0) + get(root->right, 1);
			ans = min(poss1, poss2);
		} else {
			int pos1 = get(root->left, 0) + get(root->right, 0);
			int pos2 = get(root->left, 1) + get(root->right, 1);
			int pos3 = get(root->left, 1) + get(root->right, 0);
			int pos4 = get(root->left, 0) + get(root->right, 1);
			ans =  min({pos1, pos2, pos3, pos4}) + 1;
		}

		return dp[root] = ans;

	}

	int minCameraCover(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		int ans = min(get(root, 0), get(root, 1));
		return ans;
	}
};