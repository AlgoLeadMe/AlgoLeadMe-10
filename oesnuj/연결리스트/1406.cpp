#include <iostream>
#include <list>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    list <char> li; //양방향 연결리스트 선언
    string str;
    cin >> str;
    for (auto c : str) //한 문자씩 연결리스트에 넣기
        li.push_back(c);

    list<char>::iterator cursor = li.end();
    int t;
    cin >> t;
    while(t--)
    {
        char input;
        cin >> input;
        if (input == 'L')
        {
            if (cursor != li.begin())
                cursor--;
        }
        else if (input == 'D')
        {
            if (cursor != li.end())
                cursor++;
        }
        else if (input == 'B')
        {
            if (cursor != li.begin())
            {
                cursor--;
                cursor = li.erase(cursor);
            }   
        }
        else if (input == 'P')
        {
            char insertChar;
            cin >> insertChar;
            li.insert(cursor, insertChar);
        }
    }
    
    for (auto c : li)
        cout << c;
    return 0;
}
