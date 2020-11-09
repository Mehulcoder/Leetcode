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
class Solution {
public:
        Solution() {
                ios::sync_with_stdio(false);
                cin.tie(NULL);
                cout.tie(NULL);
        }

        vector<int> get(TreeNode* root) {
                if (!root) return {0, INT_MIN, INT_MAX};
                auto l = get(root->left);
                auto r = get(root->right);

                int ans = max(l[0], r[0]);
                if (l[1] != INT_MIN) {
                        ans = max({ans, abs(root->val - l[1]), abs(root->val - l[2])});
                }
                if (r[1] != INT_MIN) {
                        ans = max({ans, abs(root->val - r[1]), abs(root->val - r[2])});
                }

                int maxi = max({root->val, l[1], r[1]});
                int mini = min({root->val, l[2], r[2]});

                return {ans, maxi, mini};
        }

        int maxAncestorDiff(TreeNode* root) {
                return (int)get(root)[0];

        }
};