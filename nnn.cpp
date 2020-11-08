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


int main(int argc, char *argv[]) {

        ll n, q;

        cin >> n >> q;

        vll ages(n, INF);
        bool ok = 1;
        rep(i, q) {
                ll a, b, w;
                cin >> a >> b >> w;
                a--; b--;
                if (a == b && w != 0) {
                        ok = 0;
                        continue;
                }

                if (i == 0) {
                        ages[a] = 0;
                        ages[b] = w;
                } else {
                        if (ages[a] == INF && ages[b] == INF) {
                                ok = 0;
                        } else if (ages[b] == INF) {
                                ages[b] = ages[a] + w;
                        } else if (ages[a] == INF) {
                                ages[a] = ages[b] - w;
                        } else {
                                if (ages[b] - ages[a] != w)ok = 0;
                        }
                }
        }

        if (!ok) {
                cout << -1 << '\n';
                return 0;
        } else {
                rep(i, n) {
                        if (ages[i] == INF) ages[i] = 0;
                }
                sort(all(ages));
                cout << ages[n - 1] - ages[0] << '\n';
        }

        return 0;
}
