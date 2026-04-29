

if __name__ == "__main__":
    source = input().strip()
    target = input().strip()

    origin_message = input().strip()
    new_message = ""

    table = {} 
    if set(source) != set(target) or len(set(source)) != 26:
        print("Failed")
        exit(0)

    for ch1, ch2 in zip(source, target):
        if ch1 not in table:
            table[ch1] = ch2
        else:
            if table[ch1] != ch2:
                print("Failed")
                exit(0)

    for ch in origin_message:
        if ch in table:
            new_message += table[ch]
        else:
            print("Failed")
            exit(0)

    print(new_message)
