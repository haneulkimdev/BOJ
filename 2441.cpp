// http://boj.kr/2f336d526ce64b2b9d17d4af620afc72
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) cout << ' ';
    for (int j = 0; j < n - i; j++) cout << '*';
    cout << '\n';
  }
}