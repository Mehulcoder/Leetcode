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
class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	struct myComp {
		bool operator()(ListNode* a,  ListNode* b)const {
			return a->val < b->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* ans = new ListNode();
		auto head = ans;

		multiset<ListNode*, myComp> m;
		for (auto &elem : lists) {
			if (elem) {
				m.insert(elem);
			}
		}
		if (!m.size()) return NULL;

		while (m.size()) {
			auto tp = *(m.begin());
			m.erase(m.begin());
			ans->val = tp->val;
			if (tp->next) m.insert(tp->next);
			if (m.size()) {
				ans->next = new ListNode();
				ans = ans->next;
			}

		}

		return head;

	}
};