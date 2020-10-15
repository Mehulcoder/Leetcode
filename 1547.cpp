class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	int n;
	vector<int> cuts;
	int dp[102][102];
	int get(int left, int right) {
		if (right - left <= 1) return 0;
		int currCost = cuts[right] - cuts[left];

		int &anss = dp[left][right];
		if (anss != -1) return anss;

		int temp = INT_MAX;
		for (int k = left + 1; k < right; ++k) {
			temp = min(temp, get(left, k) + get(k, right));
		}

		if (temp == INT_MAX) return 0;
		return anss = temp + currCost;
	}

	int minCost(int nn, vector<int>& cutss) {
		cuts.push_back(0);

		for (int i = 0; i < cutss.size(); ++i) {
			cuts.push_back(cutss[i]);
		}
		n = nn;
		cuts.push_back(n);

		memset(dp, -1, sizeof(dp));
		sort(cuts.begin(), cuts.end());
		return get(0, cuts.size() - 1);
	}
};