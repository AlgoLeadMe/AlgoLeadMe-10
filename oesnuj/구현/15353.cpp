#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Add(string str1, string str2)
{
    string result = "";
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int num1 = 0, num2 = 0;
        if (i >= 0)
            num1 = str1[i--] - '0';
        if (j >= 0)
            num2 = str2[j--] - '0';

        int sum = num1 + num2 + carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;
    }
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << Add(a, b);
    return 0;
}