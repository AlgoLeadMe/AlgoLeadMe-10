import sys
sys.setrecursionlimit(10 ** 6)

n = int(sys.stdin.readline().strip())
# 트리에 저장
tree = [[] for _ in range (n+1)]
for _ in range(n-1):
    a,b = map(int, sys.stdin.readline().strip().split())
    tree[a].append(b)
    tree[b].append(a)

arr = [0] * (n + 1)
def dfs(cur, prv, dep):
    arr[cur] = dep  # cnt는 현재 노드(cur)까지의 거리를 arr 리스트의 cur 인덱스에 저장
    for next in tree[cur]:  # 현재 노드(cur)에 연결된 모든 자식 노드를 순회
        if next == prv: # 다음 노드(next)가 이전에 방문한 부모 노드(prv)라면
            continue    # 건너뛰기
        dfs(next,cur,dep+1)  # 재귀적으로 dfs 수행, cur이 next 노드의 부모가 되고, cnt + 1을 통해 현재 깊이를 1 증가

dfs(1, 0, 0)    # 트리 탐색 시작
cnt = 0
for i in range(2, n+1):
    # 리프 노드의 깊이 더하기
    if len(tree[i]) == 1:
        cnt += arr[i]

if cnt % 2 == 1:
    print("Yes")
else:
    print("No")