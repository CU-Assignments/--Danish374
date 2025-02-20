Problem 1

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

CODE:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;

        ListNode* head = dummy->next;
        delete dummy;
        return head;        
    }
};

Problem 2:

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

CODE:
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* temp = head->next;
        bool flag = false;

        while (temp != nullptr) {
            if (curr->val != temp->val) {
                if (flag) {
                    prev->next = temp;
                    flag = false;
                } else {
                    prev = prev->next;
                }
            } else {
                flag = true;
            }
            temp = temp->next;
            curr = curr->next;
        }
        
        if (flag) {
            prev->next = temp;
        }
        
        return dummy->next;
    }
};
