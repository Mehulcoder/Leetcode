class DSU {
public:
	int connected;
	vector<int> parent, rankk;

	DSU() {}

	void init(int n) {
		parent.clear();
		rankk.clear();
		parent.resize(n, 0);
		rankk.resize(n, 0);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rankk[i] = 0;
		}
		connected = n;
	}

	int findSet(int u) {
		if (parent[u] == u) return u;
		return parent[u] = findSet(parent[u]);
	}

	bool unionSets(int u, int v) {
		int a = findSet(u);
		int b = findSet(v);
		if (a != b) {
			connected--;
			if (rankk[a] < rankk[b]) swap(a, b);
			parent[b] = a;
			if (rankk[b] == rankk[a]) rankk[a]++;
		} else {
			return 0;
		}

		return 1;
	}

	int getRank(int u) {
		return rankk[u];
	}
};

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}


	DSU dsu;
	int n;

	vector<int> detectCycle(vector<vector<int>> &edges, vector<int> skipEdge) {
		for (auto &edge : edges) {
			if (edge == skipEdge) continue;
			if (!dsu.unionSets(edge[0], edge[1])) return edge;
		}

		return { -1, -1};
	}

	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

		n = edges.size();
		for (int i = 0; i < n; ++i) {
			edges[i][0]--;
			edges[i][1]--;
		}

		dsu.init(n);
		int hasTwoIndegrees = -1;
		vector<int> indegrees(n, 0);
		for (int i = 0; i < n; ++i) {
			if (++indegrees[edges[i][1]] == 2) {
				hasTwoIndegrees = edges[i][1];
				break;
			}
		}

		vector<int> ans;
		vector<int> nill = { -1, -1};
		if (hasTwoIndegrees == -1) {
			ans = detectCycle(edges, nill);
		} else {
			for (int i = n - 1; i >= 0; --i) {
				if (edges[i][1] == hasTwoIndegrees) {
					dsu.init(n);
					if (detectCycle(edges, edges[i]) == nill) {
						ans = edges[i];
						break;
					}
				}
			}

		}

		for (auto &val : ans) {
			val++;
		}
		return ans;
	}
};