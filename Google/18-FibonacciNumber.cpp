/*
 * Brute force approach: O(2^N) in time
 * Memoization approach: O(N) in time
*/

class Solution{
    public:
      int fib(int n){
          vector<int> memoization(n + 1, -1);
          
          if(n)
            memoization[1] = 1;
          memoization[0] = 0;

          return rec_fib(n, memoization);
        }

    private:
      int rec_fib(int n, vector<int> &memoization){
          if(memoization[n] != -1)
            return memoization[n];

          return (memoization[n] = rec_fib(n - 1, memoization) + rec_fib(n - 2, memoization));
        }
  };
