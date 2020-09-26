class Solution {
public:
	string s;
	int n;
	int get(int start, int end) {
		if (start > end) return 0;
		if (start == end) return 1;

		int ans = 1;
		for (int len = 1; len <= (end - start + 1) / 2; ++len) {
			if (s.substr(start, len) == s.substr(end - len + 1, len)) {
				return get(start + len, end - len) + 2;
			}
		}

		return ans;
	}

	int longestDecomposition(string text) {
		s = text;
		n = s.size();
		return get(0, n - 1);
	}
};