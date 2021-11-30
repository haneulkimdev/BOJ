// http://boj.kr/1ef1841ff299473c9886086c22c94c96
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    string a;
    getline(cin, a);
    if (a == ".") break;
    stack<char> s;
    bool is_valid = true;
    for (auto c : a) {
      if (c == '(' || c == '[') {
        s.push(c);
      } else if (c == ')') {
        if (s.empty() || s.top() != '(') {
          is_valid = false;
          break;
        }
        s.pop();
      } else if (c == ']') {
        if (s.empty() || s.top() != '[') {
          is_valid = false;
          break;
        }
        s.pop();
      }
    }
    if (!s.empty()) is_valid = false;
    if (is_valid)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}