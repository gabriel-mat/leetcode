/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 *  Constraints:
 *  1 - Both lists have at least 1 node
 *  2 - Lists can be empty
 * */


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)  return list2;
        if(list2 == nullptr)  return list1;

        // esses ifs não são necessários, o dummy já lida com esse edge case

        ListNode dummyNode = ListNode();
        ListNode *p1, *p2, *tail = &dummyNode;

        p1 = list1;
        p2 = list2;

        while(p1 != nullptr && p2 != nullptr){

          if(p1->val < p2->val){
              tail->next = p1;
              p1 = p1->next;
          }
          else{
              tail->next = p2;
              p2 = p2->next;
          }

          tail = tail->next;
        }


        if(p1 != nullptr)
          tail->next = p1;
        else if(p2 != nullptr)
          tail->next = p2;

        return dummyNode.next;
    }
};
