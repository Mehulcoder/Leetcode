/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }


    pair<Node*, Node*> get(Node* root) {
        if (!(root->next) && !(root->child)) return {root, root};
        if (root->child) {
            if (root->next) {
                auto buffer = root->next;
                auto temp2 = get(buffer);
                auto headNext = temp2.first;
                auto tailNext = temp2.second;
                auto temp = get(root->child);
                auto headChild = temp.first;
                auto tailChild = temp.second;

                root->child = NULL;
                root->next = headChild;
                headChild->prev = root;
                tailChild->next = buffer;
                headNext->prev = tailChild;
                tailChild->next = headNext;
                headNext->child = NULL;
                tailNext->next = NULL;
                tailNext->child = NULL;
                return {root, tailNext};
            } else {
                auto temp = get(root->child);
                auto headChild = temp.first;
                auto tailChild = temp.second;

                root->next = headChild;
                root->child = NULL;
                headChild->prev = root;
                tailChild->next = NULL;
                return {root, tailChild};
            }
        } else {
            auto temp = get(root->next);
            (temp.second)->next = NULL;
            (temp.second)->child = NULL;
            root->next = temp.first;
            (temp.first)->prev = root;
            return {root, temp.second};
        }

    }

    Node* flatten(Node* head) {
        if (head == NULL) return NULL;
        return get(head).first;
    }

};