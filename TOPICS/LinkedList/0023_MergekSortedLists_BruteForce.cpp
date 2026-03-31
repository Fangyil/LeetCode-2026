// Runtime: 3ms, beats: 63.78%

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *merged = new ListNode(0);
        ListNode *tmp = merged;

        int n, min, i, times, empty;
        n = lists.size();
        min = INT_MAX;
        i = times = empty = 0;

        while (n != empty) {

            while (lists[i] == nullptr) {
                empty++;
                i++;
                if (i == n)
                    break;
            }

            // cout << "empty arr: " << i << endl;
            if (n == empty)
                break;

            while (i < n) {
                while (i < n && lists[i] == nullptr) {
                    i++;
                    empty++;
                }
                if (i == n)
                    break;

                // cout << "i " << i << endl;
                if (lists[i]->val <= min) {
                    if (lists[i]->val < min)
                        times = 0;
                    min = lists[i]->val;
                    times++;
                    // cout << "finding: " << min << endl;
                }
                i++;
            }

            i--;

            while (times) {
                while (lists[i] == nullptr)
                    i--;

                if (lists[i]->val == min) {
                    tmp->next = new ListNode(min);
                    tmp = tmp->next;
                    lists[i] = lists[i]->next;
                    times--;
                    // cout << min << " ";
                }
                i--;
            }

            // cout << "empty arr: " << empty << endl;

            // initialize
            min = INT_MAX;
            times = 0;
            empty = 0;
            i = 0;
        }

        return merged->next;
    }
};
