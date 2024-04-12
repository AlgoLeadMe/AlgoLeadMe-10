#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool binarySearch(vector <string> &v, string str) //이분탐색
{
    int left = 0;
    int right = v.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (str > v[middle])
            left = middle + 1;
        else if (str < v[middle])
            right = middle - 1;
        else
            return true;
    
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <string> v(n);    //듣도 못한 사람 입력
    for (auto& i : v){
        cin >> i;
    }
    sort(v.begin(), v.end()); //이분 탐색을 위해 정렬
    vector <string> result;
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word; //보도 못한 사람 입력
        if (binarySearch(v, word)){  //보도 못한 사람이 듣도 보다 못한 사람에도 포함되면
            result.push_back(word);
        }
    }
    sort(result.begin(), result.end()); //마지막 사전순 정렬을 위해 정렬

    cout << result.size() << "\n";
    for (const auto& word : result) {
        cout << word << "\n";
    }
    return 0;        
}