/*
 * Constraints:
 * 1 - The list can be empty!
 *
 */

class Solution{
    public:
      ListNode* reverseList(ListNode* head){
          if(head == nullptr) return nullptr;

          reverseList(head->next);

          ListNode *reversed = head;
          if(head->next != nullptr){
            head->next->next = head;
            head = head->next;
            reversed->next = nullptr;
          }

          return reversed;
        }
  };
