L, R = input().split()

if len(L) != len(R): #각 숫자의 자릿수가 같아야 함, 서로 다르면 0 출력
    print(0)
else:
    eight = 0
    for i in range(len(L)):
        if L[i] == R[i] and L[i] == '8': #같은 자리의 숫자가 8이면
            eight += 1 #8의 개수 1 증가
        else: #8이 존재하는 자릿수가 다르면 계산하지 않음, 비교 중단
            break
    print(eight)