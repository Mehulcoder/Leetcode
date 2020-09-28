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
	vvll grid;
	ll n, m;

	ll get(ll x1, ll y1, ll x2) {
		ll y2 = (x1 + y1 - x2);


	}

	int cherryPickup(vector<vector<int>>& gridd) {
		n = gridd.size();
		m = gridd[0].size();

		rep(i, n) {
			rep(j, m) {
				grid[i][j] = gridd[i][j];
			}
		}

		return get(0, 0, 0);
	}
};

ll power(ll a, ll b) {	//a is base, b is exponent
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % mod;
	ll q = power(a, b / 2);
	return (q * q) % mod;
}