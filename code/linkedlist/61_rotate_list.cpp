/*************************************************************************
# File Name: 61_rotate_list.cpp
# Author : Wenjing Fan  
# Email: fwjfan@ucdavis.edu
# Created Time: Sat Nov 21 17:17:27 2020
 ************************************************************************/

#include<iostream>
using namespace std;

*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (not head or not head->next) return head;
        int n = 0;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *tail = &dummy;
        while (tail->next) {
            n++;
            tail = tail->next;
        }
        k = k % n;
        if (k == 0) return dummy.next;
        ListNode *cur = &dummy;
        for (int i = 0; i < (n - k); ++i) {
            cur = cur->next;
        }
        tail->next = dummy.next;
        dummy.next = cur->next;
        cur->next = NULL;
        return dummy.next;
    }
};
