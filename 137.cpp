class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 31; i >= 0; --i) {
			int sum = 0;
			for (auto &num : nums) {
				sum += ((1 << i) & (num)) != 0;
			}
			int bit = sum % 3;
			if (bit)
				ans |= bit << i;
		}

		return ans;
	}
};