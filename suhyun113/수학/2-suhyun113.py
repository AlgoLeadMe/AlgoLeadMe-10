# 팰린드롬 수
def is_palindrome(num):
    return str(num) == str(num)[::-1]

# 소수 찾기
def is_prime_num(n):
    if n < 2:
        return False # 1은 소수가 아님
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

N = int(input())  # 어떤 수 N
# output은 N보다 크거나 같으므로 N으로 초기화
result = N # 현재

while True: # N보다 크거나 같은 수(항상)
    if is_prime_num(result) and is_palindrome(result): # 소수이면서 팰린드롬인 수       
        print(result)
        break
    result += 1