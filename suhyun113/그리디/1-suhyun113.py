def solution(n, lost, reserve):
    answer = 0
    
    re = list(set(reserve) - set(lost))
    lo = list(set(lost) - set(reserve))
        
    for i in re:
        if i-1 in lo: 
            lo.remove(i-1)
        elif i+1 in lo: 
            lo.remove(i+1)
    
    answer = n - len(lo)
    return answer