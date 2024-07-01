# 2716 : 원숭이 매달기

N = int(input()) # 테스트 케이스의 개수 
results = []

for _ in range(N):
    s = input().strip()
    len_s = len(s)

    depth = 0
    max_depth = 0

    for i in range(len_s):
        if (s[i] == '['):
            depth += 1
            if (depth > max_depth):
                max_depth = depth
        elif (s[i] == ']'):
            depth -= 1

    result = 1 #나무 꼭대기 도달위해 최소 한 마리 원숭이 필요
    for _ in range(max_depth):
        result *= 2
    results.append(result)

for result in results:
    print(result)