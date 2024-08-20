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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* temp = head->next;
        ListNode* prev = head;
        ListNode* pprev = nullptr;
        head = temp;

        while (temp != nullptr && prev != nullptr) {
            prev->next = temp->next;
            temp->next = prev;
            if (pprev != nullptr) {
                pprev->next = temp;
            }
            pprev = prev;
            prev = prev->next;
            if (prev != nullptr) {
                temp = prev->next;
            }
        }
        return head;
    }
};
