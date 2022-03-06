// http://boj.kr/600bfa4f668744b0a1978139f79acb23
#include <bits/stdc++.h>
using namespace std;

int k;
int s[12];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    cin >> k;
    if (k == 0) break;
    for (int i = 0; i < k; i++) cin >> s[i];
    vector<bool> brute(k);
    for (int i = 6; i < k; i++) brute[i] = 1;
    do {
      for (int i = 0; i < k; i++)
        if (brute[i] == 0) cout << s[i] << ' ';
      cout << '\n';
    } while (next_permutation(brute.begin(), brute.end()));
    cout << '\n';
  }
}