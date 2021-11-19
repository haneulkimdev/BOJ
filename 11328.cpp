// http://boj.kr/c2f050d8b02541ecad215fbbbc4fd050
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int freq[26] = {};
    string s1, s2;
    cin >> s1 >> s2;
    for (auto c : s1) freq[c - 'a']++;
    for (auto c : s2) freq[c - 'a']--;
    bool is_possible = true;
    for (int i = 0; i < 26; i++) {
      if (freq[i] != 0) {
        is_possible = false;
        break;
      }
    }
    if (is_possible)
      cout << "Possible\n";
    else
      cout << "Impossible\n";
  }
}