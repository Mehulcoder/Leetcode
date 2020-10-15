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


class DSU {
public:
	ll connected;
	vll parent, sizes;

	DSU() {}

	void init(ll n) {
		parent.clear();
		sizes.clear();
		parent.resize(n, 0);
		sizes.resize(n, 1);

		rep(i, n) {
			parent[i] = i;
			sizes[i] = 1;
		}
		connected = n;
	}

	ll findSet(ll u) {
		if (parent[u] == u) return u;
		return parent[u] = findSet(parent[u]);
	}

	bool unionSets(ll u, ll v) {
		ll a = findSet(u);
		ll b = findSet(v);
		if (a != b) {
			connected--;
			if (sizes[a] < sizes[b]) swap(a, b);
			parent[b] = a;
			sizes[a] += sizes[b];
		} else {
			return 0;
		}

		return 1;
	}

};


class Solution {
public:
	unordered_map<ll, ll> rHeads;
	unordered_map<ll, ll> cHeads;
	map<pll, ll> ind;
	ll m, n;

	DSU dsu;
	int countServers(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();
		dsu.init(m * n + 10);

		ll curr = 0;
		rep(i, n) {
			rep(j, m) {
				if (grid[i][j] == 1) {
					ind[ {i, j}] = curr++;
					if (rHeads.find(i) == rHeads.end()) {
						rHeads[i] = ind[ {i, j}];
					}
					if (cHeads.find(j) == cHeads.end()) {
						cHeads[j] = ind[ {i, j}];
					}
				}
			}
		}


		rep(i, n) {
			rep(j, m) {
				if (grid[i][j] == 1) {
					dsu.unionSets(ind[ {i, j}], rHeads[i]);
				}
			}
		}

		rep(j, m) {
			rep(i, n) {
				if (grid[i][j] == 1) {
					dsu.unionSets(ind[ {i, j}], cHeads[j]);
				}
			}
		}

		auto temp = dsu.sizes;
		unordered_set<ll> s;
		ll ans = 0ll;
		rep(i, temp.size()) {
			ll par = dsu.findSet(i);
			if (s.find(par) == s.end() && temp[par] > 1) {
				ans += temp[par];
				s.insert(par);
			}
		}

		return (int)ans;

	}
};