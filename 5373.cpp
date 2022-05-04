// http://boj.kr/4eb30e04261142929771b243c977599f
#include <bits/stdc++.h>
using namespace std;

char cube[6][3][3];

const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;

void rotate(int face, bool is_clockwise) {
  int dir = 1;
  if (!is_clockwise) dir = 3;
  while (dir--) {
    char tmp[3][3];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) tmp[i][j] = cube[face][i][j];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) cube[face][i][j] = tmp[2 - j][i];
  }
}

void rotate_face(int face, bool is_clockwise) {
  rotate(face, is_clockwise);
  int dir = 1;
  if (!is_clockwise) dir = 3;
  while (dir--) {
    if (face == UP) {
      for (int i = 0; i < 3; i++) {
        int tmp = cube[FRONT][0][i];
        cube[FRONT][0][i] = cube[RIGHT][0][i];
        cube[RIGHT][0][i] = cube[BACK][2][2 - i];
        cube[BACK][2][2 - i] = cube[LEFT][0][i];
        cube[LEFT][0][i] = tmp;
      }
    } else if (face == DOWN) {
      for (int i = 0; i < 3; i++) {
        int tmp = cube[FRONT][2][i];
        cube[FRONT][2][i] = cube[LEFT][2][i];
        cube[LEFT][2][i] = cube[BACK][0][2 - i];
        cube[BACK][0][2 - i] = cube[RIGHT][2][i];
        cube[RIGHT][2][i] = tmp;
      }
    } else if (face == FRONT) {
      for (int i = 0; i < 3; i++) {
        int tmp = cube[UP][2][i];
        cube[UP][2][i] = cube[LEFT][2 - i][2];
        cube[LEFT][2 - i][2] = cube[DOWN][0][2 - i];
        cube[DOWN][0][2 - i] = cube[RIGHT][i][0];
        cube[RIGHT][i][0] = tmp;
      }
    } else if (face == BACK) {
      for (int i = 0; i < 3; i++) {
        int tmp = cube[UP][0][i];
        cube[UP][0][i] = cube[RIGHT][i][2];
        cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
        cube[DOWN][2][2 - i] = cube[LEFT][2 - i][0];
        cube[LEFT][2 - i][0] = tmp;
      }
    } else if (face == LEFT) {
      for (int i = 0; i < 3; i++) {
        int tmp = cube[UP][i][0];
        cube[UP][i][0] = cube[BACK][i][0];
        cube[BACK][i][0] = cube[DOWN][i][0];
        cube[DOWN][i][0] = cube[FRONT][i][0];
        cube[FRONT][i][0] = tmp;
      }
    } else if (face == RIGHT) {
      for (int i = 0; i < 3; i++) {
        int tmp = cube[UP][i][2];
        cube[UP][i][2] = cube[FRONT][i][2];
        cube[FRONT][i][2] = cube[DOWN][i][2];
        cube[DOWN][i][2] = cube[BACK][i][2];
        cube[BACK][i][2] = tmp;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string color = "wyrogb";
    for (int face = 0; face < 6; face++)
      for (int i = 0; i < 3; i++)
        fill(cube[face][i], cube[face][i] + 3, color[face]);
    int n;
    cin >> n;
    while (n--) {
      string rot;
      cin >> rot;
      if (rot[0] == 'U') rotate_face(UP, rot[1] == '+');
      if (rot[0] == 'D') rotate_face(DOWN, rot[1] == '+');
      if (rot[0] == 'F') rotate_face(FRONT, rot[1] == '+');
      if (rot[0] == 'B') rotate_face(BACK, rot[1] == '+');
      if (rot[0] == 'L') rotate_face(LEFT, rot[1] == '+');
      if (rot[0] == 'R') rotate_face(RIGHT, rot[1] == '+');
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) cout << cube[UP][i][j];
      cout << '\n';
    }
  }
}