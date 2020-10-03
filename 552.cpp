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
	ll n;
	ll dp[100005][3][2][2];
	ll get(ll start, ll prevState, bool wasAbsent, bool isPrevprevLate) {
		if (start == n) {
			return 1;
		}

		if (prevState == -1) {
			return get(start + 1, 0, 1, 0) + get(start + 1, 1, 0, 0) + get(start + 1, 2, 0, 0);
		}

		ll &anss = dp[start][prevState][wasAbsent][isPrevprevLate];
		if (anss != -1) return anss;

		if (prevState == 0) return anss = (MOD + get(start + 1, 1, 1, 0) + get(start + 1, 2, 1, 0)) % MOD;

		if (prevState == 1) {
			ll ans = 0;
			if (!wasAbsent) {
				ans += get(start + 1, 0, 1, 0);
			}

			if (!isPrevprevLate) {
				ans += get(start + 1, 1, wasAbsent, 1);
			}

			ans += get(start + 1, 2, wasAbsent, 0);
			return anss = (ans + MOD) % MOD;
		}

		if (prevState == 2) {
			ll ans = 0;
			if (!wasAbsent) ans += get(start + 1, 0, 1, 0);
			ans += get(start + 1, 1, wasAbsent, 0);
			ans += get(start + 1, 2, wasAbsent, 0);

			return anss = (ans + MOD) % MOD;
		}

		return -1;

	}

	int checkRecord(int nn) {
		n = nn;
		fil(dp, -1);
		return (MOD + get(0, -1, 0, 0)) % MOD;
	}
};