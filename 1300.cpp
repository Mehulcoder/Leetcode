class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		int n  = arr.size();
		vector<int> pre(n, 0);
		// sort(arr.begin(), arr.end());

		int maxi = arr[0];
		for (int i = 0; i < n; ++i) {
			if (i != 0) pre[i] = pre[i - 1] + arr[i];
			else pre[i] = arr[i];
			maxi = max(maxi, arr[i]);
		}
		if (pre[n - 1] <= target) return maxi;


		int ans = pre[n - 1];
		int val = arr[n - 1];

		for (int i = 0; i <= maxi; ++i) {
			int ind = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
			int sum = 0;
			if (ind != 0) sum += pre[ind - 1];
			sum += i * (n - ind);

			if (abs(sum - target) < abs(ans - target)) {
				ans = sum;
				val = i;
			}
		}

		return val;
	}
};

class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		int l, r, mi, s = 0, m = -1;
		for (int v : arr) s += v, m = max(m, v);

		if (s <= target) return m; // return the max value since we will keep all nums as is

		for (l = 1, r = m; l < r;) {
			mi = (l + r) / 2;
			s = 0;
			for (int v : arr) s += (v > mi) ? mi : v;
			if (s >= target) r = mi;
			else          l = mi + 1;
		}
		// check if we are 1 step off the target
		int s1 = 0, s2 = 0;
		for (int v : arr) s1 += (v > l) ? (l) : v, s2 += (v > l - 1) ? (l - 1) : v;

		return (abs(s2 - target) <= abs(s1 - target)) ? l - 1 : l;
	}
};