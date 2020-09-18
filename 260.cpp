
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int xorr = 0;
		for (int i = 0; i < nums.size(); ++i) {
			xorr ^= nums[i];
		}

		int lastBitSet = (xorr & (xorr - 1)) ^ (xorr);

		int temp1 = 0;
		int temp2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] & lastBitSet) temp1 ^= nums[i];
			else temp2 ^= nums[i];
		}

		return {temp1, temp2};
	};
};