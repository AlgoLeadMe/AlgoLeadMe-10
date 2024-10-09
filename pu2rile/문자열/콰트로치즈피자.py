toping = int(input())
toping_lst = input().split()
cheese_set = set()

for cheese in toping_lst:
    # 토핑 이름의 마지막 6글자가 Cheese인지 확인
    # 치즈 토핑이 맞다면
    if cheese[-6:] == 'Cheese':
        # 집합에 치즈 이름 추가 (중복 자동 제거)
        cheese_set.add(cheese)  

if len(cheese_set) >= 4:    # 서로 다른 치즈가 4개 이상이면
    print("yummy")
else:
    print("sad")