// http://boj.kr/9b15d48812bc479b8c8803181991442f
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  unordered_set<string> substrings;
  for (int i = 0; i < s.size(); i++)
    for (int j = 1; j <= s.size() - i; j++) substrings.insert(s.substr(i, j));
  cout << substrings.size() << '\n';
}