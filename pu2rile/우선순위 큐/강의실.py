import heapq
import sys

n = int(sys.stdin.readline())

heap = []   # 모든 강의의 시작 시간과 종료 시간을 저장할 최소 힙
q = []  # 현재 사용 중인 강의실의 종료 시간을 저장할 최소 힙

# 주어진 강의 수만큼 반복하면서 강의 정보를 입력받아 최소 힙에 저장
for _ in range(n):
    num, start, end = map(int, sys.stdin.readline().split())
    heapq.heappush(heap, [start, end, num])

# 첫 번째 강의를 최소 힙에서 꺼내서 해당 강의의 종료 시간을 다른 힙에 저장
start, end, num = heapq.heappop(heap)
heapq.heappush(q, end)

while heap:
    start, end, num = heapq.heappop(heap)
    # 가장 빨리 끝나는 강의실의 종료 시간이 현재 강의의 시작 시간보다 작거나 같으면 종료 시간을 최소 힙에서 제거
    if q[0] <= start:
        heapq.heappop(q)
    heapq.heappush(q, end)  # 현재 강의의 종료 시간을 최소 힙에 추가

print(len(q))   # 최소 힙 q의 크기가 필요한 강의실의 수
