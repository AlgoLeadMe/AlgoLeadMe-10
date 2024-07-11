N = int(input())
dasom = int(input())
vote = []
cnt = 0

for _ in range(N-1):
  vote.append(int(input()))

vote.sort(reverse=True) #내림차순 정렬

if N == 1:
  print('0')
else:
    while vote[0] >= dasom:
        dasom += 1
        vote[0] -= 1
        cnt += 1
        vote.sort(reverse=True)
    print(cnt)
