if __name__ == "__main__":
    a, b = map(int, input().strip().split())
    
    ## 输出a/b, 双精度浮点，小数点后9位
    print(f"{a/b:.9f}")


