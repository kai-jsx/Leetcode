class Solution {
public:
    void deleteNode(ListNode* node) {
        // 1. Copy the value from the next node into the target node
        node->val = node->next->val;
        
        // 2. Store the next node to free memory
        ListNode* temp = node->next;
        
        // 3. Bypass the next node
        node->next = node->next->next;
        
        // 4. Free memory
        //delete temp;
    }
};