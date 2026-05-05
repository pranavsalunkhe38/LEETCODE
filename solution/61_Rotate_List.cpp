// LC: 61 Rotate List
// Title: Rotate List
// Difficulty: Medium
// Date: 05 May 2026

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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        vector<int> v;
        ListNode* x = head;

        while(x != nullptr){
            v.push_back(x->val);
            x = x->next;
        }

        k = k % v.size();

        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin()+k);
        reverse(v.begin()+k, v.end());

        x = head;

        for(int i=0; i < v.size(); i++, x = x->next){
            x->val = v[i];
        }

        return head;
        
    }
};
