class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long int;
	int n;
	vector<vector<ll>> edges, dis;

	void floydWarshall() {
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
				}
			}
		}

		return;
	}
	vector<bool> checkIfPrerequisite(int nn, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		n = nn;
		edges.resize(n);
		dis.resize(n, vector<ll>(n, INT_MAX));
		for (auto &edge : prerequisites) {
			edges[edge[0]].push_back(edge[1]);
			dis[edge[0]][edge[1]] = 0;
		}

		floydWarshall();

		vector<bool> ans;
		for (auto &query : queries) {
			if (dis[query[0]][query[1]] < INT_MAX) ans.push_back(1);
			else ans.push_back(0);
		}

		return ans;
	}
};