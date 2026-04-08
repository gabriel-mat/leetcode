class Solution{
    public:
      bool isPalindrome(int x){
          int reversed_num = 0;

          if(x < 0 || x && x % 10 == 0)
              return false;

          while(reversed_num < x){
              reversed_num *= 10;
              reversed_num += x % 10;
              x /= 10;
            }
          
          return (x == reversed_num || x == reversed_num / 10);
        }
  }; 
