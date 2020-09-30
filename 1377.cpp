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
	vvll edges;
	vll depthCount;
	vll childCount;
	vll parent;
	bool ok = 0;
	ll t, target;
	void dfs(ll root, ll pos = 0, ll par = -1) {
		if (pos > t) return;

		parent[root] = par;
		childCount[root] = edges[root].size() - (par != -1);

		depthCount[pos]++;
		if (root == target && pos == t) ok = 1;
		if (root == target && pos < t && childCount[root] == 0) ok = 1;

		trav(child, edges[root]) {
			if (child != par) {
				dfs(child, pos + 1, root);
			}
		}

		return;
	}
	double frogPosition(int n, vector<vector<int>>& graph, int tt, int targett) {
		edges.resize(n);
		depthCount.resize(n + 1, 0);
		childCount.resize(n, 0);
		parent.resize(n, -1);

		t = tt;
		target = targett - 1;

		trav(elem, graph) {
			edges[elem[0] - 1].push_back(elem[1] - 1);
			edges[elem[1] - 1].push_back(elem[0] - 1);
		}

		dfs(0);
		if (!ok) return 0;
		ld ans = 1.0;
		while (parent[target] != -1) {
			cout << childCount[parent[target]] << endl;
			ans *= (1.0 / (childCount[parent[target]]));
			target = parent[target];
		}

		return ans;
	}
};