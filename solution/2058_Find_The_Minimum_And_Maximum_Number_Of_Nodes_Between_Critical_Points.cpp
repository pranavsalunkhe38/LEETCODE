// LC: 2058 Find The Minimum And Maximum Number Of Nodes Between Critical Points
// Title: Find The Minimum And Maximum Number Of Nodes Between Critical Points
// Difficulty: Medium
// Date: 31 August 2026

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> c;
        int index = 0;

        int prev = -1;
        int next = -1;

        while(head != nullptr){
            int val = head->val;
            next = head->next == nullptr ? -1: head->next->val;

            if(prev != -1 && next != -1){

                if((val < prev && val < next) || (val > prev && val > next)){
                    c.push_back(index);
                }

            }

            prev = head->val;
            head = head->next;
            index++;
        }

        if(c.size() < 2) return {-1,-1};

        int mx = c[c.size()-1] - c[0];
        int mn = INT_MAX;
        for(int i=1; i < c.size(); i++){
            mn = min(mn, c[i] - c[i-1]);
        }

        return {mn,mx};
        
    }
};