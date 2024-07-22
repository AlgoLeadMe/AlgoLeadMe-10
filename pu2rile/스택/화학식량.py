chemical = input()
stack = []
atomic = {'H':1, 'C':12, 'O':16} # 원자량 딕셔너리

for c in chemical:
  if c =='(': 
    stack.append(c)
  elif c == 'H' or c == 'C' or c == 'O':
    stack.append(atomic[c]) # 입력받은 원자의 원자량을 스택에 추가
  elif c == ')':
    temp = 0 # 닫는 괄호를 만나면 temp 초기화
    while True:
      if stack[-1] == '(': # 스택의 top이 여는 괄호면
        stack.pop() # 스택에서 여는 괄호를 삭제
        stack.append(temp) # 스택에 temp 추가
        break
      else:
        temp += stack.pop() # 여는 괄호 전까지의 스택 안의 모든 값을 temp에 저장
  else: # c가 숫자라면
    stack.append(stack.pop()*int(c)) # 스택의 top 값과 숫자를 곱하여 스택에 추가

print(sum(stack))