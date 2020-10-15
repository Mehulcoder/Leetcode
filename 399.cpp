class Solution {

public:

	void dfs(unordered_map<string, vector<pair<string, double>>> &mp, string &source, string &destination, unordered_map<string, int> &visited, double &ans , double temp) {
		if (visited.count(source)) return;

		visited[source] = 1;

		if (source == destination) {
			ans = temp;
			return;
		}

		for (auto x : mp[source]) {
			dfs(mp, x.first, destination, visited, ans, temp * x.second);
		}

		return;

	}


	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {


		unordered_map<string, vector<pair<string, double>>> mp;

		for (int i = 0; i < equations.size(); i++) {
			mp[equations[i][0]].push_back({equations[i][1], values[i]});
			mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
		}

		vector<double> v;
		for (int i = 0; i < queries.size(); i++) {
			string s = queries[i][0];
			string d = queries[i][1];
			double ans = -1;
			unordered_map<string, int> visited;
			if (mp.count(s))
				dfs(mp, s, d, visited, ans, 1.0);
			v.push_back(ans);
		}

		return v;

	}
};