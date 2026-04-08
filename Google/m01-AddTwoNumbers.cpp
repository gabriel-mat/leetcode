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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      return addRecursive(l1, l2, 0);
    }

private:
    ListNode *addRecursive(ListNode *l1, ListNode *l2, int carry){
      if(l1 == nullptr && l2 == nullptr && !carry) return nullptr;
      
      int val1, val2, sum;

      val1 = l1 == nullptr ? 0 : l1->val;
      val2 = l2 == nullptr ? 0 : l2->val;
      sum = val1 + val2 + carry;

      ListNode *currentNode = new ListNode(sum % 10);
      ListNode *next1, *next2;

      next1 = l1 == nullptr ? nullptr : l1->next;
      next2 = l2 == nullptr ? nullptr : l2->next;
    
      currentNode->next = addRecursive(next1, next2, sum / 10);
      return currentNode;
    }
};
