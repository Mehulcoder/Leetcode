class Solution {
public:
	vector<vector<long long int>> dp;
	long long int get(vector<int>&arr, long long int i, long long int j) {
		if (i == j) return 0;
		long long int &ans = dp[i][j];
		if (ans != -1) return ans;
		long long int temp = INT_MAX;
		for (long long int k = i + 1; k <= j - 1; ++k) {
			long long int elem1 = *max_element(arr.begin() + i, arr.begin() + k + 1);
			long long int elem2 = *max_element(arr.begin() + k + 1, arr.begin() + j + 1);
			temp = min(temp, get(arr, i, k) + get(arr, k + 1, j) + elem1 * elem2);
		}
		return ans = temp;
	}

	int mctFromLeafValues(vector<int>& arr) {
		dp.resize(arr.size(), vector<int>(arr.size(), -1));
		return (int)get(arr, 0, arr.size() - 1);
	}
};