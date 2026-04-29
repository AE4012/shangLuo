

if __name__ == "__main__":
    #  输入一串整数
    nums = list(map(int, input().split()))

    print(' '.join(map(str, nums[-2::-1])))