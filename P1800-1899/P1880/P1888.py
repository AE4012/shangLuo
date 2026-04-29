

if __name__ == "__main__":
    a, b, c = map(int, input().split())
    min_data = min(a, b, c)
    max_data = max(a, b, c)
    def gcd(a, b):
        if b == 0:
            return a
        return gcd(b, a % b)


    g = gcd(min_data, max_data)
    print(f"{min_data//g}/{max_data//g}")