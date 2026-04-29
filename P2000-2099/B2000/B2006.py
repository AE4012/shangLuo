if __name__ == "__main__":
    x, a, y, b = map(int, input().strip().split())
    z = (y * b - x * a) / (b - a)
        
    # 格式化输出，保留两位小数
    print(f"{z:.2f}")