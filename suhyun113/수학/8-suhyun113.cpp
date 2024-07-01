// 1004 : 어린 왕자

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T; // 테스트 케이스의 개수
    int x1, y1, x2, y2; // 출발점, 도착점
    int n; // 행성의 개수
    int cx, cy, r; // 행성계의 중점과 반지름
    
    cin >> T;
    while(T--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;

        int enter = 0; // 진입 횟수
        int departure = 0; // 이탈 횟수
        int count = 0; // 최종 진입/이탈 횟수

        while(n--) {
            cin >> cx >> cy >> r;
            float startDistance = sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)); // 출발점과 원 사이의 거리
            float endDistance = sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)); // 도착점과 원 사이의 거리

            if (startDistance < r){  // 출발점이 원 내부에 있고, 
                if (endDistance > r) { // 도착점이 원 외부에 있음
                    departure++; // 출발점 포함하는 행성 -> 이탈 횟수 증가
                }
            }
            if (startDistance > r) { // 출발점이 원 외부에 있고, 
                if (endDistance < r) { // 도착점이 원 내부에 있음
                    enter++; // 도착점 포함하는 행성 -> 진입 회수 증가
                }
            }
        }
        count = enter + departure; // 최종 진입/이탈 횟수
        cout << count << endl; 
    }
    return 0;
}