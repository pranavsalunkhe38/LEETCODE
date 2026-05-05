// LC: 61 Rotate List
// Title: Rotate List
// Difficulty: Medium
// Date: 05 May 2026

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

        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        ListNode* temp = head;
        ListNode* tail = nullptr;
        int n=0;

        while(temp != nullptr){
            n++;
            tail = temp;
            temp = temp->next;
        }

        k = k % n;
        if(k == 0) return head;
        tail->next = head;
       
        ListNode* newtail = head;
        ListNode* newhead = nullptr;
        // cout<<n-k<<endl;

        for(int i=0; i < n-k-1; i++){
            newtail = newtail->next;
        }
        newhead = newtail->next;
        newtail->next = nullptr;

        return newhead;


    }
};