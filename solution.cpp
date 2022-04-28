#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol816;
using namespace std;

/*takeaways
  - break the string into two parts one for generating the x coordinate
    the other for y coordinate
  - find all the possible valid numbers each part can generate and
    then pair up those numbers into the possible coordinates
*/

/* return all the possible valid numbers
   that this string can generate
*/
vector<string> Solution::permutate(const string &s)
{
  if (s.empty())
    return {};
  /*
    - the string itself is not a valid number as
      it will always has a leading 0
    - nor can you place a decimal point somewhere
      in the string to make it a valid decimal
      number as it will always has a trailing zero
  */
  if (s.size() >= 2 && s.front() == '0' && s.back() == '0')
    return {};

  /* s itself is valid number, but you can't
     produce any valid decimal number out of it
     - this also takes care of single '0' case
  */
  if (s.back() == '0')
    return {s};
  /*
    - the only valid number we can produce is 0.XXXX
  */
  if (s.front() == '0')
    return {"0." + s.substr(1)};

  /* s itself as a valid number */
  auto result = vector<string>{s};
  /* plus all the places you can put the decimal point in
     to create a valid decimal number
  */
  for (auto i = 1; i < s.size(); i++)
    result.push_back(s.substr(0, i) + '.' + s.substr(i));

  return result;
}

vector<string> Solution::generate(const string &s)
{
  /*extract the number out */
  const auto num = s.substr(1, s.size() - 2);
  auto result = vector<string>();
  for (auto i = 1; i < num.size(); i++)
    for (auto x : permutate(num.substr(0, i)))
      for (auto y : permutate(num.substr(i)))
        result.push_back('(' + x + ", " + y + ')');

  return result;
}