class Solution {
public:
	vector<vector<int>> edges;
	int node = 0;
	int maxi = 0;

	void dfs(int root, int lev, int par) {
		if (lev >= maxi) node = root, maxi = lev;

		for (auto &child : edges[root]) {
			if (child == par)continue;
			dfs(child, lev + 1, root);
		}

		return;
	}

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& _edges) {
		edges.clear();
		edges.resize(n);
		node = 0;
		maxi = 0;

		for (auto &elem : _edges) {
			edges[elem[0]].push_back(elem[1]);
			edges[elem[1]].push_back(elem[0]);
		}

		dfs(0, 0, -1);

		vector<bool> vis(n, 0);
		vector<int> par(n, -1);
		queue<vector<int>>q;
		q.push({node, 0});

		int end1 = node;
		vis[end1] = 1;
		int depth = 0;
		while (!q.empty()) {
			auto tp = q.front();
			q.pop();
			if (tp[1] >= depth) {
				depth = tp[1];
				end1 = tp[0];
			}

			for (auto &child : edges[tp[0]]) {
				if (!vis[child]) {
					vis[child] = 1;
					par[child] = tp[0];
					q.push({child, tp[1] + 1});
				}
			}
		}

		int count = 0;
		int curr = end1;
		vector<int> ans;

		while (curr != -1 && ans.size() < depth % 2 + 1) {
			if (count == depth / 2 || count == (depth + 1) / 2) {
				ans.push_back(curr);
			}
			curr = par[curr];
			count++;

		}
		return ans;

	}
};