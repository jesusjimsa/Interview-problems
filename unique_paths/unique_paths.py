def factorial(number):
    result = 1

    for i in range(1, number):
        result = result * i

    return result


def uniquePaths(m, n):
    return int(factorial(m + n - 2) / (factorial(m - 1) * factorial(n - 1)))


m = 19
n = 13

print("Results for m =", m, "; n =", n, ":", uniquePaths(m, n))
