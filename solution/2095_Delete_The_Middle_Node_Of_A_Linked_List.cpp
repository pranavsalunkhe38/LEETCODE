// LC: 2095 Delete The Middle Node Of A Linked List
// Title: Delete The Middle Node Of A Linked List
// Difficulty: Medium
// Date: 15 June 2026

#include <bits/stdc++.h>
using namespace std;

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        int mid = cnt/2;
        if(cnt == 1) return nullptr;

        temp = head;
        ListNode* prev = nullptr;

        for(int i=0; i < mid; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        // free(temp);

        return head;
        
    }
};