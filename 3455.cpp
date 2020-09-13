class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	string getHint(string secret, string guess) {
		unordered_multiset<char> s, s2;
		for (int i = 0; i < secret.size(); ++i) {
			s.insert(secret[i]);
			s2.insert(guess[i]);
		}
		int a = 0, b = 0;
		for (int i = 0; i < min(secret.size(), guess.size()); ++i) {
			if (secret[i] == guess[i]) {
				s.erase(s.find(secret[i]));
				s2.erase(s2.find(guess[i]));
				a++;
			}
		}

		for (int i = 0; i < guess.size(); ++i) {
			if (s.find(guess[i]) != s.end() && s2.find(guess[i]) != s2.end()) {
				b++;
				s.erase(s.find(guess[i]));
				s2.erase(s2.find(guess[i]));
			}
		}
		string ans = to_string(a) + "A"  + to_string(b) + "B";
		return ans;
	}
};