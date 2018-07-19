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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        length = 0;
        first = head;
        ListNode * node = head;
        while(node){
            length++;
            node = node->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int cur = random()%length;
        ListNode * node = first;
        while(cur != 0){
            node = node->next;
            cur--;
        }
        
        return node->val;
    }
private:
    int length;
    ListNode * first;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */