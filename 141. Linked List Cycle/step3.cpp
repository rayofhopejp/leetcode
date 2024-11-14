/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *now = head;
        int INF = 112345;
        while(now != nullptr){
            if(now->val == INF)return true;
            now->val = INF;
            now = now->next;
        }
        return false;
    }
};