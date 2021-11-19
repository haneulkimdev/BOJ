// http://boj.kr/43696cb5a9ff4e45a7824bf37ce0b653
#include <bits/stdc++.h>
using namespace std;

int freq[2][26];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s1, s2;
  cin >> s1 >> s2;
  for (auto c : s1) freq[0][c - 'a']++;
  for (auto c : s2) freq[1][c - 'a']++;
  int ans = 0;
  for (int i = 0; i < 26; i++) ans += abs(freq[0][i] - freq[1][i]);
  cout << ans;
}