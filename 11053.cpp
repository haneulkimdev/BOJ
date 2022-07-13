// http://boj.kr/65539609ebce4a86a75dc48ccfd8ec8c
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000], d[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    d[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) d[i] = max(d[i], d[j] + 1);
    }
  }
  cout << *max_element(d, d + n);
}