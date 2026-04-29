if __name__ == "__main__":
    xl, xu = map(int, input().split())
    yl, yu = map(int, input().split())

    INT_MAX = 2147483647
    INT_MIN = -2147483648

    products = [
        xl * yl,
        xl * yu,
        xu * yl,
        xu * yu
    ]

    if min(products) < INT_MIN or max(products) > INT_MAX:
        print("long long int")
    else:
        print("int")