class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	const int N = 1e5;
	vector<vector<int>> edges;
	int color[N];
	bool s[N];
	int n;


	bool dfs(int root) {
		color[root] = 1; //On recursion
		for (auto &child : edges[root]) {
			if (s[child]) {
				s[root] = 1;
				return 0;
			}
			if (color[child] == 2) continue;
			if (color[child] == 1) {
				s[root] = 1;
				return 0;
			} else {
				bool temp = dfs(child);
				if (!temp) {
					s[root] = 1;
					return 0;
				}
			}
		}

		color[root] = 2;
		return 1;
	}


	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		n = graph.size();
		edges = graph;
		memset(s, 0, sizeof(s));
		memset(color, 0, sizeof(color));

		for (int i = 0; i < n; ++i) {
			if (color[i] == 0) dfs(i);
		}

		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 0) ans.push_back(i);
		}

		return ans;
	}
};

