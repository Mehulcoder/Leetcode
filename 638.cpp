class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	map<vector<int>, int> m;
	int dot(vector<int> &price, vector<int> &needs) {
		int ans = 0;

		for (int i = 0; i < price.size(); ++i) {
			ans += price[i] * needs[i];
		}

		return ans;
	}

	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int start = 0) {
		int localMinima = dot(price, needs);
		int ans = localMinima;

		if (m.find(needs) != m.end()) return m[needs];

		// Start taking each offer 1 time
		for (int j = start; j < special.size(); ++j) {
			auto offer = special[j];
			vector<int> temp = {};
			for (int i = 0; i < needs.size(); ++i) {
				if (needs[i] < offer[i]) {
					temp = {};
					break;
				}

				temp.push_back(needs[i] - offer[i]);
			}

			if (temp.size()) ans = min(ans, offer.back() + shoppingOffers(price, special, temp, j));
		}

		return m[needs] = ans;

	}
};