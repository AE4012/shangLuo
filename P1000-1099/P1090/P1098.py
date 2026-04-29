import sys


def solve(left: str, right: str, p1: int, p2: int, p3: int) -> int:
    gap = ord(right) - ord(left) - 1
    if gap <= 0:
        return ""

    if p1 == 3:
        seq = ['*']*gap
    else:
        seq = [chr(ord(left)+i) for i in range(1, gap+1)]
        if left.islower():
            if p1 == 2:
                seq = [ch.upper() for ch in seq]
    if p3 == 2:
        seq.reverse()
    
    return "".join(ch * p2 for ch in seq)

    
if __name__ == "__main__":
    data = sys.stdin.read().splitlines()
    p1, p2, p3 = map(int, data[0].split())
    s = data[1].rstrip('\n')

    ans = []
    for i, ch in enumerate(s):
        if ch != '-':
            ans.append(ch)
            continue
    
        # '-'在0或者最后一个位置，不处理
        if i == 0 or i == len(s)-1:
            ans.append('-')
            continue
        
        # '-'的左右数据
        left = s[i-1]
        right = s[i+1]

        # 如果left和right类型不一致
        same_type_tag = (left.islower() and right.islower()) or (left.isdigit() and right.isdigit())
        if not same_type_tag or ord(right) <= ord(left):
            ans.append('-')
            continue


        if ord(right) == ord(left)+1:
            continue

        ans.append(solve(left, right, p1, p2, p3))

    print("".join(ans))


    