class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int longestSubarray(vector<int>& s, int limit) {
		int n = s.size();
		multiset<int> small;

		int ans = 1, l = 0, r = 1;
		small.insert(s[0]);

		while (r < n) {

			while (r < n && abs(*(small.begin()) - * (small.rbegin())) <= limit) {
				ans = max(ans, r - l);
				small.insert(s[r]);
				r++;
			}

			while (l < r && abs(*small.begin() - *small.rbegin()) > limit) {
				small.erase(small.find(s[l]));
				l++;
			}

			if (abs(*small.begin() - *small.rbegin()) <= limit) {
				ans = max(ans, r - l);
			}
		}

		return ans;
	}
};