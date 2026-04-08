// Solução mais simples
// O(N^2)

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int dp[nums.size()];
        int maxL = 1, maxP;
        
        for(int i = 0; i < nums.size(); ++i){
            dp[i] = 1;
            maxP = 0;

            for(int j = i - 1; j >= 0; --j)
                if(nums[j] < nums[i]) maxP = max(dp[j], maxP);

            dp[i] = maxP + 1;
            maxL = max(dp[i], maxL);
        }

        return maxL;
    }
};

// Solução ideal
// O(N * log(N))
// usando bsearch

// note que há sequências inválidas no processo, mas elas só servem para guardar
// o número máximo e possibilitar novas sequências
// as sequências podem ser inválidas, mas o tamanho é o que importa

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> sub;
        
        for (int x : nums) {
            // Se sub estiver vazio ou x for maior que o último elemento
            if (sub.empty() || x > sub.back())
                sub.push_back(x);
            else {
                // BSearch retornando um iterador para o primeiro elemento >= x
                auto it = lower_bound(sub.begin(), sub.end(), x);
                *it = x;
            }
        }
        
        return sub.size();
    }
};

// Um follow-up: retornar a sequência:

class Solution {
public:
    vector<int> longestIncreasingSubsequence(const vector<int> &nums) {
        if (nums.empty()) return {};

        // Em vez de guardar os valores, guarda os ÍNDICES do array 'nums'
        vector<int> indices_sub; 
        
        // Array para congelar no tempo quem era o elemento anterior (o pai)
        // Inicializamos tudo com -1 (que significa "não tem pai")
        vector<int> pais(nums.size(), -1);

        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];

            // Pesquisa binária manual (já que estamos a procurar índices, mas a comparar valores)
            int esquerda = 0;
            int direita = indices_sub.size() - 1;
            int posicao_insercao = indices_sub.size(); // Por defeito, vai para o fim

            while (esquerda <= direita) {
                int meio = esquerda + (direita - esquerda) / 2;

                if (nums[indices_sub[meio]] >= x) {
                    posicao_insercao = meio;
                    direita = meio - 1;
                } else {
                    esquerda = meio + 1;
                }
            }

            // O TRUQUE MÁGICO: Congelar a história!
            // Se não estamos a colocar o número na primeira posição (índice 0 do sub),
            // significa que ele está a formar uma sequência com o número que está à sua esquerda.
            if (posicao_insercao > 0)
                pais[i] = indices_sub[posicao_insercao - 1];

            // Atualiza o vetor da pesquisa binária com o índice do novo número
            if (posicao_insercao == indices_sub.size())
                indices_sub.push_back(i);
            else
                indices_sub[posicao_insercao] = i;
        }

        // --- RECONSTRUÇÃO DA SEQUÊNCIA (Backtracking) ---
        
        std::vector<int> lis_real;
        
        // Começamos pelo índice do último elemento da maior sequência encontrada
        int atual = indices_sub.back(); 

        // Puxamos o fio de Ariadne até chegarmos ao início (-1)
        while (atual != -1) {
            lis_real.push_back(nums[atual]);
            atual = pais[atual]; // Saltamos para o pai
        }

        // Como andámos de trás para a frente, a sequência está invertida.
        // Basta virar do avesso para ter a resposta final!
        std::reverse(lis_real.begin(), lis_real.end());

        return lis_real;
    }
};
