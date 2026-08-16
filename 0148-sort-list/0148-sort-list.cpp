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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *right = slow->next;
        slow->next = NULL;

        ListNode *left = sortList(head);
        right = sortList(right);
        return merge(left, right);
    }

    ListNode* merge(ListNode *left,ListNode *right){
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                curr->next = left;
                left = left->next;
            }else{
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

            if(left != NULL){
                curr->next = left;
            }

            if(right != NULL){
                curr->next = right;
            }

            return dummy.next;
    }
};