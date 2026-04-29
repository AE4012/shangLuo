"""
表达式括号匹配
"""

import sys
if __name__ == "__main__":
    # 以@作为表达式的结束符
    data = input().strip()

    # 栈
    stack = []
    for ch in data:
        if ch == "@":
            break
        if ch == "(":
            stack.append(ch)
        elif ch == ")":
            if stack == []:
                print("NO")
                sys.exit(0)
            stack.pop()

    
    if stack == []:
        print("YES")
    else:
        print("NO") 
