class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n;
	unordered_set<string> emails;
	unordered_map<int, set<string>> m2;
	unordered_map<string, int> m;
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		n = accounts.size();
		int curr = -1;
		for (auto &account : accounts) {
			curr++;
			int owner = -1;
			set<int> owners;
			for (int i = 1; i < account.size(); ++i) {
				if (emails.find(account[i]) != emails.end()) {
					owner = m[account[i]];
					owners.insert(owner);
				}
			}

			if (owners.size() != 0) {
				owner = *owners.begin();
				int i = 0;
				for (auto &oww : owners) {
					if (i == 0) {
						i++;
						continue;
					};
					for (auto &email : m2[oww]) {
						m2[owner].insert(email);
						m[email] = owner;
					}
					i++;
					m2.erase(oww);
				}
			}


			for (int i = 1; i < account.size(); ++i) {
				emails.insert(account[i]);
			}

			if (owner != -1) {
				for (int i = 1; i < account.size(); ++i) {
					m2[owner].insert(account[i]);
					m[account[i]] = owner;
				}
			} else {
				for (int i = 1; i < account.size(); ++i) {
					m2[curr].insert(account[i]);
					m[account[i]] = curr;
				}
			}

		}

		vector<vector<string>> ans;
		for (auto &elem : m2) {
			vector<string> temp;
			string owner = accounts[elem.first][0];
			temp.push_back(owner);
			for (auto &email : elem.second) {
				temp.push_back(email);
			}
			ans.push_back(temp);
		}

		return ans;
	}
};