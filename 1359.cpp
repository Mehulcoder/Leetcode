using ll = long long int;
const int MOD = 1e9 + 7;
const ll N = 2e3 + 10;



class Solution {
public:
	ll power(ll a, ll b, ll mod = MOD) {	//a is base, b is exponent
		if (b == 0)
			return 1;
		if (b == 1)
			return a;
		if (b % 2 == 1)
			return (power(a, b - 1) * a) % mod;
		ll q = power(a, b / 2);
		return (q * q) % mod;
	}

	vector<ll> fact;

	void precalc() {
		fact.resize(N, 1);

		for (int i = 2; i <= N - 1; i++) {
			fact[i] = (fact[i - 1] * i) % MOD;
		}
		return;
	}

	ll gcdExtended(ll a, ll b, ll &x, ll &y) {
		if (a == 0) {
			x = 0;
			y = 1;
			return b;
		}

		ll x1, y1;
		ll d = gcdExtended(b % a, a, x1, y1);
		x = y1 - (b / a) * x1;
		y = x1;
		return d;
	}

	ll modInverse(ll a, ll mod) {
		ll x, y;
		ll d = gcdExtended(a, mod, x, y);
		if (d != 1) {
			return -1;
		}

		return (x % mod + mod) % mod;
	}
	int countOrders(int n) {
		ll ans = modInverse((power(2, n)), MOD) * (fact[2 * n]);
		ans %= MOD;
		return (int)ans;
	}
};