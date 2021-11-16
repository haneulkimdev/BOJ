// http://boj.kr/ae37f5e87e3d4698ada69aad816cb5e4
#include <bits/stdc++.h>
using namespace std;

int freq[10];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int tot = a * b * c;
  while (tot > 0) {
    freq[tot % 10]++;
    tot /= 10;
  }
  for (int i = 0; i < 10; i++) cout << freq[i] << '\n';
}