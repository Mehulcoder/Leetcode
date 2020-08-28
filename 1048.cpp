class Solution {
public:
	vector<int> dp;
	vector<pair<int, int>> m;
	int n;
	static bool mySort(string a, string b) {
		return a.size() < b.size();
	}

	bool isDiff(string right, string left) {
		if (right.size() != left.size() + 1) return 0;
		int count = 0;
		for (int i = 0; i < left.size(); ++i) {
			if (count > 1) return 0;
			if (left[i] != right[i + count]) count++, i--;
		}
		if (count <= 1) return 1;

		return 0;
	}

	int get(vector<string> &words, int end) {
		int &ans = dp[end];
		if (ans != -1) return ans;
		int currSize = words[end].size();
		int currLeft = m[currSize - 1].first , currRight = m[currSize - 1].second;

		ans = 1;
		for (int i = currRight; i >= 0 && i >= currLeft; --i) {
			if (isDiff(words[end], words[i])) {
				ans = max(ans, 1 + get(words, i));
			}
		}

		return ans;
	}

	int longestStrChain(vector<string>& words) {
		n = words.size();
		dp.resize(n, -1);
		m.resize(20);
		sort(words.begin(), words.end(), mySort);
		int left = -1, right = -1, sz = -1;
		for (int i = 0; i < n; ++i) {
			if (sz != words[i].size()) {
				if (sz != -1)
					m[sz] = {left, right};
				left = i;
				right = i;
				sz = words[i].size();
			} else {
				right = i;
			}
		}
		if (sz != -1)
			m[sz] = {left, right};
		int ans = 1;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, get(words, i));
		}

		return ans;
	}


};
static const auto magic = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return nullptr;
}();