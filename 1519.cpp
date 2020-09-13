class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<vector<int>> dp, edges2;
	vector<int> ans;
	void get(int root, string &labels, int parent = -1) {
		dp[root][labels[root] - 'a']++;
		for (auto &child : edges2[root]) {
			if (child == parent) continue;
			get(child, labels, root);
			for (int i = 0; i < 27; ++i) {
				dp[root][i] += dp[child][i];
			}
		}
		ans[root] = dp[root][labels[root] - 'a'];
		return;
	}

	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		dp.resize(n, vector<int>(27, 0));
		ans.resize(n);
		edges2.resize(n);

		for (int i = 0; i < edges.size(); ++i) {
			edges2[edges[i][0]].push_back(edges[i][1]);
			edges2[edges[i][1]].push_back(edges[i][0]);
		}

		get(0, labels, -1);
		return ans;
	}
};