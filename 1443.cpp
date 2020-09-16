class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<int> appleCount;
	void getAppleCount(vector<vector<int>> &edges, vector<bool> &hasApple, int root, int parent) {
		for (auto &child : edges[root]) {
			if (child != parent) {
				getAppleCount(edges, hasApple, child, root);
				appleCount[root] += appleCount[child];
			}
		}

		return;
	}


	int get(vector<vector<int>> &edges, vector<bool> &hasApple, int root, int parent) {
		int ans = 0;

		for (auto &child : edges[root]) {
			if (child != parent) {
				int temp = get(edges, hasApple, child, root);
				if (appleCount[child] > 0) {
					ans += temp + 2;
				}
			}
		}

		return ans;
	}

	int minTime(int n, vector<vector<int>>& edge, vector<bool>& hasApple) {
		vector<vector<int>> edges;
		appleCount.resize(n, 0);
		edges.resize(n);
		for (int i = 0; i < edge.size(); ++i) {
			edges[edge[i][0]].push_back(edge[i][1]);
			edges[edge[i][1]].push_back(edge[i][0]);
		}

		for (int i = 0; i < n; ++i) {
			if (hasApple[i]) appleCount[i] = 1;
		}
		getAppleCount(edges, hasApple, 0, -1);
		return get(edges, hasApple, 0, -1);
	}
};