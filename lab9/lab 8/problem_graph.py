import matplotlib.pyplot as plt

price = [1, 5, 8, 9, 10]
n = len(price)

dp = [0] * (n + 1)

for i in range(1, n + 1):
    max_val = float('-inf')
    for j in range(i):
        max_val = max(max_val, price[j] + dp[i - j - 1])
    dp[i] = max_val


print("Length vs Maximum Profit:")
for i in range(1, n + 1):
    print(f"{i} -> {dp[i]}")

lengths = list(range(1, n + 1))
profits = dp[1:]

plt.plot(lengths, profits, marker='o')
plt.xlabel("Rod Length")
plt.ylabel("Maximum Profit")
plt.title("Rod Cutting Problem (DP)")
plt.grid()

plt.show()