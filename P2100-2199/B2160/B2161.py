def _2bin(n:int)->str:
    """
    将十进制整数转换为二进制字符串
    """
    if n == 0:
        return "0"

    b = ""
    while n > 0:
        b = str(n % 2) + b
        n //= 2
    return b

if __name__ == "__main__":
    n = int(input().strip())
    #二进制
    b = bin(n)[2:]
    print(b)
    # print(_2bin(n))

