# 11047 : 동전 0

# 동전의 종류와 목표 금액을 입력받아 최소 동전 개수를 계산하는 함수
def min_coins(n, k, coins):
    count = 0  # 동전 개수를 세기 위한 변수
    for coin in reversed(coins):  # 동전의 종류를 큰 것부터 작은 것 순으로 탐색
        if k == 0:  # 목표 금액이 0이면 더 이상 동전을 사용할 필요 없음
            break
        count += k // coin  # 현재 동전으로 만들 수 있는 최대 개수 추가
        k %= coin  # 남은 금액 업데이트
    return count  # 최소 동전 개수 반환

# 입력 받기
n, k = map(int, input().split())  # 동전의 종류(n)와 목표 금액(k) 입력
coins = [int(input()) for _ in range(n)]  # 동전의 종류 입력

# 최소 동전 개수 계산 및 출력
result = min_coins(n, k, coins)
print(result)