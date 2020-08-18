class Solution {
public:
	vector<int> tails;
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size(), ans = 0;
		for (auto &elem : nums) {
			int ind = upper_bound(tails.begin(), tails.end(), elem) - tails.begin();
			if (ind == tails.size()) {
				tails.push_back(elem);
				ans++;
			} else tails[ind] = elem;
		}

		return ans;
	}
};