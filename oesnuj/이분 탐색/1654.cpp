#include <iostream>
#include <vector>
using namespace std;

bool check(vector <int>& v, int n, long long length);
int binary_serach(vector <int>& v, int n);

int main() {
    int k, n;
    cin >> k >> n;
    vector <int> v(k);
    for (auto& i : v) {
        cin >> i;
    }
    cout << binary_serach(v, n);
    return 0;
}

bool check(vector <int>& v, int n, long long length) {
    int cnt = 0;
    for (const auto& i : v) {
        cnt += i / length;
    }
    return cnt >= n;
}

int binary_serach(vector <int>& v, int n) {
    long long lo = 1, hi = 2147483648; //자를 수 있는 랜선의 범위
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(v, n, mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}
