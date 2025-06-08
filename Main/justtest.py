import subprocess

# 建立空棋盤（全是 '.'）
empty_board = [['.' for _ in range(19)] for _ in range(19)]
empty_board[9][9] = '1'
#empty_board[0][0] = '0'
#empty_board[8][8] = '1'
#empty_board[7][7] = '0'
#empty_board[8][9] = '1'
#empty_board[7][8] = '0'
#empty_board[9][7] = '1'
#empty_board[7][9] = '0'

# 將棋盤轉成文字格式（空格隔開）
def board_to_input(board):
    return '\n'.join(' '.join(row) for row in board)

# 呼叫黑子程式
def test_black():
    board_input = board_to_input(empty_board)

    result = subprocess.run(
        ["./a.exe", "White"],   # 執行檔與參數
        input=board_input,          # 傳入棋盤
        text=True,                  # 文字模式
        capture_output=True,        # 擷取 stdout 與 stderr
        timeout=1                   # 最多等待 1 秒
    )

    print("程式輸出：", result.stdout.strip())
    print("錯誤輸出（如果有）：", result.stderr.strip())

# 呼叫測試
test_black()