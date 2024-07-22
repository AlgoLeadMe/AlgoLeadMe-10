# 1916 : 최소비용 구하기

import heapq

INF = float('inf') # 최대값 정의

N = int(input()) # 도시의 개수(노드)
M = int(input()) # 버스의 개수(에지)
 
graph = [[] for _ in range(N+1)] # 그래프 인접 리스트로 초기화(방문하지 않은 노드들)
distance = [INF] * (N+1) # 각 노드까지의 거리 무한대로 초기화

for _ in range(M):
    x, y, cost = map(int, input().split()) # x -> y 도시로 가는 데 필요한 비용 cost
    graph[x].append([y, cost]) # 그래프에 에지 추가

start, end = map(int, input().split()) # 출발, 도착 노드 입력 받기

# 다익스트라 알고리즘
def Dijkstra(start):
    q = [] # 우선순위 큐 생성
    heapq.heappush(q, [0, start]) # 출발할 도시 큐에 넣기([거리, 노드] 형태)
    distance[start] = 0 # 시작 도시의 거리 0으로 초기화

    while q: # 큐가 빌 때까지 반복
        weight, node = heapq.heappop(q) # 현재 노드까지의 거리, 현재 노드(큐에서 가장 작은 값)
        if distance[node] < weight: # 현재 노드가 이미 처리된 노드인지 확인
            continue
        for n, w in graph[node]:
            cost = w + weight # 현재 노드를 통해 인접 노드까지 가는 새로운 거리 계산
            if distance[n] > cost: # 새로운 거리가 기존에 저장된 거리보다 짧은지 확인
                distance[n] = cost # 최단 거리 갱신
                heapq.heappush(q, [cost, n]) # 인접 노드를 우선순위 큐에 추가

Dijkstra(start)
print(distance[end])