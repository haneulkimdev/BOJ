// http://boj.kr/de90738d3c4c48ca9e8f7d70a5969f69
#include <bits/stdc++.h>
using namespace std;

int freq[201];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, v;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    freq[t + 100]++;
  }
  cin >> v;
  cout << freq[v + 100];
}