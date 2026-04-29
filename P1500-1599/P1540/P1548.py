import sys
# def main():
#     data = sys.stdin.read().strip().split()
#     if not data:
#         return
#     N, M = map(int, data)

#     # squares
#     K = min(N, M)
#     squares = 0
#     for k in range(1, K + 1):
#         squares += (N - k + 1) * (M - k + 1)

#     # all rectangles
#     rectangles = (N * (N + 1) // 2) * (M * (M + 1) // 2)

#     non_square_rectangles = rectangles - squares
#     print(squares, non_square_rectangles)

if __name__ == "__main__":
    N, M = map(int, input().strip().split())
    k = min(N, M)
    squares = 0
    for i in range(1, k + 1):
        squares += (N - i + 1) * (M - i + 1)

    rectangles = (N * (N + 1) // 2) * (M * (M + 1) // 2)
    print(squares, rectangles - squares)
