class Solution {
public:
	int n;
	vector <int> dp;
	int maxi;
	int get(vector<vector<int>> &books, int end) {
		if (end < 0) return 0;
		int currWidth = books[end][0];
		int currHeight = books[end][1];
		if (end == 0) return currHeight;

		int &ans = dp[end];
		if (ans != -1) return ans;

		//I place on a newLevel
		ans = get(books, end - 1) + currHeight;
		//Let's try to fit in prev books with this one
		for (int i = end - 1; i >= 0; --i) {
			currWidth += books[i][0];
			if (currWidth > maxi) break;
			currHeight = max(currHeight, books[i][1]);
			ans = min(ans, currHeight + get(books, i - 1));
		}

		return ans;
	}

	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		n = books.size();
		dp.resize(n, -1);
		maxi = shelf_width;
		return get(books, n - 1);
	}
};