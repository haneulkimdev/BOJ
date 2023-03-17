// http://boj.kr/a5aa6721d8dd4c44bae53b37a3a2c4b2
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100000];
vector<bool> state(100001);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long cnt = 0;
  state[a[0]] = true;
  int en = 0;
  for (int st = 0; st < n; st++) {
    while (en < n - 1 && !state[a[en + 1]]) {
      en++;
      state[a[en]] = true;
    }
    cnt += en - st + 1;
    state[a[st]] = false;
  }
  cout << cnt;
}