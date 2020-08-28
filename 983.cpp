class Solution {
public:
	int n;
	vector<int> dys, cst, dp;
	int get(int end) {
		if (end < 0) return 0;

		int &ans = dp[end];
		if (ans != -1) return ans;

		//Buy one day ticket
		int temp1 = cst[0] + get(end - 1);

		//Buy 7 days ticket
		//Mai dys[j] ke baad waale day pe ticket lunga
		int j;
		for (j = end - 1; j >= 0; --j) if (dys[j] <= dys[end] - 7) break;

		int temp2, temp3;
		temp2 = cst[1] + get(j);

		//But the 30 day ticket
		for (j = end - 1; j >= 0; --j) if (dys[j] <= dys[end] - 30) break;

		temp3 = cst[2] + get(j);

		return ans = min({temp1, temp2, temp3});
	}

	int mincostTickets(vector<int>& days, vector<int>& costs) {
		n = days.size();
		dp.resize(n, -1);
		dys = days; cst = costs;
		get(n - 1);
		return dp[n - 1];
	}
};