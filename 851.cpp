class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<vector<int>> edges;
	vector<int> ans;
	int n;
	void dfs(int root, vector<int> &quiet) {
		if (ans[root] != -1) return;
		ans[root] = root;
		for (auto &child : edges[root]) {
			if (ans[child] != -1)
				dfs(child, quiet);
			if (quiet[ans[child]] < quiet[ans[root]]) {
				ans[root] = ans[child];
			}
		}

		return;
	}

	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		n = quiet.size();
		edges.resize(n);
		ans.resize(n, -1);

		for (auto &link : richer) {
			edges[link[1]].push_back(link[0]);
		}

		for (int i = 0; i < n; ++i) {
			if (ans[i] == -1) dfs(i, quiet);
		}

		return ans;
	}
};