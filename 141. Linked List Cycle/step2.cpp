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
        int INF = 101010;
        ListNode *now = head;
        while(now != nullptr){
            if(now->val == INF)return true;
            now->val = INF;
            now = now->next;
        }
        return false;
    }
};