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
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		dsu.init(edges.size());
		vector<int> ans;
		for (auto &edge : edges) {
			if (!dsu.unionSets(edge[0] - 1, edge[1] - 1)) {
				ans.push_back(edge[0]);
				ans.push_back(edge[1]);
				break;
			}
		}

		return ans;
	}
};