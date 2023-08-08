// http://boj.kr/72624ba5de564ad2a942611e4565694a
#include <bits/stdc++.h>
using namespace std;

int n;
int x[1000000];
vector<int> uni;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    uni.push_back(x[i]);
  }
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  for (int i = 0; i < n; i++)
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
}