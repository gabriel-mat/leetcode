// 
//  Não basta encontrar o ciclo, 
// é necessário encontrar o início
// ajustando um ponteiro extra (slow)
// no início e esperando o próximo encontro
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }

        int slow2 = nums[0];

        while (slow != slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};



//  Outra resolução: Cyclic Sort
// a ideia é a do problema dos pombos
// como temos N+1 inteiros para N posições,
// alguma posição terá 2 inteiros.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ){
            if(nums[nums[i]] == nums[i]) 
                return nums[i];

            swap(nums[i], nums[nums[i]]);
        }

        return 1;
    }
};
