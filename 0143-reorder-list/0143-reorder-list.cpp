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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        slow->next = NULL;

        ListNode *prev = NULL;
        ListNode *curr = second;

        while(curr != NULL){
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *first = head;
        ListNode dummy(0);
        ListNode *temp = &dummy;
        while(first != NULL && prev != NULL){
            temp->next = first;
            temp = temp->next;
            first = first->next;
            temp->next = prev;
            temp = temp->next;
            prev = prev->next;
        }

        while(first != NULL){
            temp->next = first;
            temp = temp->next;
            first = first->next;
        }

    }
};