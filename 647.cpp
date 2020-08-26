class Solution {
public:
	int countSubstrings(string s) {
		int n = s.size(), ans = 0;
		for (int center = 0; center < n; ++center) {
			int left = center, right = center;
			//Odd length;
			int count = 0;
			while (left >= 0 && right < n && s[left] == s[right]) {
				count++;
				left--;
				right++;
			}
			ans += count;
			//Even length;
			count = 0;
			left = center - 1;
			right = center;
			while (left >= 0 && right < n && s[left] == s[right]) {
				count++;
				left--;
				right++;
			}
			ans += count;

		}

		return ans;
	}
};