T = int(input())

for _ in range(T):
    N = int(input())
    score = [list(map(int, input().split())) for _ in range(N)]

    # 서류 심사 성적 기준으로 오름차순 정렬
    rank_1 = sorted(score)
    top = 0 # 서류 성적이 가장 좋은 사람을 기준으로 설정 (첫 번째 사람)
    result = 1  # 첫 번째 지원자는 항상 합격하므로 결과를 1로 시작
    
    # 2번째 지원자부터 서류 성적 순으로 면접 성적 비교
    for i in range(1, len(rank_1)):
        # 현재 지원자의 면접 성적이 기준점(top)의 지원자보다 좋으면 (숫자가 낮으면)
        if rank_1[i][1] < rank_1[top][1]:
            top = i # 기준점(top)을 현재 지원자로 갱신
            result += 1
    
    print(result)   