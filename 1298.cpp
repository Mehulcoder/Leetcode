class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	const int N = 1e3 + 10;
	int ky[N], bx[N], vis[N];
	int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
		queue<int> q;
		memset(ky, 0, sizeof(ky));
		memset(bx, 0, sizeof(bx));
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < initialBoxes.size(); ++i) {
			bx[initialBoxes[i]] = 1;
			if (status[initialBoxes[i]] == 1) q.push(initialBoxes[i]);
		}

		int ans = 0;
		while (!q.empty()) {
			auto tp = q.front();
			q.pop();

			if (vis[tp]) continue;
			vis[tp] = 1;

			ans += candies[tp];
			for (auto &elem : containedBoxes[tp]) {
				if (status[elem] == 1 || ky[elem] == 1) {
					q.push(elem);
				}
				bx[elem] = 1;
			}

			for (auto &k : keys[tp]) {
				if (bx[k] == 1) {
					q.push(k);
				}
				ky[k] = 1;
			}
		}

		return ans;


	}
};