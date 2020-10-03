/*
Author: Mehul Chaturvedi
Talent is overrated
*/

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fil(ar, val) memset(ar, val, sizeof(ar))

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<vll> jobs;
	ll dp[50010], n;

	static bool mySort(vll &a, vll &b) {
		return (a[1] < b[1]);
		if (a[1] == b[1]) return a[0] < b[0];
		return 0;
	}

	ll getUpper(ll end, ll val) {
		ll lo = 0;
		ll hi = end - 1;

		ll ans = -1;
		while (lo <= hi) {
			ll mid = (lo + hi) / 2;

			if (jobs[mid][1] > val) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
				ans = mid;
			}
		}

		return ans;
	}

	ll get(ll end) {
		if (end < 0) return 0;

		if (dp[end] != -1) return dp[end];

		ll poss1 = get(end - 1);
		ll poss2 = jobs[end][2];

		ll start = jobs[end][0];
		ll ind = getUpper(end, start);

		if (ind >= 0 && ind < end) {
			poss2 += get(ind);
		}


		return dp[end] = max(poss1, poss2);

	}

	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		n = startTime.size();
		fil(dp, -1);
		jobs.resize(n, vll(3));
		rep(i, n) {
			jobs[i][0] = startTime[i];
			jobs[i][1] = endTime[i];
			jobs[i][2] = profit[i];
		}

		sort(all(jobs), mySort);
		return (int)get(n - 1);
	}
};