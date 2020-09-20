class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<int> nums;
	int n, sum = 0, maxi = INT_MIN;
	vector<bool> visited;

	bool get(int subSetsLeft, int currSubSetSum, int startPos) {
		if (subSetsLeft == 0) return 1;
		if (currSubSetSum == sum) return get(subSetsLeft - 1, 0, 0);

		for (int i = startPos; i < n; ++i) {
			if (!visited[i] && nums[i] + currSubSetSum <= sum) {
				visited[i] = 1;
				bool temp = get(subSetsLeft, currSubSetSum + nums[i], i + 1);
				if (temp) return 1;
				visited[i] = 0;
			}
		}

		return 0;
	}

	bool canPartitionKSubsets(vector<int>& Nums, int k) {
		nums = Nums;
		n = nums.size();
		visited.resize(n, 0);
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			maxi = max(maxi, nums[i]);
		}
		if (sum % k != 0 || maxi > sum / k) return 0;
		sum /= k;
		return get(k, 0, 0);
	}
};