n = int(input())
nums = list(map(int, input().split()))

# dp 테이블 초기화
dp = [[0] * 21 for _ in range(n)] # 0 이상 20 이하인 숫자이므로 크기가 21인 배열

# 첫 번째 숫자를 dp 테이블에 초기값으로 설정
dp[0][nums[0]] = 1

# dp 테이블 채우기
for i in range(1, n - 1):
    for j in range(21):
        if dp[i - 1][j]:
            if j + nums[i] <= 20: # 더하기
                dp[i][j + nums[i]] += dp[i - 1][j]
            if j - nums[i] >= 0: # 빼기
                dp[i][j - nums[i]] += dp[i - 1][j]

# 마지막 숫자를 목표 값으로 만들 수 있는 경우의 수 출력
print(dp[n-2][nums[-1]])