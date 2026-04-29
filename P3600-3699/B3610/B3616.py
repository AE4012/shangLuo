import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    que = []
    
    # 记录当前处理到 input_data 的哪个位置
    ptr = 1
    
    for _ in range(n):
        op = input_data[ptr]
        ptr += 1
        
        if op == '1':  # push x
            x = input_data[ptr]
            que.append(x)
            ptr += 1
        elif op == '2':  # pop
            if que:
                que.pop(0) # 弹出队首
            else:
                print("ERR_CANNOT_POP")
        elif op == '3':  # query
            if que:
                print(que[0])
            else:
                print("ERR_CANNOT_QUERY")
        elif op == '4':  # size
            print(len(que))

if __name__ == "__main__":
    solve()