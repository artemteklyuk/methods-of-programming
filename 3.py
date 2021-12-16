S, N = (int(i) for i in input().split())
A = list(map(int, input().split(maxsplit = N)))
F = [1] + [0] * S

for j in range(len(A)):
    for i in range(S, A[j] - 1, -1):
        if F[i - A[j]] == 1:
            F[i] = 1

i = S
while F[i] == 0:
    i -= 1

print(i)