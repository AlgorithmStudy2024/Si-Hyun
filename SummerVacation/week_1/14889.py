def cal_stats():
    global result, cnt
    cnt += 1
    not_in_combination = []
    for idx, i in enumerate(visit):
        if not i:
            not_in_combination.append(idx)

    start = 0
    for i in combination:
        for j in combination:
            if i != j:
                start += S[i][j]

    link = 0
    for i in not_in_combination:
        for j in not_in_combination:
            if i != j:
                link += S[i][j]
    result = min(result, abs(link-start))

def comb(select, start):
    if select == N // 2:
        cal_stats()
    elif select > N // 2:
        return
    else:
        for i in range(start, N):
            combination.append(i)
            visit[i] = True
            comb(select+1, i + 1)
            visit[i] = False
            del combination[-1]

N = int(input())

S = []
for i in range(N):
    S.append(list(map(int, input().split())))

combination = []
visit = [False for i in range(N)]
result = 1000
cnt = 0
comb(0, 0)

print(result)