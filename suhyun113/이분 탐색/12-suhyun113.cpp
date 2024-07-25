// 2805 : 나무 자르기

#include <iostream>
#include <vector>
using namespace std;

// 절단기에 지정한 나무의 높이 H로 나무를 자름
// H보다 크면 자르기(작으면, 값이 0 또는 음수로 나옴)
bool  can_cut(vector<int>& trees, int H, int M) {
	long long total = 0; // 자른 나무들의 총 합
	for (int tree : trees) {
		if (tree > H) {
			total += (tree - H);
		}
	}
	return total >= M; // 총 합이 M 보다는 커야 함
}

int binary_search(vector<int>& trees, int M) {
	int lo = 0;
	int hi = 1000000000;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2; // 중앙값 저장

		if (can_cut(trees, mid, M)) { // 절단기 높이 변경
			lo = mid; // 현재의 절단기 높이를 가능한 최소 높이로 저장(중앙값 더 커짐)
		}
		else {
			hi = mid; // 현재 절단기 높이 안되면, 더 낮은 높이로 확인
		}
	}

	return lo; // canCut을 만족해야 하므로
}

int main() {
	int N, M;
	cin >> N >> M;

	// N개의 나무들의 길이 목록 만들기
	vector<int> trees(N);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}

	int result = binary_search(trees, M);
	cout << result << endl;

	return 0;
}