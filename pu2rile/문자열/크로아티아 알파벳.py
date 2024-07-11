change = ['c=','c-','dz=','d-','lj','nj','s=','z=']
str = input()
for n in change: #change에서 하나씩 루프 돌며
  str = str.replace(n, 'a') #str과 같은 문자를 발견하면 해당 문자를 a으로 치환
print(len(str)) #str의 길이