class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<int> sum1, sum2, diff1, diff2;
	int n;
	int ans = INT_MIN;
	void get(vector<int> &arr) {
		int maxi = arr[0]; int mini = arr[0];
		for (int i = 0; i < n; ++i) {
			maxi = max(maxi, arr[i]);
			mini = min(mini, arr[i]);
		}

		ans = max(ans, maxi - mini);
		return;
	}

	int maxAbsValExpr(vector<int>& a, vector<int>& b) {
		n = a.size();
		for (int i = 0; i < n; ++i) {
			sum1.push_back(a[i] + b[i] + i);
			sum2.push_back(a[i] + b[i] - i);
			diff1.push_back(a[i] - b[i] + i);
			diff2.push_back(a[i] - b[i] - i);
		}

		get(sum1);
		get(sum2);
		get(diff1);
		get(diff2);

		return ans;
	}
};