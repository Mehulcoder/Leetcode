/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

class Solution {
public:
	vvll get(TreeNode* root) {
		if (!root) return {};
		if (!(root->left) && !(root->right)) {
			vll p(10, 0);
			p[root->val]++;
			vvll full;
			full.push_back(p);
			return full;
		}

		auto a = get(root->left);
		auto b = get(root->right);

		for (auto &vec : a) {
			vec[root->val]++;
		}

		for (auto &vec : b) {
			vec[root->val]++;
			a.push_back(vec);
		}

		return a;
	}

	int pseudoPalindromicPaths(TreeNode* root) {
		auto temp = get(root);
		int ans = 0;

		trav(vec, temp) {
			ll n = vec.size();
			ll oddCount = 0;
			rep(i, n) {
				cout << vec[i] << " ";
			}
			cout << endl;
			rep(i, n) {
				if (vec[i] % 2 != 0) oddCount++;
			}

			if (oddCount == 0 || oddCount == 1) {
				ans++;
			}
		}

		return ans;
	}
};