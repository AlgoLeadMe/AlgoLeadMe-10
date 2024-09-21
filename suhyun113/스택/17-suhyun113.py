# 1874 : 스택 수열

n = int(input())  # 수열의 크기
sequence = [int(input()) for _ in range(n)]  # 주어진 수열

stack = []
result = []
current = 1  # 스택에 넣을 숫자
possible = True

for num in sequence:
    # 현재 숫자보다 수열에서 필요한 숫자가 크거나 같을 때까지 push
    while current <= num:
        stack.append(current)
        result.append('+')
        current += 1
    
    # 스택의 최상단이 num과 같다면 pop
    if stack and stack[-1] == num:
        stack.pop()
        result.append('-')
    else:
        possible = False
        break

if possible:
    print("\n".join(result))
else:
    print("NO")