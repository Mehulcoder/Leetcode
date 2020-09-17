
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pll = pair<long long, long long>;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))
const ll MOD = 1e9 + 9;


class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	vector<string> ans;
	ll n;
	void get(string &s, ll start, ll end, string &temp) {
		if (start > end) {
			ans.push_back(temp);
			return;
		}

		if (isalpha(s[start])) {
			char up = toupper(s[start]);
			char lo = tolower(s[start]);

			temp.push_back(up);
			get(s, start + 1, end, temp);
			temp.pop_back();
			temp.push_back(lo);
			get(s, start + 1, end, temp);
			temp.pop_back();
		} else {
			temp.push_back(s[start]);
			get(s, start + 1, end, temp);
			temp.pop_back();
		}

		return;
	}

	vector<string> letterCasePermutation(string S) {
		n = S.size();
		string temp = "";
		get(S, 0, n - 1, temp);
		return ans;
	}
};