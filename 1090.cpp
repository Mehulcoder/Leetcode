class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		vector<pair<int, int>> v;
		int n = values.size();

		for (int i = 0; i < n; ++i) {
			v.push_back({values[i], labels[i]});
		}

		sort(v.begin(), v.end(), greater<pair<int, int>>());

		int currCount = 0;
		int ans = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (currCount == num_wanted) break;
			if (m[v[i].second] == use_limit) continue;

			ans += v[i].first;
			m[v[i].second]++;
			currCount++;
		}

		return ans;
	}
};