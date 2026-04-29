if __name__ == "__main__":
    x, y = map(int, input().strip().split())
    if x <= 1 and x >= -1:
        if y <= 1 and y >= -1:
            print("Yes")
        else:
            print("No")
    else:
        print("No")


