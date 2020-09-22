using ll = long long int;

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n;
	vector<vector<ll>> dis;
	vector<ll> freq;
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

	int findTheCity(int nn, vector<vector<int>>& edges, int distanceThreshold) {
		n = nn;
		dis.resize(n, vector<ll>(n, INT_MAX));
		freq.resize(n, 0);

		for (int i = 0; i < n; ++i) {
			dis[i][i] = 0;
		}

		for (auto &edge : edges) {
			dis[edge[0]][edge[1]] = edge[2];
			dis[edge[1]][edge[0]] = edge[2];
		}

		floydWarshall();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j && dis[i][j] <= distanceThreshold) freq[i]++;
			}
		}

		ll maxi = INT_MAX;
		ll ans = -1;
		for (int i = 0; i < n; ++i) {
			if (freq[i] <= maxi) {
				maxi = freq[i];
				ans = i;
			}
		}

		return ans;
	}
};