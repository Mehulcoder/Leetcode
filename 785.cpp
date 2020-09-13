class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<int> vis(graph.size());
		for (int i = 0; i < graph.size(); i++)
			if (!dfs(graph, vis, i, vis[i]))
				return false;
		return true;
	}

	bool dfs(vector<vector<int>> &graph, vector<int> &vis, int i, int pos) {
		if (!vis[i]) {
			vis[i] = pos == 2 ? 2 : 1;
			for (int j : graph[i])
				if (!dfs(graph, vis, j, pos == 2 ? 1 : 2))
					return false;
		}
		return !pos || pos == vis[i];
	}
};