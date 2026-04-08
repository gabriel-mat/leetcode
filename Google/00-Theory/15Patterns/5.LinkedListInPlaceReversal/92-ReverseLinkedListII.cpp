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

//  Para simplificar a inversão no meio da lista, 
// usamos uma ideia de stack, removendo o nó e 
// adicionando na "head" (no left) da pilha.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode *dummy = new ListNode(0);

        dummy->next = head;
        ListNode *prev = dummy;

        for (int i = 0; i < left - 1; ++i)
            prev = prev->next;

        ListNode *temp;
        ListNode *cur = prev->next;

        for (int i = 0; i < right - left; ++i) {
            temp = cur->next;
            cur->next = temp->next;  // ligando ao final da sublista
            temp->next = prev->next; // head da stack
            prev->next = temp;       // novo head
        }

        return dummy->next;
    }
};
