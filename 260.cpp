
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int xorr = 0;
		for (int i = 0; i < nums.size(); ++i) {
			xorr ^= nums[i];
		}

		int f = 1;
		int pos = 0;
		while (xorr > 0) {
			if ((xorr & f) == 1) {
				break;
			} else {
				xorr >> 1;
				pos++;
			}
		}
		vector<int> ans;
		vector<vector<int>> groups(2);
		for (int i = 0; i < nums.size(); ++i) {
			groups[(nums[i] >> pos) & 1].push_back(nums[i]);
		}

		for (int i = 0; i < 2; ++i) {
			int temp = 0;
			for (int j = 0; j < nums[i].size; ++j) {
				temp ^= groups[i][j];
			}
			ans.push_back(temp);
		}

		return ans;
	};