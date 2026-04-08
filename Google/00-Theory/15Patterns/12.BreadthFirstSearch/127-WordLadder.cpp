// Não parece ter otimizações significativas,
// a solução é feia mesmo
// O(M^2 * N), where M is size of dequeued word & N is size of our word list


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (!set.contains(endWord)) return 0;

        queue<string> queue({beginWord});
        unordered_set<string> visited = {beginWord};

        int changes = 1;

        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                string word = queue.front(); queue.pop();

                if (word == endWord) return changes;

                for (int j = 0; j < word.length(); j++) {
                    for (char k = 'a'; k <= 'z'; k++) {
                        string nS = word;
                        nS[j] = k;

                        if (set.contains(nS) && !visited.contains(nS)){
                            queue.push(nS); 
                            visited.insert(nS);
                        }
                    }
                }
            }

            ++changes;
        }

        return 0;
    }
};


// Algumas otimizações:
// 1. evitar novas strings
// 2. remover as palavras já vistas

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if (!dict.contains(endWord)) return 0;

        queue<string> q({beginWord});
        dict.erase(beginWord); 

        int changes = 1;

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string word = q.front(); q.pop();

                if (word == endWord) return changes;

                for (int j = 0; j < word.length(); j++) {
                    char originalChar = word[j];
                    
                    for (char k = 'a'; k <= 'z'; k++) {
                        if (k == originalChar) continue;
                        
                        word[j] = k;
                        if (dict.contains(word))
                            q.push(word); dict.erase(word);
                    }

                    word[j] = originalChar; 
                }
            }

            ++changes;
        }

        return 0;
    }
};
