//14502 : 연구소

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 메크로 설정
#define BLANK 0
#define WALL 1
#define VIRUS 2

int N, M; // 지도의 세로 크기, 가로 크기
vector<vector<int>> initial_map; // 초기 지도
vector<pair<int, int>> blank_map; // 빈 칸
int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 방향

// 가능한 모든 벽 세우기 조합 구하기
vector<vector<pair<int, int>>> building_walls() {
	vector<vector<pair<int, int>>> combinations;
	int size = blank_map.size(); // 빈 칸 크기
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				// 빈 칸에 벽 3개 세우기
				combinations.push_back({blank_map[i], blank_map[j], blank_map[k]});
			}
		}
	}
	return combinations;
}

// 너비 우선 탐색(바이러스인 칸 큐에 저장 후, 
// 바이러스 칸 주변 칸이 바이러스 아닌 빈 칸이라면,
// 주변 칸을 바이러스로 바꾸기)
void bfs(vector<vector<int>>& map_copy) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map_copy[i][j] == VIRUS) {
				q.push({i, j});
			}
		}
	}
	// 바이러스인 칸이 아니고 빈 칸이라면,
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) { // 방향 탐색
			int nx = x + directions[d][0];
			int ny = y + directions[d][1];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map_copy[nx][ny] == 0) {
				map_copy[nx][ny] = VIRUS; // 빈 칸을 바이러스로 바꾸기
				q.push({nx, ny});
			}
		}
	}
}

// 안전 영역 크기 계산 함수
int calculate_safe_area(vector<vector<int>>& map_copy) {
	int safe_area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map_copy[i][j] == BLANK) { // 빈 칸의 개수
				safe_area++;
			}
		}
	}
	return safe_area;
}

int main() {
	cin >> N >> M;
	initial_map.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> initial_map[i][j];
			if (initial_map[i][j] == BLANK) {
				blank_map.push_back({ i, j }); // 빈 칸 지도 생성
			}
		}
	}

	vector<vector<pair<int, int>>> wall_combinations = building_walls(); // 빈 칸에 벽 세우기
	int max_safe_area = 0; // 안전 영역의 최대 크기

	for (const auto& walls : wall_combinations) { // 벽 3개를 세운 여러 조합 반복
		// 초기 맵 복사해서 그 맵에 벽 3개 세우는 여러 조합 중 한 경우 적용
		vector<vector<int>> map_copy = initial_map;
		for (const auto& wall : walls) { // 한 경우에서 세운 벽 3개의 각각 위치에 벽 세우기
			map_copy[wall.first][wall.second] = WALL; // 벽 세우기
		}

		bfs(map_copy); // 바이러스 주변 칸 빈 칸이라면 바이러스 번짐

		int safe_area = calculate_safe_area(map_copy); // 안전영역 크기 계산
		max_safe_area = max(max_safe_area, safe_area);
	}

	cout << max_safe_area << endl;
	return 0;
}