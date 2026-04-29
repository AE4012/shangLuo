"""
P1300-1399.P1300.P1307 的 Docstring

"""

if __name__ == "__main__":
    n = input().strip()

    # 处理符号
    sign = ''
    if n[0] == '-':
        sign = '-'
        n = n[1:]

    # 反转并去掉前导 0
    rev = n[::-1].lstrip('0')

    # 特殊情况：原数为 0 或全是 0
    if rev == '':
        rev = '0'

    print(sign + rev)
