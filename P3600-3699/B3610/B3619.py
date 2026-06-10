
def solve():
    n = int(input())
    x = int(input())
    
    # 十进制整数 n 转 x 进制；给定一个十进制整数 n 和一个小整数 x。将整数 n 转为 x 进制。对于超过十进制的数码，用 A，B ... 表示。
    if n == 0:
        return "0"
    x_str = ""
    while n > 0:
        x_str += str(n % x)
        n //= x
    return x_str[::-1]


if __name__ == "__main__":
    solve()
