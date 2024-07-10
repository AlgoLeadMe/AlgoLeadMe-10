N, K = map(int, input().split()) #입력으로 주어지는 수는 모두 정수
item = [[0,0]]
bag = [[0 for _ in range(K + 1)] for _ in range(N + 1)] 
#가로 - 가방 1~K까지의 무게, 세로 - 물건 N개의 개수로 이루어진 2차원 배열

for _ in range(N): #물건의 최대 개수(N)만큼 입력
    item.append(list(map(int, input().split())))


#알고리즘
for i in range(1, N + 1): #물건
    for j in range(1, K + 1): #최대 무게
        w = item[i][0]
        v = item[i][1]

        if j < w:
            bag[i][j] = bag[i - 1][j] #w(eight)보다 작으면 위의 값을 그대로 가져옴
        else:
            bag[i][j] = max(v + bag[i - 1][j - w], bag[i - 1][j])
            #bag[i][j] = max(현재 물건 가치 + bag[이전 물건][현재 가방 무게-현재 물건 무게], bag[이전 물건][현재 가방 무게])

print(bag[N][K])