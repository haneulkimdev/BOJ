// http://boj.kr/275df22636be4458b7185e52874aed16
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, v;
  cin >> a >> b >> v;
  if ((v - b) % (a - b) == 0)
    cout << (v - b) / (a - b);
  else
    cout << (v - b) / (a - b) + 1;
}