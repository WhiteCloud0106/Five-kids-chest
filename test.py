import subprocess

record_file = open("record.txt", "w", encoding="utf-8")
BOARD_SIZE = 19
LETTERS = "ABCDEFGHIJKLMNOPQRS"

def init_board():
    return [['.' for _ in range(BOARD_SIZE)] for _ in range(BOARD_SIZE)]

def board_to_input(board):
    return '\n'.join(' '.join(row) for row in board)

def call_ai(exe_path, color, board):
    input_data = board_to_input(board)
    try:
        result = subprocess.run(
            [exe_path, color],
            input=input_data,
            text=True,
            capture_output=True,
            timeout=1
        )
        return result.stdout.strip()
    except subprocess.TimeoutExpired:
        print(f"{color} 超時落子")
        return None

def parse_move(move_str):
    try:
        col_letter, row_str = move_str.split(',')
        col = LETTERS.index(col_letter.strip().upper())
        row = int(row_str.strip()) - 1
        return row, col
    except:
        return None, None

def print_board(board):
    print("   " + ' '.join(LETTERS))
    for i in range(BOARD_SIZE):
        print(f"{i+1:2} " + ' '.join(board[i]))

def check_winner(board, r, c):
    player = board[r][c]
    if player == '.':
        return None

    directions = [
        (0, 1),   # →
        (1, 0),   # ↓
        (1, 1),   # ↘
        (1, -1),  # ↙
    ]

    for dr, dc in directions:
        count = 1
        for step in [1, -1]:
            nr, nc = r, c
            while True:
                nr += step * dr
                nc += step * dc
                if 0 <= nr < 19 and 0 <= nc < 19 and board[nr][nc] == player:
                    count += 1
                else:
                    break
        if count >= 5:
            return 'Black' if player == '1' else 'White'

    return None

def main():
    board = init_board()
    turn = 0

    while turn < BOARD_SIZE * BOARD_SIZE:
        color = "Black" if turn % 2 == 0 else "White"
        exe_path = "./main/cbb113000" if color == "Black" else "./main/cbb113136"
        player_value = '1' if color == "Black" else '0'

        move_str = call_ai(exe_path, color, board)
        if move_str is None:
            print(f"{color} 無效落子，結束")
            break

        row, col = parse_move(move_str)
        if row is None or not (0 <= row < 19 and 0 <= col < 19):
            print(f"{color} 格式錯誤：{move_str}")
            break

        if board[row][col] != '.':
            print(f"{color} 落子重複：{move_str}")
            break

        board[row][col] = player_value  # 落子為 0 或 1
        print(f"{color} 落子：{move_str}")
        print_board(board)
        print("-" * 40)
        record_file.write(f"{turn+1:02d}. {color} 落子：{move_str}\n")
        for i in range(19):
            record_file.write(' '.join(board[i]) + '\n')
        record_file.write("-" * 40 + "\n")

        winner = check_winner(board, row, col)
        if winner:
            print(f"{winner} 獲勝！")
            record_file.write(f"{winner} 獲勝！\n")
            break

        turn += 1

    print("對戰結束")
    record_file.close()

if __name__ == "__main__":
    main()