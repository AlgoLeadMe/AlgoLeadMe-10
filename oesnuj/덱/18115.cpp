#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	deque <int> d;
	vector <int > v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {       //규칙 저장하기 : 사용한 순서대로 vector에 넣음
		int num;
		cin >> num;
		v.push_back(num);
	}
	vector<int>::reverse_iterator rit = v.rbegin(); //복원시 가장 마지막에 사용한 규칙부터 사용해야하기에 역반복자 사용

	int card = 1; //다 내려놓은 이후 현재 제일 위의 카드는 1
	for (rit; rit != v.rend(); rit++) {
		//규칙 1은 제일 위 카드 1장 바닥에 내려놓기이므로 복원시에는 덱의 가장 위로 옮긴다.
		if (*rit == 1) 
			d.push_back(card);


		// 규칙 2는 위에 두번째 카드 바닥에 내려놓기이므로 복원시에는 덱의 위에서 두번째로 옮긴다.
		else if (*rit == 2)
		{
			int temp = d.back(); //가장 위의 숫자는 잠깐 빼고
			d.pop_back();
			d.push_back(card); //넣어야할 카드 넣고
			d.push_back(temp); //빼두었던 가장 위의 숫자 다시 넣기
		}

		//규칙 3은 제일 밑의 카드를 바닥으로 내려놓기이므로 복원시에는 덱의 제일 밑으로 옮긴다.
		else if (*rit == 3)
			d.push_front(card);
		
		card++; //다음카드를 복원시켜야함(다음카드는 하나 큰 숫자임)
	}

	reverse(d.begin(), d.end()); //덱의 요소를 뒤(위)에서 부터 출력해야해 뒤집는다.
	for (auto &k : d) {      //출력
		cout << k << " ";
	}
	return 0;
}