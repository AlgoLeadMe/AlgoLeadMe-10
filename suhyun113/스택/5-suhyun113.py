def solution(board, moves):
    answer = 0
    basket = [float("inf")] # board배열에서 뽑은 인형들을 넣는 바구니

    N = len(board) # board 2차원 배열은 N*N이므로, board의 행 또는 열의 길이를 N으로 받음.

    # moves 1차원 배열에 있는 요소에 따라 어떤 열의 인형을 뽑을 지 정함.
    for move in moves: #[1 5 3 5 1 2 1 4]
        move -= 1 # 1번째가 실제로 board배열에서는 0번째 이므로, 각 요소마다 1씩 빼줌.
        doll = 0 # 인형이 비어있다고 가정 -> 0으로 초기화

        for i in range(N):
            if board[i][move] != 0:  # 열은 move로 정해져 있고, 행이 i로 계속 변함.
                doll = board[i][move] # 0이 아니라면, 인형이 있는 것이므로, 인형의 값을 변경
                board[i][move] = 0
                break

        if doll != 0:  # 인형이 비어있지 않아서 doll에 새로운 인형의 값이 들어갔을 때,
            if basket[-1] == doll: # 바구니 가장 위에 담긴 인형과 새로 뽑은 인형이 같다면
                basket.pop() # 바구니 가장 위의 인형 제거
                answer += 2 # 같은 인형이 바구니에 담겼으므로, 2개의 인형이 터짐
            else:
                basket.append(doll) # 바구니의 가장 위의 인형과 같은 인형이 아니라면, doll을 새로 바구니에 추가하기              
    return answer