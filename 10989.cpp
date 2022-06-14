// http://boj.kr/96452834380f481bb6fabd4908ab18ab
#include <bits/stdc++.h>
using namespace std;

int freq[10001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    freq[a]++;
  }
  for (int i = 1; i <= 10000; i++) {
    while (freq[i]--) {
      cout << i << '\n';
    }
  }
}