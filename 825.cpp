class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int numFriendRequests(vector<int>& ages) {
		int n = ages.size();
		sort(ages.begin(), ages.end());
		int ans = 0;
		vector<int> cntt(n, 0);
		for (int i = 0; i < n; ++i) {
			int val = 0.5 * ages[i] + 7;
			int ind = upper_bound(ages.begin(), ages.end(), val) - ages.begin();
			int cnt = i - ind;
			if (cnt > 0 && cnt < n) {
				if (i > 0 && ages[i - 1] == ages[i]) cntt[i] = max(cnt, cntt[i - 1]);
				else cntt[i] = cnt;
			}
		}

		for (int i = n - 1; i >= 0; --i) {
			if (i != n - 1 && ages[i + 1] == ages[i]) {
				cntt[i] = max(cntt[i], cntt[i + 1]);
			}
			ans += cntt[i];
		}

		return ans;

	}
};