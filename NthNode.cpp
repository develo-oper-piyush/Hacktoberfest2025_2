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
    ListNode* findNthNode(ListNode* temp, int x){
        int cnt = 1;
        while (temp != nullptr){
            if (cnt == x) return temp;
            cnt++;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        ListNode* tail = head;
        int len = 1;

        while (tail -> next != nullptr){
            tail = tail -> next;
            len++;
        }

        if (k%len == 0) return head;

        k = k%len;
        tail -> next = head;

        ListNode* newLast = findNthNode(head, len - k);

        head = newLast -> next;
        newLast -> next = nullptr;

        return head;
    }
};
