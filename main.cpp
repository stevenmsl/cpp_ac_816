#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol816;

/*
Example 1:
Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
*/

tuple<string, vector<string>>
testFixture1()
{
  auto input = "(123)";
  auto output = vector<string>{"(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"};
  return make_tuple(input, output);
}

/*
Example 2:
Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation:
0.0, 00, 0001 or 00.01 are not allowed.
*/
tuple<string, vector<string>>
testFixture2()
{
  auto input = "(00011)";
  auto output = vector<string>{"(0.001, 1)", "(0, 0.011)"};
  return make_tuple(input, output);
}

/*
Example 3:
Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
*/
tuple<string, vector<string>>
testFixture3()
{
  auto input = "(0123)";
  auto output = vector<string>{"(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"};
  return make_tuple(input, output);
}

/*
Example 4:
Input: "(100)"
Output: [(10, 0)]
Explanation:
1.0 is not allowed.
*/
tuple<string, vector<string>>
testFixture4()
{
  auto input = "(100)";
  auto output = vector<string>{"(10, 0)"};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.generate(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.generate(get<0>(f))) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.generate(get<0>(f))) << endl;
}

void test4()
{
  auto f = testFixture4();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.generate(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}