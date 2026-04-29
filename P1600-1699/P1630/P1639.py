

if __name__ == "__main__":
    a, b, x, y = map(int, input().split())
    dist = abs(b - a)
    dist_left = min(abs(a-x),abs(a-y))
    dist_right = min(abs(b-x), abs(b-y))
    
    print(min(dist, dist_left+dist_right))