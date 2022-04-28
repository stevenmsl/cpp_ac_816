
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;
namespace sol816
{

  class Solution
  {
  private:
    vector<string> permutate(const string &s);

  public:
    vector<string> generate(const string &s);
  };
}
#endif