class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int maxSatisfaction(vector<int>& satisfaction) {
		int n = satisfaction.size(), ans = 0;

		sort(satisfaction.begin(), satisfaction.end());
		for (int i = 0; i < n; ++i) {
			int curr = 1, currAns = 0;

			for (int j = i; j < n; ++j) {
				currAns += curr * satisfaction[j];
				curr++;
			}
			ans = max(ans, currAns);
		}
		return ans;
	}


	int maxSatisfaction(vector<int>& satisfaction) {
		int n = satisfaction.size(), ans = 0;
		sort(satisfaction.begin(), satisfaction.end());
		vector<int> suff(n, 0), ssuff(n, 0);

		for (int i = n - 1; i >= 0; --i) {
			suff[i] = satisfaction[i];
			if (i != n - 1) suff[i] += suff[i + 1];
		}


		for (int i = n - 1; i >= 0; --i) {
			ssuff[i] = suff[i];
			if (i != n - 1) ssuff[i] += ssuff[i + 1];
			ans = max(ans, ssuff[i]);
		}

		return ans;
	}
};