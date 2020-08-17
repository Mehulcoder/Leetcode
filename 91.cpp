class Solution {
public:
	string s1;
	vector<int> dp;
	int get(int start) {
		int n = s1.size();
		if (start == n) return 1;
		if (s1[start] == '0') return 0;

		int &ans = dp[start];
		if (ans != -1) return ans;

		int temp = get(start + 1);
		int val = stoi(s1.substr(start, 2));
		if (val <= 26 && val >= 10)temp += get(start + 2);

		return ans = temp;
	}

	int numDecodings(string s) {
		s1 = s;
		int n = s.size();
		dp.resize(n, -1);
		if (n == 1) return stoi(s) > 0;
		return get(0);
	}
};