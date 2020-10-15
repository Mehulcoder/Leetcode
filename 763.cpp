class Solution {
public:
	vector<int> partitionLabels(string s) {

		int n = s.size();
		int lastPos[27];
		memset(lastPos, -1, sizeof(lastPos));
		for (int i = n - 1; i >= 0; i--) {
			int c = s[i] - 'a';
			if (lastPos[c] == -1) {
				lastPos[c] = i;
			}
		}

		int l = 0, r = 0, i = 0;
		vector<int> ans;
		while (i <= r && i < n) {
			if (i == r && lastPos[s[i] - 'a'] == r) {
				ans.push_back(r - l + 1);
				l = r = r + 1;
			} else {
				r = max(r, lastPos[s[i] - 'a']);
			}
			i++;
		}

		return ans;
	}
};