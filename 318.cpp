class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n, ans = 0;
	bool check(int a, int b) {
		for (int i = 0; i < 32; ++i) {
			if (((1 << i) & a) != 0 && (((1 << i) & b) != 0)) return 0;
		}

		return 1;
	}

	struct comp {
		bool operator()(const string &s1, const string &s2) {
			return s1.size() > s2.size();
		}
	};

	int maxProduct(vector<string>& words) {
		n = words.size();
		vector<int> bitString, sizes;
		sort(words.begin(), words.end(), comp);

		for (auto &word : words) {
			cout << word << endl;
			sizes.push_back(word.size());
		}

		for (int i = 0; i < n; ++i) {
			int num = 0;
			string &word = words[i];
			for (auto &ch : word) {
				num |= (1 << (ch - 'a'));
			}
			bitString.push_back(num);
		}


		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; j++) {
				int num1 = bitString[i];
				int num2 = bitString[j];
				if (sizes[i]*sizes[j] <= ans) break; //pruning
				if (check(num1, num2)) {
					ans = max(ans, sizes[i] * sizes[j]);
				}
			}
		}

		return ans;
	}
};