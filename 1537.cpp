class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long int;
	int n, m;
	const ll MOD = 1e9 + 7;
	int maxSum(vector<int>& nums1, vector<int>& nums2) {
		m = nums2.size();
		n = nums1.size();

		int i = 0;
		int j = 0;

		ll sum1 = 0, sum2 = 0, ans = 0;

		while (i < n && j < m) {
			if (nums1[i] < nums2[j]) {
				sum1 += nums1[i];
				i++;
			} else if (nums2[j] < nums1[i]) {
				sum2 += nums2[j];
				j++;
			} else {
				ans += max(sum1, sum2) + nums1[i];
				sum1 = sum2 = 0;
				i++;
				j++;
			}
		}

		while (i < n) {
			sum1 += nums1[i];
			i++;
		}

		while (j < m) {
			sum2 += nums2[j];
			j++;
		}


		ans += max(sum1 , sum2);

		return ans % MOD;
	}
};