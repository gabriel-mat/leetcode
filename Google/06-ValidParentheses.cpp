/*
 * Edge cases:
 * 1- If the stack is empty, we cannot pop
 * 2- If the stack is not empty after the loop, s is invalid
 */

class Solution {
public:
    bool isValid(string s) {
      stack<char> brackets_stack;

      for(char c : s){
          if(c == '(' || c == '[' || c == '{'){
            brackets_stack.push(c);
            continue;
          }

          if(brackets_stack.empty() || !isMatch(c, brackets_stack))
            return false;

          brackets_stack.pop();
        }

      return brackets_stack.empty();
    }

private:
    bool isMatch(char c, stack<char> &stk){
        switch (c){
            case ')': return stk.top() == '(';
            case ']': return stk.top() == '[';
            case '}': return stk.top() == '{';
            default: return false;
          }
      }
};
