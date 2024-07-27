/*풀이1 재귀만 이용*/
//#include <iostream>
//using namespace std;
//
//int calc(int k, int n) {
//    if (k == 0) return n;
//    int sum = 0;
//    for (int i = n; i > 0; i--) {
//        sum += calc(k - 1, i);
//    }
//    return sum;
//}
//
//int main() 
//{
//    int T, k, n;
//    cin >> T;
//    while (T--) {
//        cin >> k >> n;
//        cout << calc(k, n) << "\n";
//    }
//    return 0;
//}

/*풀이2, 재귀 + DP*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

int calc(int k, int n) {
    if (k == 0) return n;
    if (dp[k][n] != -1) return dp[k][n]; // 이미 계산된 값이면 반환

    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += calc(k - 1, i);
    }
    return dp[k][n] = sum; // 계산된 값을 저장하고 반환
}

int main()
{
    int T, k, n;
    cin >> T;
    while (T--) {
        cin >> k >> n;
        dp = vector<vector<int>>(k + 1, vector<int>(n + 1, -1)); //케이스별 DP 테이블 초기화
        cout << calc(k, n) << "\n";
    }
    return 0;
}
