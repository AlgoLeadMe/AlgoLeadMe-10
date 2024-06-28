#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

int calcDistance(Point a, Point b)
{
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

bool compareInfo(Point &a, Point &b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        vector <Point> v(4);
        for (int i = 0; i < 4; i++) {
            cin >> v[i].x >> v[i].y;
        }
        sort(v.begin(), v.end(),compareInfo);
        //2 3
        //0 1
        int s1 = calcDistance(v[0], v[1]); //선분
        int s2 = calcDistance(v[0], v[2]);
        int s3 = calcDistance(v[1], v[3]);
        int s4 = calcDistance(v[2], v[3]);

        int dia1 = calcDistance(v[0], v[3]); //대각선
        int dia2 = calcDistance(v[1], v[2]);
        if (s1 == s2 && s2 == s3 && s3 == s4 && dia1 == dia2) //네변의 길이가 같고 대각선의 길이가 같다.
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}