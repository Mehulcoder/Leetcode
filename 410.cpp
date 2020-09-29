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

	int splitArray(vector<int>& nums, int m) {
		ll lo = 0, hi = 1e9;
		ll n = nums.size();
		ll ans = hi;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			ll curr = 1, sum = 0;
			bool ok = 1;
			rep(i, n) {
				sum += nums[i];
				if (sum > mid) {
					sum = nums[i];
					if (sum > mid) ok = 0;
					curr++;
				}
			}

			if (sum > mid) curr++;

			if (curr <= m && ok) {
				hi = mid - 1;
				ans = min(ans, mid);
			} else {
				lo = mid + 1;
			}
		}

		return ans;
	}
};