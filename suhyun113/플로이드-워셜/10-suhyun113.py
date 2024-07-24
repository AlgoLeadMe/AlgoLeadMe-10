# 11404 : 플로이드
import sys

input = sys.stdin.readline
INF = float('inf') # 최대값 정의

# 노드의 개수(n)과 간선의 개수(m) 입력
n = int(input()) # 도시의 개수 n
m = int(input()) # 버스의 개수 m

# 2차원 리스트 (그래프 표현) 만들고, 무한대로 초기화(플로이드-워셜 = 이차원 배열)
graph = [[INF] * (n + 1) for _ in range(n + 1)]

# i에서 j로 갈 수 없는 경우, 
# 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화(대각선에 해당하는 부분))
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            graph[i][j] = 0

# 각 간선에 대한 정보를 입력받아, 그 값으로 초기화
for _ in range(m):
    # A -> B로 가는 비용을 C라고 설정
    i, j, cost = map(int, input().split())
    if graph[i][j] > cost: # 시작 도시와 도착 도시 연결하는 노선 하나가 x
        graph[i][j] = cost

# 점화식에 따라 플로이드 워셜 알고리즘을 수행(3중 for문)
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

# 수행된 결과를 출력
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if graph[i][j] == INF:
            print(0, end=' ')
        else:
            print(graph[i][j], end=' ')
    print()