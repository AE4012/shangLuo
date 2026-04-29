"""
P1400-1499.P1420.P1425 小鱼游泳时间
"""

if __name__ == "__main__":
    # 从 a 时 b 分一直游泳到当天的 c 时 d 分
    a, b, c, d = map(int, input().split())
    # 输出两个整数e和f，表示一共游了e小时，f分钟
    total_start = a * 60 + b
    total_end = c * 60 + d
    if total_end < total_start:
        total_end += 24 * 60
    total = total_end - total_start
    e = total // 60
    f = total % 60
    print(e, f)