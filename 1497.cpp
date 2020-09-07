class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	bool canArrange(vector<int>& arr, int k) {
		int n = arr.size();
		vector<int> s(k, 0);
		for (int i = 0; i < n; ++i) {
			arr[i] = (k + (arr[i] + k) % k) % k;
			s[arr[i]]++;
		}

		for (int i = 0; i < n; ++i) {
			if (s[arr[i]] <= 0) continue;
			s[arr[i]]--;
			if (arr[i] == 0) {
				if (s[0]-- <= 0) return 0;
			} else if (s[k - arr[i]]-- <= 0) return 0;
		}
		return 1;
	}
};