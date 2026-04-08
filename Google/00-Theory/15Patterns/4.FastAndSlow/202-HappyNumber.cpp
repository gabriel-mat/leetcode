class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;

        if(calc(slow) == 1) return true; // fast poderia ter sido inicializado com calc(n)

        while(fast != 1){
            slow = calc(slow);
            fast = calc(calc(fast));

            if(slow == fast) return false;
        }

        return true;
    }

    inline int calc(int n){
        int sum = 0;
        
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }
};
