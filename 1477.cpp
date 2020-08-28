class Solution {
public:
	int minSumOfLengths(vector<int>& arr, int target) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int n = arr.size();
		vector<int> pre(n, 0), suff(n, 0), dpl(n, INT_MAX), dpr(n, INT_MAX);

		for (int i = 0; i < n; ++i) {
			pre[i] = arr[i];
			if (i > 0) pre[i] += pre[i - 1];
		}

		for (int i = n - 1; i >= 0; --i) {
			suff[i] = arr[i];
			if (i < n - 1) suff[i] += suff[i + 1];
		}

		unordered_map<int, int> ml;
		ml[0] = -1;
		for (int i = 0; i < n; ++i) {
			int len1;
			if (ml.find(pre[i] - target) != ml.end()) {
				len1 = i - ml[pre[i] - target];
				dpl[i] = len1;
			}
			if (i > 0) dpl[i] = min(dpl[i], dpl[i - 1]);
			ml[pre[i]] = i;
		}


		unordered_map<int, int> mr;
		mr[0] = n;
		for (int i = n - 1; i >= 0; --i) {
			int len1;
			if (mr.find(suff[i] - target) != mr.end()) {
				len1 = -i + mr[suff[i] - target];
				dpr[i] = len1;
			}
			if (i < n - 1) dpr[i] = min(dpr[i], dpr[i + 1]);
			mr[suff[i]] = i;
		}

		int ans = INT_MAX;
		for (int i = 0; i < n; ++i) {
			if (dpl[i] != INT_MAX && i + 1 < n && dpr[i + 1] != INT_MAX) {
				ans = min(ans, dpl[i] + dpr[i + 1]);
			}
		}

		return ((ans == INT_MAX) ? (-1) : ans);
	}
};