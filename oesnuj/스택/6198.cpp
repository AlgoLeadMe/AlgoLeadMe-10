#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n; //빌딩 개수 입력

	vector <int> v(n);  //빌딩 높이를 받을 벡터 선언
	vector <int> s;     //빌딩 높이들을 적절하게 넣을 스택 선언
	for (auto& i : v)
		cin >> i;   //각 빌딩 높이 입력

	long long int count = 0;  //count가 int형을 넘어서기에 long long int type으로 둠
	for (const auto& height : v) // 모든 빌딩 높이를 하나씩 순회한다.
	{
		while (true)
		{
			if (s.empty()) //스택이 비었다면 현재 빌딩 높이 스택에 push
			{
				s.push_back(height);
				break;
			}
			if (height < s.back()) //현재 빌딩 높이가 스택의 top보다 높은 빌딩이라면(볼 수 있는 빌딩이라면)
			{
				count += s.size();
				//스택에는 현재 빌딩보다 높은 빌딩 밖에 없으니 스택의 크기 = 현재 빌딩을 볼 수 있는 빌딩 수
				s.push_back(height);
				break;
			}
			s.pop_back(); //현재 빌딩이 스택의 top보다 높다면(어짜피 나를 볼 수 없는 빌딩이니) 전부 pop
			//스택이 비거나 현재 빌딩보다 높은 top이 나올때까지 pop한다.
			// 언제까지 pop 할까?
			//case 1. 스택이 비면 나를 볼 수 있는 빌딩은 없다는 뜻이니 스택에 push
			//case 2. 나보다 높은 빌딩이 나온다면 그때 스택의 크기 = 나를 볼 수 있는 빌딩 수 를 count에 추가
		}
	}
	cout << count;
	return 0;
}