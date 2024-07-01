n = int(input())
cnt = 0
six = 666
while True:
    if '666' in str(six):
        cnt += 1
    if cnt == n:
        break
    
    six += 1

print(six)