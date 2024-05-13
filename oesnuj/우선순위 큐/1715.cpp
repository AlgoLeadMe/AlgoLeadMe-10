#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);

    priority_queue <int, vector<int>, greater<int>> pq; //최소 힙으로 우선순위 큐 선언 
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) //우선순위 큐에 다 넣음
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int result = 0;
    while(pq.size() > 1) //우선순위 큐에 값이 하나만 남을 때 까지 반복
    {
        // 우선순위 큐에서 가장 작은 두 수를 꺼내서 합침
        int a = pq.top();
        pq.pop();                                                                                   
        int b = pq.top();
        pq.pop();
        int sum = a + b; 
        pq.push(sum);  // 합친 결과를 우선순위 큐에 다시 넣음 
        
        result += sum;  // 결과값을 누적
    }
    cout << result;
    return 0;
}