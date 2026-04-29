import sys
def judge(s:str) -> bool:
    if len(s) == 0:
        return True
    if len(s) % 2 == 1:
        return False
    stack = []
    for c in s:
        if c == "(" or c == "[" or c == "{":
            stack.append(c)
        else:
            if len(stack) == 0:
                return False
            top = stack.pop()
            if (top == "(" and c != ")") or (top == "[" and c != "]") or (top == "{" and c != "}"):
                return False
    
    return len(stack) == 0

if __name__ == "__main__":
    T = int(input().strip())
    data = sys.stdin.read().strip().split("\n")
    for _ in range(T):
        s = data[_]
        if judge(s):
            print("YES")
        else:
            print("NO")
