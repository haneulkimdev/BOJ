// http://boj.kr/fb7af60bf4134088bb6402c9d352ea7a
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    int x;
    cin >> x;
    cnt += is_prime(x);
  }
  cout << cnt;
}