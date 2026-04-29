
def solve():
    oct_num = input()
    decimal_num = int(oct_num, 8)
    hex_num = hex(decimal_num)
    print(hex_num[2:])

if __name__ == "__main__":
    solve()
