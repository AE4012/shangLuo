

if __name__ == "__main__":

    n = int(input().strip())
    code = input().strip()
    # 密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 n 位形成的。

    for c in code:
        print(chr((ord(c) - ord('a') + n) % 26 + ord('a')), end='')




