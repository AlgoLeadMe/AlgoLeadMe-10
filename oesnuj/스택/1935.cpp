#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    stack <double> s;

    int n;  
    cin >> n;
    string postfix;  
    cin >> postfix;
    double arr[26] = {0};
    for (int i = 0; i < n; i++) //알파벳에 해당하는 값 저장해놓기
        cin >> arr[i];

    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= 'A' && postfix[i] <= 'Z') //피연산자라면 해당 값 push
            s.push(arr[postfix[i] - 'A']);

        else //연산자를 만난다면 스택의 top 2개를 꺼내어 연산 수행후 해당 값 push
        {
            double op1 = s.top();
            s.pop();
            double op2 = s.top();
            s.pop();
            if (postfix[i] == '+')
                s.push(op2 + op1);
            else if (postfix[i] == '-')
                s.push(op2 - op1);
            else if (postfix[i] == '*')
                s.push(op2 * op1);
            else if (postfix[i] == '/')
                s.push(op2 / op1);
        }
    }
    cout << fixed << setprecision(2) << s.top(); //소수점 둘째짜리 까지 출력
    return 0;
}