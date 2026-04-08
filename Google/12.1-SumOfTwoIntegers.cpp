/*
 *  Um possível follow-up para o 12-AddTwoIntegers
 *
 *  A ideia é dividir a soma em:
 *  1 - Soma sem carry
 *  2 - carry
 *
 *  E assim até o carry zerar
 *
 *  Essa solução é O(N) em tempo (limitado pela quantidade de bits de um int) e espaço
 */

class Solution {
public:
    int getSum(int a, int b) {
      while(b){
          int sum_wo_carry = a ^ b;
          unsigned carry = (unsigned)(a & b) << 1; // unsigned previne erro de shift
          
          a = sum_wo_carry;
          b = carry;
        }

      return a;
    }
};
