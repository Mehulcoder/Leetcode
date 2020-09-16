/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll =  pair<long long, long long>;

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
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	DSU dsu;
	bool similar(string &a, string &b) {
		int n = 0;
		for (int i = 0; i < a.size(); i++)
			if (a[i] != b[i] && ++n > 2)
				return false;
		return true;
	}

	int numSimilarGroups(vector<string>& A) {
		dsu.init(A.size());
		for (int i = 0; i < A.size(); i++)
			for (int j = i + 1; j < A.size(); j++)
				if (similar(A[i], A[j]))
					dsu.unionSets(i, j);
		return dsu.connected;
	}
};