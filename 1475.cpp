// http://boj.kr/a05bcfd4941a460986c4959a35d448f2
#include <bits/stdc++.h>
using namespace std;

int freq[10];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n > 0) {
    freq[n % 10]++;
    n /= 10;
  }
  int ans = 1;
  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) continue;
    ans = max(ans, freq[i]);
  }
  ans = max(ans, (freq[6] + freq[9] + 1) / 2);
  cout << ans;
}