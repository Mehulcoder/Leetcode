// Below is the standard 2D solution by deciding on each state whether to choose the current coin or ignore it. I have used long long to make the code short, by handling 32bit integer overflow automatically

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		long long int n = coins.size();
		vector<vector<long long int>> dp(n + 1, vector<long long int > (amount + 1, 0));

		for (long long int i = 0; i < n; ++i) {
			for (long long int j = 1; j < amount + 1; ++j) {
				long long int temp1 = (i - 1 >= 0) ? dp[i - 1][j] : INT_MAX;
				long long int temp2 = (j - coins[i] >= 0) ? (1 + dp[i][j - coins[i]]) : INT_MAX;
				dp[i][j] = min(temp2, temp1);
			}
		}

		return ((dp[n - 1][amount] < INT_MAX) ? dp[n - 1][amount] : -1);
	}
};
// We can see that we only need the values of the previous row's current column and values on the left of the current row. This can be handled easily by a 1D array/vector. You can try to draw a 2D matrix first in your copy to check, it helps to build the intuition for the optimization and get the feel of the working of the code. I'd suggest not to jump directly to the second solution. Go step by step, it helps.

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		long long int n = coins.size();
		vector<long long int> dp(amount + 1, 0);

		for (long long int i = 0; i < n; ++i) {
			for (long long int j = 1; j < amount + 1; ++j) {
				long long int temp1 = (i - 1 >= 0) ? dp[j] : INT_MAX;
				long long int temp2 = (j - coins[i] >= 0) ? (1 + dp[j - coins[i]]) : INT_MAX;
				dp[j] = min(temp2, temp1);
			}
		}

		return (dp[amount] < INT_MAX ? dp[amount] : -1);
	}
};