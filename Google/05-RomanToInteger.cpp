/*For each char, I'd use a helper function with a switch statement to convert it to an int, 
which keeps the code clean. 
If the current value is smaller than the next one, 
I subtract it from the total. 
Otherwise, I add it to the total.
*/


class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0; // Blindagem contra o underflow do size_t

        int roman_integer = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            // Variáveis declaradas o mais perto possível de onde são usadas
            int current_val = romanCharToInt(s[i]);
            int next_val = romanCharToInt(s[i + 1]);

            if (current_val < next_val) {
                roman_integer -= current_val;
            } else {
                roman_integer += current_val;
            }
        }

        roman_integer += romanCharToInt(s[n - 1]);

        return roman_integer;
    }

private:
    int romanCharToInt(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};              return 50;

              case 'C':
              return 100;

              case 'D':
              return 500;

              case 'M':
              return 1000;

              default:
              return 0;
            }
        }
  };
