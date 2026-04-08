#include <vector>
#include <unordered_set>

using namespace std;

/*
    Mesma complexidade, mas é mais elegante
*/

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> seen;

        for (int n : nums) {
            if (seen.count(n))
                return true;

            seen.insert(n);
        }

        return false;
    }
};