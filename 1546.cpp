// http://boj.kr/44878b000fa64b9398ffae8e1605fd23
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int mx = *max_element(a, a + n);
  double sum = 0;
  for (int i = 0; i < n; i++) sum += (double)a[i] / mx * 100;
  cout << sum / n;
}