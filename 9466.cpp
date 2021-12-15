// http://boj.kr/68d832c911054e26ac0c314540b8327e
#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int state[100001];
int n;

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x) {
  int cur = x;
  while (true) {
    state[cur] = x;
    cur = arr[cur];
    if (state[cur] == x) {
      while (state[cur] != CYCLE_IN) {
        state[cur] = CYCLE_IN;
        cur = arr[cur];
      }
      return;
    } else if (state[cur] != 0) {
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    fill(state + 1, state + n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++)
      if (state[i] == NOT_VISITED) run(i);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (state[i] != CYCLE_IN) cnt++;
    cout << cnt << '\n';
  }
}