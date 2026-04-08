class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        
        // O loop continua enquanto houver dígitos em qualquer uma das strings OU houver um carry sobrando
        while (i >= 0 || j >= 0 || carry > 0) {
            // Se o índice for < 0, significa que aquela string acabou, então tratamos o dígito como 0
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;          // Calcula o "vai um" (ex: 15 / 10 = 1)
            result += to_string(sum % 10); // Pega apenas a unidade (ex: 15 % 10 = 5)
            
            i--;
            j--;
        }
        
        // Como fomos anexando do fim para o começo, precisamos inverter a string no final
        reverse(result.begin(), result.end());
        
        return result;
    }
};
