/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

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
const ll MOD = 1e9 + 7;


class Solution {
public:
	vll cost;
	ll n;
	vector<string> dp;
	string get(ll target) {
		if (target < 0) return "-1";
		if (target == 0) return "";

		string &ans = dp[target];
		if (ans != "-2") return ans;

		string bestSuff = "";
		string bestAns = "-1";
		rep(i, 9) {
			char curr = '0' + i + 1;
			string temp = get(target - cost[i]);
			if (temp == "-1") continue;
			if (bestSuff.size() < temp.size()) {
				bestSuff = temp;
				bestAns = curr + temp;
			} else if (bestSuff.size() == temp.size()) {
				bestSuff = temp;
				bestAns = curr + temp;
			}
		}

		return ans = bestAns;
	}

	string largestNumber(vector<int>& c, int target) {
		n = c.size();
		rep(i, n) cost.push_back(c[i]);
		dp.resize(target + 1, "-2");
		return (get(target) == "-1" ? "0" : get(target));
	}
};

