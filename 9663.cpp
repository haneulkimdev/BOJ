// http://boj.kr/7df41c6959e64e71b93bb6422ef53756
#include <bits/stdc++.h>
using namespace std;
bool is_used1[14];
bool is_used2[27];
bool is_used3[27];

int ans = 0;
int n;
void func(int cur) {
  if (cur == n) {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (is_used1[i] || is_used2[cur + i] || is_used3[cur - i + n - 1]) continue;
    is_used1[i] = 1;
    is_used2[cur + i] = 1;
    is_used3[cur - i + n - 1] = 1;
    func(cur + 1);
    is_used1[i] = 0;
    is_used2[cur + i] = 0;
    is_used3[cur - i + n - 1] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << ans;
}