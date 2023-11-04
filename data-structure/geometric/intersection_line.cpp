#include <iostream>
using namespace std;

struct point {
  int x; // x 좌표
  int y; // y 좌표
} FirstPoint, SecondPoint;

struct line {
  struct point pt1;
  struct point pt2;
} TestLine; // 선분

/*
세 점의 상대 위치를 결정하는 알고리즘 (Direction)

(1) 점 A, B, C가 일직선 상에 있지 않을 때, 꺾은선 ABC의 방향이
    - 시계 방향인 경우: 1
    - 시계 반대 방향인 경우: -1
(2) 점 A, B, C가 일직선 상에 있을 때
    - C가 가운데 있거나 C=A, C=B 인 경우: 0
    - B가 가운데 있는 경우: 1
    - A가 가운데 있는 경우: -1
*/
int Direction (struct point A, struct point B, struct point C) {
  int Dir; // 출력 값
  int dxAB, dxAC, dyAB, dyAC; // 기울기

  dxAB = B.x - A.x;
  dyAB = B.y - A.y;
  dyAC = C.x - A.x;
  dyAC = C.y - A.y;

  // (1) 점 A, B, C가 일직선 상에 있지 않은 경우
  if (dxAB * dyAC < dyAB * dxAC) Dir = 1; // 시계 방향
  if (dxAB * dyAC > dyAB * dxAC) Dir = -1; // 시계 반대 방향

  // (2) 점 A, B, C가 일직선 상에 있는 경우
  if (dxAB * dyAC == dyAB * dxAC) {
    if (dxAB == 0 && dyAB ==0) Dir = 0; 

    if ((dxAB * dxAC < 0) || (dyAB * dyAC < 0)) Dir = -1; // A가 가운데 있는 경우
    // C가 가운데 있거나 C=A, C=B인 경우 (|AB| >= |AC|)
    else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) Dir = 0;
    else Dir = 1; // B가 가운데 있는 경우
  }
  return Dir;
}

/*
두 선분의 교차 알고리즘 (Intersection)

(1) Direction(A, B, C) * Direction(A, B, D) <= 0
(2) Direction(C, D, A) * Direction(C, D, B) <= 0

위의 (1), (2) 조건을 모두 만족하는 경우, 두 선분이 교차
*/
int Intersection(struct line AB, struct line CD) {
  int LineCrossing;

  if ((Direction(AB.pt1, AB.pt2, CD.pt1) * Direction(AB.pt1, AB.pt2, CD.pt2) <= 0) &&
      (Direction(CD.pt1, CD.pt2, AB.pt1) * Direction(CD.pt1, CD.pt2, AB.pt2) <= 0)) {
    LineCrossing = true;
  }
  else {
    LineCrossing = false;
  }

  return LineCrossing;
}

int main() {
  line AB = {{0, 0}, {5, 5}};
  line CD = {{0, 5}, {5, 0}};

  if (Intersection(AB, CD)) cout << "intersection" << endl;
  else cout << "not interesction" << endl;

  return 0;
}