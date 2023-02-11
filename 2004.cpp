// http://boj.kr/f709dae0cb1f4141ab5caf78daa89b5e
#include <bits/stdc++.h>
using namespace std;

int amount2(int a) {  // a!의 2의 개수
  int val = a;
  int cnt = 0;
  while (val > 0) {
    val /= 2;
    cnt += val;
  }
  return cnt;
}

int amount5(int a) {  // a!의 5의 개수
  int val = a;
  int cnt = 0;
  while (val > 0) {
    val /= 5;
    cnt += val;
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int num2 = amount2(n) - amount2(m) - amount2(n - m);
  int num5 = amount5(n) - amount5(m) - amount5(n - m);
  cout << min(num2, num5);
}

/*
nCm = n! / m! * (n - m)!
*/