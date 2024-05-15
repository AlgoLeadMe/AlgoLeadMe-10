num = int(input())
arr = list(map(int, input().split())) 
arr.sort() #입력받은 정수 오름차순 정렬
result = 0
time = 0
for i in range(num): 
    time += arr[i] #현재 사람이 기다리는 시간을 계산해서 time에 더함
    result += time #현재 사람까지의 총 대기 시간을 결과에 더함
print(result)