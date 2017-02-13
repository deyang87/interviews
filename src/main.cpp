#include <iostream>
#include "WordLadder.h"

int main()
{
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    auto res = interviews::wordladder2::findLadders("hit", "cog", wordList);
    for (const auto& path: res) {
       std::cout << "[ ";
       for(const auto& str: path) {
           std::cout << str << " ";
       }
       std::cout << "]" << std::endl;
    }
}