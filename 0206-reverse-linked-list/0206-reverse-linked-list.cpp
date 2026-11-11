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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr){
            ListNode* nextTemp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextTemp;
        }
       return (prev); 

    }
};

//Take two pointers first, initialise one with null and other with the head. With each iteration reverse the pointing direction of one node.
//Take help of a third node inside the loop which keeps the record of the next node whose linking direction is to be reversed.
//With each loop interation the first two pointers move forward by a step making room for the next interation to take place.