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
ListNode* Search(ListNode* start,int x)
    {
        if (start == nullptr)
        {
            return nullptr;
        }
        else
        {
            bool flag = false;
            ListNode *temp;
            temp = start;
            while (temp != nullptr && !flag)
            {
                if (temp->val == x)
                {
                    flag = true;
                    return temp;
                }
                temp = temp->next;
            }
            return temp;
        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *temp1 = Search(head,val);
        if (temp1 == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                ListNode *to_delete = temp;
                temp = temp->next;
                delete to_delete;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};