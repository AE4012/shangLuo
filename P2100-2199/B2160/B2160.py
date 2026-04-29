if __name__ == "__main__":
    n = int(input().strip())
    old_men = []
    young_men = []
    for i in range(n):
        a, b = map(str, input().strip().split())
        b = int(b)

        if b >= 60:
            old_men.append((a, b))
        else:
            young_men.append(a)

    old_men.sort(key=lambda x: x[1], reverse=True)
    for i in range(len(old_men)):
        print(old_men[i][0])
    for i in range(len(young_men)):
        print(young_men[i])