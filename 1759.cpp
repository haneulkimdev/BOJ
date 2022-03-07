// http://boj.kr/041d65c4a92a4e088743a91825473b61
#include <bits/stdc++.h>
using namespace std;

int l, c;
char s[15];

bool is_vowel(char x) {
  return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> c;
  for (int i = 0; i < c; i++) cin >> s[i];
  sort(s, s + c);
  vector<bool> brute(c);
  for (int i = l; i < c; i++) brute[i] = 1;
  do {
    string ans;
    int cnt = 0;
    for (int i = 0; i < c; i++) {
      if (brute[i] == 0) {
        ans += s[i];
        if (is_vowel(s[i])) cnt++;
      }
    }
    if (cnt < 1 || l - cnt < 2) continue;
    cout << ans << '\n';
  } while (next_permutation(brute.begin(), brute.end()));
}