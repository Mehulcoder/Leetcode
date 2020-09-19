class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int ans = 0;
	void add(string &s) {
		int carry = 1;
		int pos = s.size() - 1;
		while (pos >= 0 && carry) {
			int carry2 = ((s[pos] - '0') & (carry));
			s[pos] = ('0' + (carry ^ (s[pos] - '0')));
			carry = carry2;
			pos--;
		}

		if (carry) s.insert(s.begin(), '1');
		return;
	}

	int numStepsSlow(string s) {
		while (s.size() > 1) {
			while (s.size() > 1 && s.back() == '0') {
				ans++;
				s.pop_back();
			}

			if (s.size() > 1 && s.back() == '1') {
				ans++;
				add(s);
			}
		}

		return ans;
	}

	int numSteps(string s) {
		int carry = 0;
		for (int i = s.size() - 1; i > 0; i--) {
			// '1'+'0' or 0+1
			if (s[i] - '0' + carry == 1) {
				//Odd-->add 1 --->carry is now one--->andd and rightshift--->2 ops
				ans += 2;
				carry = 1;
			} else {
				//1+1 or 0+0 --> carry remains the same. Only one operation. Right shift
				ans++;
			}
		}

		return ans + carry;
	}
};