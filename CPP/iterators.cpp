#include <iostream>
#include <vector>
#include <unordered_map>

namespace util{
auto print = [](auto a){ std::cout << a << " "; };
auto endl = [](){ std::cout << std::endl; };
}

int main(){
    std::vector<int> values = {1, 2, 3};

    for(int v : values)
        util::print(v);
    util::endl();

    util::endl();

    for(std::vector<int>::iterator it = values.begin(); it != values.end(); ++it)
        util::print(*it);
    util::endl();

    using ScoreMap = std::unordered_map<std::string, int>;
    ScoreMap leaderboard;
    leaderboard["AAA"] = 1;
    leaderboard["BBB"] = 2;
    leaderboard["CCC"] = 3;

    util::endl();

    for(ScoreMap::const_iterator it = leaderboard.begin(); it != leaderboard.end(); ++it){
        auto &key = it->first;
        auto &value = it->second;

        util::print(key), util::print(value);
        util::endl();
    }

    util::endl();
    
    for(const auto& [key, value] : leaderboard) {
        util::print(key);
        util::print(value);
        util::endl();
    }

    return 0;
}