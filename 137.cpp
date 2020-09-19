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

/*
* Let us deal with single bits for now. Array of single bits. That is 0 or 1
* We basically want count(1) % k. Without using modulo.
* Suppose a mask m has the binary form xm, xm-1, xm-2, ...x1. Iterate on the array
* and eveytime you encounter a 1 increase m by 1.
* What that means is, let's say that we got our first 1 ==> x1 changes to 1
* Now we got our next one x2->1 basically x2 = x2^(x1&ai)
* Similary say we got our mth one ==> xm = xm^(x1&x2---xm-1 & ai)

* Now next task is that we want something to check if our count reaches k, then
* we reset our count to 0. So we can actually create a mask, which will get 0 only when
* count reaches k. And we'll take the & ==> xm = xm & mask,...xi = xi & mask,...x1 = x1 & mask.
*
*
*
*
*
*
*
*
*
*
*/