# compute n-th fibonacci number
# Naive recursive solution
def fib(n):
	if n <= 2:
		return 1
	else:
		return fib(n-1) + fib(n-2)

# memoization
def memo(n):
	M = [None for v in range(n+1)]	
	def memo_helper(M, n):
		if n <= 2:
			M[n] = 1
		elif M[n] == None:
			M[n] = memo_helper(M, n-1) + memo_helper(M, n-2)
		return M[n]

	return memo_helper(M, n)

# dynamic programming
def dp(n):
	if n <= 2: return 1
	M = [1 for v in range(n+1)]
	for i in range(3, n+1):
		M[i] = M[i-1] + M[i-2]
	return M[n]

def dp2(n):
	# use a dictionary
	fib = {}
	for k in range(1, n+1):
		if k <= 2: f = 1
		else: f = fib[k-1] + fib[k-2]
		fib[k] = f
	return fib[n]

for i in range(50):
	print(dp(i))