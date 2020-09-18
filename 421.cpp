
#define trav(a, x) for(auto& a : x)


class trie {
public:
	trie* left;
	trie* right;
	int val;

	trie(int val) {
		this->left = NULL;
		this->right = NULL;
		this->val = val;
	}

	void add(int num) {
		trie* temp = this;
		for (int i = 31; i >= 0; --i) {
			int bit = ((1 << i) & num) != 0;
			if (bit) {
				if (temp->right) {
					temp = temp->right;
				} else {
					temp->right = new trie(1);
					temp = temp->right;
				}
			} else {
				if (temp->left) {
					temp = temp->left;
				} else {
					temp->left = new trie(0);
					temp = temp->left;
				}
			}
		}
		return;
	}

};

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int findMaximumXOR(vector<int>& nums) {
		auto temp = new trie(2);
		int n = nums.size();

		trav(elem, nums) {
			temp->add(elem);
		}

		int ans = 0;
		trav(elem, nums) {
			auto mover = temp;
			int maxXorFor = 0;

			for (int i = 31; i >= 0; --i) {
				int bit = ((1 << i) & elem) != 0;
				int bitToAdd = 0;
				if (bit) {
					//Look for 0
					bitToAdd = (mover->left != NULL);
					if (bitToAdd) mover = mover->left;
					else mover = mover->right;
				} else {
					//Look for 1 as 0^1=1
					bitToAdd = (mover->right != NULL);
					if (bitToAdd) mover = mover->right;
					else mover = mover->left;
				}
				maxXorFor = ((bitToAdd << i) | (maxXorFor));
			}
			ans = max(maxXorFor, ans);
		}
		return ans;
	}
};