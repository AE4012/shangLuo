if __name__ == "__main__":
    data = list(map(int, input().strip().split()))
    print(" ".join(f"{x:8d}" for x in data))