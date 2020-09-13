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
	TreeNode* get(ListNode* head) {
		if (head == NULL) return NULL;
		if (!head->next) return new TreeNode(head->val);
		auto slow = head, fast = head->next;

		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		auto mid = slow->next;
		slow->next = NULL;
		TreeNode* root = new TreeNode(mid->val);
		root->left = get(head);
		root->right = get(mid->next);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		return get(head);
	}
};