class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool wordPattern(string pattern, string str) {
        vector<string> words;
        int n = str.size();
        string curr = "";
        for (int i = 0; i < n ; i++) {
            if (str[i] == ' ') {
                words.push_back(curr);
                curr = "";
            } else {
                curr += str[i];
            }
        }
        words.push_back(curr);
        if (words.size() != pattern.size()) return 0;

        vector<string> m(27, "");
        for (int i = 0 ; i < pattern.size(); i++) {
            int c = pattern[i] - 'a';
            if (m[c] == "" || m[c] == words[i]) m[c] = words[i];
            else return 0;
        }
        set<string> s;
        for (int i = 0; i < 27; i++) {
            if (s.find(m[i]) != s.end() && m[i] != "") return 0;
            s.insert(m[i]);
        }
        return 1;

    }
};