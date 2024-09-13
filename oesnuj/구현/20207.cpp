#include <iostream>
#include <vector>
using namespace std;

struct EventPeriod
{
    int start, end;
};

int main()
{
    int N;
    cin >> N;
    vector <EventPeriod> v(N);
    int days[365] = {0};

    for(int i = 0; i < N; i++)
    {
        cin >> v[i].start >> v[i].end; //일정 시작일, 종료일 입력받기

        for (int k = v[i].start - 1; k < v[i].end; k++) {
            days[k]++; //일정에 포함되는 날의 배열 값 +1;
        }
    }

    int result = 0;
    int height = 0, width = 0;
    for (int i = 0; i < 365; i++) {
        if (days[i] != 0) {
            width++;
            height = max(height, days[i]);
        }
        
        if (days[i + 1] == 0) {
            result += height * width;
            width = 0;
            height = 0;
        }
    }
    cout << result;
    return 0;
}