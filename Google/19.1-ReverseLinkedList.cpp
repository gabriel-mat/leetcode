/* 
 * From recursive to iterative approach
 * we maintain the time complexity as O(N)
 * but brings down the space complexity to O(1)
 */

class Solution{
    public:
      ListNode* reverseList(ListNode* head){
          if(head == nullptr || head->next == nullptr) return head;
          
          ListNode *prev, *curr, *next;

          prev = nullptr;
          curr = head;

          while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
          }

          return prev;
        }
  };
