class Solution {
public:

	string get(string &s, int start, int end) {
		if (start > end) return "";
		string ans = "";
		string temp = "";
		int count = 0;
		for (int i = start; i <= end; ++i) {
			if (isalpha(s[i])) {
				temp += s[i];
				count = 0;
			} else {
				ans += temp;
				temp = "";
				if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
					count = count * 10 + (s[i] - '0');
				} else {
					int left = i + 1;
					stack<char> st;
					st.push('[');
					while (!st.empty()) {
						i++;
						if (s[i] == '[') st.push('[');
						else if (s[i] == ']') st.pop();
					}
					int right = i - 1;
					string tempp = get(s, left, right);
					while (count--) ans += tempp;
					ans += get(s, i + 1, end);
					return ans;
				}
			}
		}

		if (temp.size() != 0)ans += temp;
		return ans;
	}

	string decodeString(string s) {
		int n = s.size();
		return get(s, 0, n - 1);
	}
};