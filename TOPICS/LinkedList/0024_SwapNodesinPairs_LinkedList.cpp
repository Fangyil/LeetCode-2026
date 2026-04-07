// Runtime: 0ms, beats: 100.00%

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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *current = dummy;

        while (current->next && current->next->next) {
            ListNode *first = current->next;
            ListNode *second = current->next->next;

            // swap
            first->next = second->next;
            second->next = first;
            current->next = second;

            // move forward
            current = first;
        }

        return dummy->next;
    }
};
