def solve():
    n = int(input())
    x = int(input())
    
    if n == 0:
        return "0"
    
    # 建立 0-35 对应的字符表
    chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    x_str = []
    
    while n > 0:
        # 1. 求余数
        rem = n % x
        # 2. 根据余数查表，获取对应的字符，并加入列表中
        x_str.append(chars[rem])
        # 3. 整除
        n //= x
        
    # 翻转并拼接成最终的字符串
    return "".join(reversed(x_str))


if __name__ == "__main__":
    print(solve())