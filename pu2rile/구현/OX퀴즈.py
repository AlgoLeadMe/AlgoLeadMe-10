n = int(input())
for _ in range(n):
    test = list(input())
    score = 0  
    sum_score = 0  #새로운 태스트를 입력받으면 점수 리셋
    for ox in test:
        if ox == 'O':
            score += 1  #'O'가 연속되면 점수가 1점씩 추가
            sum_score += score
        else:
            score = 0
    print(sum_score)