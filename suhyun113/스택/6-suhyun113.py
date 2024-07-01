def solution(s):
    answer = 0
    
    stack = [float("inf")]
    
    # 문자열을 공백 기준으로 나누어 리스트에 저장
    s_list = s.split()
    
    for i in s_list: # i는 s_list의 인덱스가 아닌 값 
        if i != 'Z':
            stack.append(i)
        else:
            stack.pop()  #  stack의 가장 위의 값 빼기
    stack.pop(0)
    
    # 문자를 정수로 변환하기
    for i in stack:
        n = int(i)
        answer += n
    return answer