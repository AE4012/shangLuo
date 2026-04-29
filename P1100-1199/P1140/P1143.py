

if __name__ == "__main__":
    n = int(input().strip())
    input_str = input().strip()
    m = int(input().strip())
    
    val = 0
    for ch in input_str:
        if '0' <= ch <= '9':
            d = ord(ch) - ord('0')
        else:
            d = ord(ch) - ord('A') + 10
        val = val*n + d

    if val == 0:
        print('0')
        exit(0)

    digits = []
    while val > 0:
        r = val % m
        if r < 10:
            digits.append(chr(ord('0') + r))
        else:
            digits.append(chr(ord('A') + r - 10))
        val //= m

    
    # 逆序输出
    print(''.join(reversed(digits)))