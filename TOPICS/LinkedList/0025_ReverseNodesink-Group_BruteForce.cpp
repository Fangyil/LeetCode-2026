// Runtime: 2ms, beats: 3.72%

#include <iostream>
using namespace std;

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *ans = new ListNode(0);
        ListNode *current = ans;

        while (head != nullptr) {

            ListNode *tmp = new ListNode(head->val);
            ListNode *reversed = new ListNode(head->val);
            ListNode *tmp_t = tmp;
            head = head->next;
            int i;
            for (i = 1; i < k && head != nullptr; i++) {
                tmp_t->next = new ListNode(head->val);
                // cout << head->val << endl;
                tmp_t = tmp_t->next;

                ListNode *t = reversed;
                reversed = new ListNode(head->val);
                reversed->next = t;
                // reversed = reversed->next;
                // cout << reversed->val << " " << reversed->next->val << endl;

                head = head->next;
            }

            // cout << "Here" << endl;
            if (i < k) {
                current->next = tmp;
                break;
            }
            current->next = reversed;
            current = current->next;

            // checked current situation
            // cout << "current: ";
            while (current->next != nullptr) {
                // cout << current->val << " ";
                current = current->next;
            }
            // cout << endl;
        }

        return ans->next;
    }
};
