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
const ll MOD = 1e9 + 9;

class Solution {
public:
	int n, d;
	vector<int> a;
	int dp[1002];


	int get(int pos) {
		int ans = 0;

		int &anss = dp[pos];
		if (anss != -1) return anss;

		fr(i, pos + 1, n - 1) {
			if (a[i] >= a[pos] || i - pos > d) break;
			ans = max(ans, get(i));
		}

		frr(i, pos - 1, 0) {
			if (a[i] >= a[pos] || pos - i > d) break;
			ans = max(ans, get(i));
		}

		return anss = ans + 1;
	}

	int maxJumps(vector<int>& arr, int dMax) {
		n = arr.size();
		d = dMax;
		a = arr;
		fil(dp, -1);
		int ans = 0;
		rep(i, n) ans = max(ans, get(i));

		return (int)ans;

	}
};