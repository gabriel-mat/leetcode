#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    int cap;
    list<pair<int, int>> lru_list; 
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        
        // Move o elemento para a frente da lista (LRU)
        // void splice( const_iterator pos, list& other, const_iterator it );
        lru_list.splice(lru_list.begin(), lru_list, m[key]);

        // ** m[key] is an iterator **
        
        return m[key]->second;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            lru_list.splice(lru_list.begin(), lru_list, m[key]);
            m[key]->second = value;
            return;
        }
        
        if (m.size() == cap) {
            int key_to_del = lru_list.back().first;
            m.erase(key_to_del);
            lru_list.pop_back();
        }
        
        lru_list.push_front({key, value});
        m[key] = lru_list.begin();
    }
};
