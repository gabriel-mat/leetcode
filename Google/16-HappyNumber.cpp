/*
 *
 * Problema de 2 pointers: fast & slow, hare-tortoise
 * Floyd's cycle detection (in linked lists)
 */

class Solution{
    public:
      bool isHappy(int n){
        int slow = n, fast = sumSquares(n);
        
        while(fast != 1 && slow != fast){
            slow = sumSquares(slow);
            fast = sumSquares(sumSquares(fast));
          }

        return fast == 1;
      }

    private:
      int sumSquares(int n){
          int sum = 0;

          while(n){
              sum += (n % 10) * (n % 10);
              n /= 10;
          }

          return sum;
      }
  };
