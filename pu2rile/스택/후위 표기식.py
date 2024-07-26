MAX_STACK_SIZE = 100
MAX_EXPR_SIZE = 100

class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return not self.items

    def push(self, item):
        if len(self.items) >= MAX_STACK_SIZE:
            raise OverflowError("스택 포화 에러: 최대 크기 초과")
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            raise IndexError("스택 공백 에러")
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            raise IndexError("스택 공백 에러")
        return self.items[-1]

def prec(op):
    if op in {'+', '-'}:
        return 1
    elif op in {'*', '/'}:
        return 2
    else:
        return 0

def infix_to_postfix(exp):
    if len(exp) > MAX_EXPR_SIZE:
        raise ValueError("수식 길이 초과 에러: 최대 길이 초과")
    
    s = Stack()
    postfix = []
    for ch in exp:
        if ch.isalnum():  # 피연산자 (숫자, 문자 등)
            postfix.append(ch)
        elif ch == '(':
            s.push(ch)
        elif ch == ')':
            while not s.is_empty() and s.peek() != '(':
                postfix.append(s.pop())
            s.pop()  # '(' 버림
        else:  # 연산자
            while not s.is_empty() and prec(ch) <= prec(s.peek()):
                postfix.append(s.pop())
            s.push(ch)

    while not s.is_empty():  # 스택에 남아 있는 모든 연산자를 출력
        postfix.append(s.pop())

    return ''.join(postfix)

def main():
    expr = input()
    postfix_expr = infix_to_postfix(expr)
    print(postfix_expr)

if __name__ == "__main__":
    main()