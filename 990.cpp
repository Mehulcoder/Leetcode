/*
Author: Mehul Chaturvedi
Talent is overrated
*/

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



class DSU {
public:
	ll connected;
	vll parent, rankk;

	DSU() {}

	void init(ll n) {
		parent.clear();
		rankk.clear();
		parent.resize(n, 0);
		rankk.resize(n, 0);

		rep(i, n) {
			parent[i] = i;
			rankk[i] = 0;
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
			if (rankk[a] < rankk[b]) swap(a, b);
			parent[b] = a;
			if (rankk[b] == rankk[a]) rankk[a]++;
		} else {
			return 0;
		}

		return 1;
	}

	ll getRank(ll u) {
		return rankk[u];
	}
};


class Solution {
public:
	DSU dsu;
	bool equationsPossible(vector<string>& equations) {
		dsu.init(2 * equations.size());
		trav(elem, equations) {
			int el1 = elem.front() - 'a';
			int el2 = elem.back() - 'a';

			if (elem[2] == '=') {
				dsu.unionSets(el1, el2);
			}
		}
		cout << dsu.findSet(0) << '\n';
		trav(elem, equations) {
			int el1 = elem.front() - 'a';
			int el2 = elem.back() - 'a';

			if (elem[2] == '!') {
				if (dsu.findSet(el1) == dsu.findSet(el2)) return 0;
			}
		}

		return 1;
	}
};