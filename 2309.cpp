// http://boj.kr/e67acbfaade5417fa633bc94a491ddbb
#include <bits/stdc++.h>
using namespace std;

int a[9];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 9; i++) cin >> a[i];
  sort(a, a + 9);
  do {
    int sum = 0;
    for (int i = 0; i < 7; i++) sum += a[i];
    if (sum == 100) {
      for (int i = 0; i < 7; i++) cout << a[i] << '\n';
      break;
    }
  } while (next_permutation(a, a + 9));
}