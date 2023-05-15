// http://boj.kr/392d22e3dca14556b0d074f0611712ec
#include <bits/stdc++.h>
using namespace std;

int freq[26];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (auto c : s) freq[toupper(c) - 'A']++;
  int mx = 0;
  char ans = '?';
  for (int i = 0; i < 26; i++) {
    if (freq[i] > mx) {
      mx = freq[i];
      ans = i + 'A';
    } else if (mx == freq[i]) {
      ans = '?';
    }
  }
  cout << ans;
}