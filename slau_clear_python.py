import math

def clear_python_solve():
    a = [[1, 0.17, -0.25, 0.54], [0.47, 1, 0.67, -0.32], [-0.11, 0.35, 1, -0.74], [0.55, 0.43, 0.36, 1]]
    f = [[0.3], [0.5], [0.7], [0.9]]
    x = [[0]] * 4
    for i in range(len(a)):
        for j in range(len(a)):
            if (i != j):
                a[i][j] = a[i][j] / (-1) * a[i][i]

    for i in range(len(a)):
        x[i] = [f[i][0] / a[i][i]]

    for i in range(len(a)):
        f[i] = [f[i][0] / a[i][i]]

    for i in range(len(a)):
        a[i][i] = 0

    t = [0]*len(a)
    for k in range(16):
        for i in range(len(a)):
            for j in range(len(a)):
                t[j] = a[i][j] * x[j][0]

            l = math.fsum(t)

            x[i][0] = l + f[i][0]
    return x