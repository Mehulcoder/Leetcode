
/*
* https://www.youtube.com/watch?v=hA408ZMan1Q&ab_channel=LeadCoding
*/
class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	int count;

	vector<int> get(TreeNode* root, int distance) {
		if (root == NULL) return {};
		if ((root->left == NULL) && (root->right == NULL)) {
			return {1};
		}

		auto l = get(root->left, distance);
		auto r = get(root->right, distance);

		for (auto &l1 : l) {
			for (auto &r1 : r) {
				if (l1 + r1 <= distance) count++;
			}
		}
		vector<int> temp;
		for (auto &l1 : l) {
			if (l1 < distance) {
				temp.push_back(l1 + 1);
			}
		}

		for (auto &r1 : r) {
			if (r1 < distance) {
				temp.push_back(r1 + 1);
			}
		}

		return temp;
	}

	int countPairs(TreeNode* root, int distance) {
		count = 0;
		get(root, distance);
		return count;
	}
};