using ll = unsigned long long int;
using ld  = long double;

class Solution {
public:
	ll ans = 1e18;
	ll num;
	bool check(ll len, ll base) {
		ll sum = 0;
		ll curr = 0;
		ll adder = 1;
		while (curr < len) {
			sum += adder;
			adder *= base;
			if (sum > num) return 1;
			curr++;
		}

		if (sum > num) return 1;
		if (sum == num) ans = min(ans, base);
		return 0;
	}

	string smallestGoodBase(string n) {
		num = stoll(n);
		ans = num - 1;
		for (int len = log2(num + 1); len >= 2; --len) {
			ll lo = 2, hi =  pow(num, 1.0 / (len - 1)) + 1;;
			while (lo <= hi) {
				ll mid = (lo + hi) / 2;
				if (check(len, mid)) {
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
		}

		return to_string(ans);
	}
};