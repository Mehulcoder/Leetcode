#define f first
#define s second
using ll = long long int;
using pll = pair<ll, ll>;


class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	vector<vector<pll>> edges;
	vector<vector<bool>> s;
	ll n;

	vector<int> shortestAlternatingPaths(int nn, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		n = nn;
		edges.resize(n);
		s.resize(n, vector<bool>(2, 0));
		for (auto &edge : red_edges) {
			edges[edge[0]].push_back({edge[1], 0});
		}

		for (auto &edge : blue_edges) {
			edges[edge[0]].push_back({edge[1], 1});
		}

		vector<int> ans(n, INT_MAX);
		queue<vector<ll>> q;

		//num, col, dis
		q.push({0, 0, 0});
		while (!q.empty()) {
			auto temp = q.front();
			q.pop();

			ans[temp[0]] = min((ll)ans[temp[0]], temp[2]);

			for (auto &child : edges[temp[0]]) {
				if (child.s == !temp[1]) {
					if (s[child.f][child.s] == 1) continue;
					s[child.f][child.s] = 1;
					q.push({child.f, !temp[1], temp[2] + 1});
				}
			}
		}

		s.clear();
		s.resize(n, vector<bool>(2, 0));
		q.push({0, 1, 0});
		while (!q.empty()) {
			auto temp = q.front();
			q.pop();

			ans[temp[0]] = min((ll)ans[temp[0]], temp[2]);

			for (auto &child : edges[temp[0]]) {
				if (child.s == !temp[1]) {
					if (s[child.f][child.s] == 1) continue;
					s[child.f][child.s] = 1;
					q.push({child.f, !temp[1], temp[2] + 1});
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (ans[i] == INT_MAX) ans[i] = -1;
		}

		return ans;

	}


};
