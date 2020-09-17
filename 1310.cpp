class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		int n = arr.size();
		vector<int> pre(n + 1, 0), ans;

		for (int i = 1; i < n + 1; ++i) {
			pre[i] = pre[i - 1] ^ arr[i - 1];
		}

		for (auto &q : queries) {
			ans.push_back(pre[q[1] + 1]^pre[q[0]]);
		}

		return ans;
	}
};