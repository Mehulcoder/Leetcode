class Solution {
public:

	using ll = long long int;
	int kSimilarity(string A, string B) {
		queue<pair<string, int>> q;
		ll n = A.size();
		q.push({A, 0});
		unordered_set<string> vis;

		while (!q.empty()) {
			auto tp = q.front();
			if (tp.first == B) return tp.second;
			q.pop();
			if (vis.find(tp.first) != vis.end()) continue;
			vis.insert(tp.first);

			ll i = 0;
			while (tp.first[i] == B[i]) i++;
			for (int j = i + 1; j < n; ++j) {
				string temp = tp.first;
				if (B[j] == temp[i] && B[j] != temp[j]) {
					swap(temp[i], temp[j]);
					q.push({temp, tp.second + 1});
				}
			}
		}

		return -1;
	}
};