if __name__ == "__main__":
    N = int(input().strip())
    # 求高16位
    low = N & 0xFFFF
    high = N >> 16 & 0xFFFF

    ans = (low << 16) | high
    print(ans)