/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<vector<int>> edges;
	unordered_map<TreeNode*, int> index;
	unordered_map<int, TreeNode*> rIndex;
	TreeNode* newRoot;
	TreeNode* targett;
	vector<int> ans;
	int n = 0, k;
	int curr = 0;

	void makeGraph(TreeNode* root) {
		if (!root) return;
		if (root->left) {
			edges[index[root]].push_back(index[root->left]);
			edges[index[root->left]].push_back(index[root]);
		}

		if (root->right) {
			edges[index[root]].push_back(index[root->right]);
			edges[index[root->right]].push_back(index[root]);
		}

		makeGraph(root->left);
		makeGraph(root->right);

		return;
	}

	void markVertices(TreeNode* root) {
		if (!root) return;
		if (root == targett) {
			newRoot = root;
		}
		index[root] = curr;
		rIndex[curr] = root;
		curr++;

		markVertices(root->left);
		markVertices(root->right);

		return;
	}

	void dfs(int root, int dis = 0, int parent = -1) {
		if (dis == k) {
			ans.push_back(rIndex[root]->val);
			return;
		}

		for (auto &child : edges[root]) {
			if (child != parent) {
				dfs(child, dis + 1, root);
			}
		}

		return;
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		k = K;
		targett = target;
		markVertices(root);
		n = curr;
		edges.resize(n);
		makeGraph(root);

		dfs(index[newRoot]);

		return ans;
	}
};