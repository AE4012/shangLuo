
from collections import deque

if __name__ == "__main__":
    S, C, L, P0, N =map(float, input().split())
    N = int(N)

    max_range = C * L

    # 加油站信息
    # D: 距离 P: j价格
    D = [0.0]
    P = [P0]

    for i in range(N):
        d, p = map(float, input().split())
        if d - D[-1] > max_range:
            print("No Solution")
            exit(0)
        D.append(d)
        P.append(p)

    # 终点
    D.append(S)
    P.append(0.0)

    """
    计算最小花费，先买在退
    """
    OIL = deque() # 存储加油站的价格和油量
    OIL.append({"price":P0, "oil": C}) # 初始加满油

    cost = P0 * C  # 初始加满油
    fuel = C      # 当前油量

    for i in range(1, N + 2):
        need = (D[i] - D[i-1]) / L  # 需要的油量
        while need > 0 and OIL:
            p = OIL[0]
            if p["oil"] > need:
                p["oil"] -= need
                fuel -= need
                need = 0
            else:
                need -= p["oil"]
                fuel -= p["oil"]
                OIL.popleft()

        if i == N + 1:
            # 到最后一站
            while OIL:
                p = OIL.popleft()
                cost -= p["price"] * p["oil"]  # 卖掉剩余的油
            break

        price_now = P[i]

        while OIL and OIL[-1]["price"] > price_now:
            p = OIL.pop()
            cost -= p["price"] * p["oil"]  # 卖掉剩余的油
            fuel -= p["oil"]

        # 加满油箱
        cost += price_now * (C - fuel)
        if C - fuel > 0:
            OIL.append({"price": price_now, "oil": C - fuel})
        
        
        fuel = C

    print(f"{cost:.2f}")