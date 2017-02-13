#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

namespace interviews {
namespace wordladder2 {
struct Node {
public:
  std::string str;
  std::shared_ptr<Node> parent;
  Node(const std::string &s, const std::shared_ptr<Node> p = nullptr)
      : str(std::move(s)), parent(p) {}
};

bool canTransfer(const std::string &a, const std::string b) {
  if (a.length() != b.length()) {
    return false;
  }
  uint16_t distance = 0;
  for (size_t i = 0; i < a.length(); ++i) {
    if (a[i] != b[i]) {
      ++distance;
    }
  }
  return distance == 1;
}

void backPropogate(std::shared_ptr<Node> node, std::vector<std::string> &path) {
  if (!node->parent) {
    path.push_back(node->str);
    return;
  }
  backPropogate(node->parent, path);
  path.push_back(node->str);
}

std::vector<std::vector<std::string>>
findLadders(std::string beginWord, std::string endWord,
            std::vector<std::string> &wordList) {
  std::vector<std::vector<std::string>> results;
  std::deque<std::shared_ptr<Node>> leaves;
  std::unordered_set<std::string> visited;
  leaves.push_back(std::make_shared<Node>(beginWord));
  leaves.push_back(std::make_shared<Node>(""));
  visited.insert(beginWord);
  std::vector<std::string> iterated;

  while (!leaves.empty()) {
    auto current = leaves.front();
    if (current->str.empty()) {
      if (!results.empty()) {
        return results;
      }
      leaves.pop_front();
      if (leaves.empty()) {
        break;
      }
      leaves.push_back(current);
      for(const auto& s : iterated) {
        visited.insert(s);
      }
      iterated.clear();
      continue;
    }
    for (const auto &str : wordList) {
      if (canTransfer(str, current->str) && visited.find(str) == visited.end()) {
        if (str == endWord) {
          std::vector<std::string> path;
          backPropogate(std::make_shared<Node>(str,current), path);
          results.push_back(std::move(path));
          break;
        }
        leaves.push_back(std::make_shared<Node>(str, current));
        iterated.push_back(str);
      }
    }
    leaves.pop_front();
  }
  return results;
}
}
}