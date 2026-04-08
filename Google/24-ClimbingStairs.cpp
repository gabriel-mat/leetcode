class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;

        int fib;
        for(int num1 = 1, num2 = 2, i = 3; i <= n; i++){
            fib = num1 + num2;
            num1 = num2;
            num2 = fib;
        }

        return fib;
    }
};
