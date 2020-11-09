class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    string strSort(string &s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;

        for (auto &elem : strs) {
            string s = elem;
            s = strSort(s);
            m[s].push_back(elem);
        }

        vector<vector<string>> ans;


        for (auto &elemm : m) {
            auto &elem = elemm.second;
            vector<string> temp;
            if (elem.size()) {
                for (auto &ele : elem) {
                    temp.push_back(ele);
                }

                ans.push_back(temp);
            }
        }

        return ans;
    }
};