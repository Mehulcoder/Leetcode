
class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long int;
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<pair<string, ll>> q;
		q.push({beginWord, 0});

		unordered_set<string> s;
		unordered_map<string, bool> vis;
		for (auto &word : wordList) {
			s.insert(word);
		}

		while (!q.empty()) {
			auto tp = q.front();

			if (tp.first == endWord) return tp.second + 1;
			q.pop();

			if (vis[tp.first]) continue;
			vis[tp.first] = 1;

			for (int i = 0; i < 26; ++i) {
				char c = 'a' + i;
				for (int j = 0; j < tp.first.size(); ++j) {
					string &temp = tp.first;
					char orig = temp[j];
					temp[j] = c;
					if (s.find(temp) != s.end()) q.push({temp, tp.second + 1});
					temp[j] = orig;
				}
			}
		}

		return 0;
	}
};