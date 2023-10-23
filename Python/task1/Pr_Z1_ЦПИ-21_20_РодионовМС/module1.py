def D1(M):
    x, y = M
    return (y >= ((x - 2) ** 2 - 3)) and y >= 0 and x >= y


def D2(M):
    x, y = M
    return (y >= ((x - 2) ** 2 - 3)) and x <= abs(y) and y < 0


def fp(M):
    return D1(M) or D2(M)
