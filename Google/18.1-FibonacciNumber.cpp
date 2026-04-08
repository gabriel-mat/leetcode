/*
 * Interviewer: 
 * "Your implementation correctly applies memoization, 
 * and you've handled the n=0 edge case for the vector initialization with that if(n) check. 
 * The time complexity is indeed O(n) now.
 * However, I noticed that with this top-down approach, 
 * we are still using O(n) space for the vector plus the O(n) overhead for the recursive call stack.
 * In a system where memory is extremely tight—like an embedded controller—could we achieve 
 * the same O(n) time complexity but reduce the total space complexity to O(1)? 
 * How would you change your strategy to avoid using a vector or recursion entirely?" 
 */

class Solution{
    public:

    int fib(int n){

        int fibonacci = n;

        for(int n1 = 0, n2 = 1, i = 2; i <= n; i++){
            fibonacci = n1 + n2;
            n1 = n2;
            n2 = fibonacci;
          }

        return fibonacci;
      }
  };
