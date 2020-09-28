/*
Author: Mehul Chaturvedi
Talent is overrated
*/

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int dp[50001] = {[0 ... 50000] = INT_MIN};
	int get(vector<int> &stones, int start, int n) {
		if (start >= n) {
			return 0;
		}

		auto &ans = dp[start];
		if (ans != INT_MIN) return ans;

		int sum = 0;
		for (int i = 0; i < 3; i++) {
			if (i + start >= n) break;
			sum += stones[start + i];
			ans = max(ans, (sum - get(stones, start + i + 1, n)));
		}

		return ans;
	}

	string stoneGameIII(vector<int>& stones) {
		int n = stones.size();

		int ans = get(stones, 0, n);

		if (ans == 0) return "Tie";
		else if (ans > 0) return "Alice";
		else return "Bob";

	}
};