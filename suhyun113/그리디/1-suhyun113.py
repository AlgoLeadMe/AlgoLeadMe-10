def solution(n, lost, reserve):
    answer = 0
    
    # 여벌 체육복 가져온 학생이 체육복을 도난 당한 경우 제외
    re = list(set(reserve) - set(lost))
    lo = list(set(lost) - set(reserve))
        
    # 체육복 빌려주기
    for i in re:
        if i-1 in lo:  # 앞번호 학생에게 체육복 빌려줌
            lo.remove(i-1)
        elif i+1 in lo: # 앞번호 학생이 체육복 있으므로, 뒷번호 학생에게 체육복 빌려줌
            lo.remove(i+1)
    
    answer = n - len(lo)
            
    return answer