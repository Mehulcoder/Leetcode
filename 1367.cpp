/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

	bool isSubPathFromHere(ListNode* head, TreeNode* root) {
		if (!head) return 1;
		if (!root) return 0;


		if (head->val == root->val) {
			bool a = isSubPathFromHere(head->next, root->left);
			bool b = isSubPathFromHere(head->next, root->right);

			return (a || b);
		} else {
			return  0;
		}
	}


	bool isSubPath(ListNode* head, TreeNode* root) {
		if (!head) return 1;
		if (!root) return 0;

		if (isSubPathFromHere(head, root)) return 1;
		else {
			return (isSubPath(head, root->left) || isSubPath(head, root->right));
		}
	}
};