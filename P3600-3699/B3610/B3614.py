import sys

def solve():
    data = sys.stdin
    T = int(data.readline())
    
    output = []  # 收集输出，最后统一写出
    
    for _ in range(T):
        n = int(data.readline())
        stack = []
        
        for _ in range(n):
            line = data.readline().strip()
            
            if line[0] == 'p':  # push 或 pop
                if line[1] == 'u':  # push
                    # push x
                    x = int(line.split()[1])
                    stack.append(x)
                else:  # pop
                    if stack:
                        stack.pop()
                    else:
                        output.append("Empty")
            
            elif line[0] == 'q':  # query
                if stack:
                    output.append(str(stack[-1]))
                else:
                    output.append("Anguei!")
            
            else:  # size
                output.append(str(len(stack)))
    
    sys.stdout.write("\n".join(output))


if __name__ == "__main__":
    solve()