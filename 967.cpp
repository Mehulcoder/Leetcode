class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<int> get(int N, int K) {
		if (N == 1) {
			return {1, 2, 3, 4, 5, 6, 7, 8, 9};
		}
		vector<int> temp = get(N - 1, K);
		vector<int> ans;
		for (int i = 0; i < temp.size(); ++i) {
			int num = temp[i];
			int lastDig = temp[i] % 10;

			if (lastDig + K < 10) {
				ans.push_back(10 * num + lastDig + K);
			}

			if (lastDig - K >= 0 && K != 0) {
				ans.push_back(10 * num + lastDig - K);
			}
		}

		return ans;
	}

	vector<int> numsSameConsecDiff(int N, int K) {
		if (N == 1) {
			return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		}
		return get(N, K);
	}
};