// http://boj.kr/3a16287a10ce4d908c821678b1596600
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
  }
  for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}