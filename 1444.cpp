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
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<string> mat;
	vvll sum;
	ll n, m;
	ll dp[51][51][11];
	void getSum() {
		rep(i, n) {
			sum[i][0] = (mat[i][0] == 'A');
			if (i > 0) sum[i][0] += sum[i - 1][0];
		}

		rep(i, m) {
			sum[0][i] = (mat[0][i] == 'A');
			if (i > 0) sum[0][i] += sum[0][i - 1];
		}

		fr(i, 1, n - 1) {
			fr(j, 1, m - 1) {
				sum[i][j] = (mat[i][j] == 'A');
				sum[i][j] += sum[i - 1][j];
				sum[i][j] += sum[i][j - 1];
				sum[i][j] -= sum[i - 1][j - 1];

			}
		}

		return;
	}


	ll get(ll rowCount, ll colCount, int k) {
		if (!k) return 1;

		ll &ans = dp[rowCount][colCount][k];
		if (ans != -1) return ans;

		//Cut along the vertical line

		ll totalApples = 0ll;
		totalApples += sum[n - 1][m - 1];


		if (n >= rowCount + 1)
			totalApples -= sum[n - rowCount - 1][m - 1];

		if (m >= colCount + 1)
			totalApples -= sum[n - 1][m - colCount - 1];

		if (n >= rowCount + 1 && m >= colCount + 1)
			totalApples += sum[n - rowCount - 1][m - colCount - 1];

		ll ans1 = 0;
		ll ans2 = 0;
		fr(ci, 1, colCount - 1) {
			bool ok = 0;
			ll appleGiven = sum[n - 1][m - 1 - ci];

			if (n >= 1 && m >= colCount + 1)
				appleGiven -= sum[n - 1][m - colCount - 1];

			if (n >= rowCount + 1 && m >= ci + 1)
				appleGiven -= sum[n - rowCount - 1][m - ci - 1];

			if (n >= rowCount + 1 && m >= colCount + 1)
				appleGiven += sum[n - rowCount - 1][m - colCount - 1];

			ok = (appleGiven > 0) && (totalApples - appleGiven > 0);
			assert(appleGiven >= 0);

			if (ok) {
				ans1 += get(rowCount, ci, k - 1);
			}

		}

		fr(ri, 1, rowCount - 1) {
			bool ok = 0;
			ll appleGiven = sum[n - ri - 1][m - 1];

			if (n >= rowCount + 1 && m >= 1)
				appleGiven -= sum[n - 1 - rowCount][m - 1];

			if (n >= ri + 1 && m >= colCount + 1)
				appleGiven -= sum[n - ri - 1][m - colCount - 1];

			if (n >= rowCount + 1 && m >= colCount + 1)
				appleGiven += sum[n - rowCount - 1][m - colCount - 1];

			ok = (appleGiven > 0) && (totalApples - appleGiven > 0);
			assert(appleGiven >= 0);

			if (ok) {
				ans2 += get(ri, colCount, k - 1);
			}

		}

		ans1 = (ans1 + MOD) % MOD;
		ans2 = (ans2 + MOD) % MOD;

		return ans = (ans1 + ans2) % MOD;
	}

	int ways(vector<string>& pizza, int k) {
		mat = pizza;
		n = pizza.size();
		m = pizza[0].size();

		memset(dp, -1, sizeof(dp));

		sum.resize(n, vll(m, 0));
		getSum();


		return get(n, m, k - 1);
	}
};