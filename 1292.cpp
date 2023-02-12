// http://boj.kr/057630ffc5db46a48ad08a89c76ef7f1
#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int idx = 1;
  for (int i = 1; idx <= 1000; i++) {
    for (int j = 0; j < i; j++) {
      if (idx > 1000) break;
      arr[idx++] = i;
    }
  }
  int a, b;
  cin >> a >> b;
  int sum = 0;
  for (int i = a; i <= b; i++)
    sum += arr[i];
  cout << sum;
}