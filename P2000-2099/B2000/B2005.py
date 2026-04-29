if __name__ == "__main__":
    char = input().strip()

    # 优雅的循环：高度为 3
    for i in range(3):
        spaces = " " * (2 - i)
        chars = char * (2 * i + 1)
        print(spaces + chars)