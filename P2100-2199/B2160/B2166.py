import sys
import bisect

data = list(map(int, sys.stdin.buffer.read().split()))

n = data[0]
m = data[1]

a = data[2:2+n]
queries = data[2+n:]

write = sys.stdout.write

for q in queries:
    i = bisect.bisect_left(a, q)
    if i < n and a[i] == q:
        write(str(i+1) + "\n")
    else:
        write("-1\n")