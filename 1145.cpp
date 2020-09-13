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

	// TreeNode* getRoot(TreeNode * root, int x) {
	// 	if (!root) return NULL;
	// 	if (root->val == x) {
	// 		return root;
	// 	}

	// 	TreeNode* temp1 = getRoot(root->left, x);
	// 	TreeNode* temp2 = getRoot(root->right, x);
	// 	if (!temp1) return temp2;
	// 	else return temp1;
	// }

	void getRoot(TreeNode* root, int x, TreeNode* &ans) {
		if (!root) return;
		if (root->val == x) {
			ans = root;
			return;
		}

		getRoot(root->left, x, ans);
		getRoot(root->right, x, ans);

		return;
	}

	int getSize(TreeNode * root) {
		if (!root) return 0;
		return (1 + getSize(root->left) + getSize(root->right));
	}

	bool btreeGameWinningMove(TreeNode * root, int n, int x) {
		TreeNode* temp = new TreeNode(NULL);
		getRoot(root, x, temp);

		vector<int> arr(3, 0);
		arr[0] = getSize(temp->left);
		arr[1] = getSize(temp->right);
		arr[2] = n - arr[0] - arr[1] - 1;

		int sum = arr[0] + arr[1] + arr[2];

		for (int i = 0; i < 3; ++i) {
			if (arr[i] > sum - arr[i]) return 1;
		}

		return 0;
	}
};