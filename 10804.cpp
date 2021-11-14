// http://boj.kr/b71007a642ae4adb818a572ab8e33f42
#include <bits/stdc++.h>
using namespace std;

int card[21];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 20; i++) card[i] = i;
  for (int i = 0; i < 10; i++) {
    int a, b;
    cin >> a >> b;
    reverse(card + a, card + b + 1);
  }
  for (int i = 1; i <= 20; i++) cout << card[i] << ' ';
}