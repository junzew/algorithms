# return length of longest common subsequent of string A and B
def LLCS(A, B):
	if len(A) == 0 or len(B) == 0:
		return 0
	elif (A[-1] == B[-1]):
		return LLCS(A[:-1], B[:-1]) + 1
	else:
		return max(LLCS(A[:-1], B), LLCS(A, B[:-1]))

# memoized version
def memo(A, B):
	n, m = len(A), len(B)
	M = [[None for x in range(m+1)] for y in range(n+1)]
	return memo_helper(M, A, B, n, m)
	
def memo_helper(M, A, B, n, m):
	if M[n][m] == None:
		if n == 0 or m == 0:
			M[n][m] = 0
		elif A[n-1] == B[m-1]:
			M[n][m] = memo_helper(M, A, B, n-1, m-1) + 1
		else:
			M[n][m] = max(memo_helper(M, A, B, n-1, m), memo_helper(M, A, B, n, m-1))			
	return M[n][m]

# dynamic programming solution
def dp(A, B):
	n, m = len(A), len(B)
	M = [[0 for x in range(m+1)] for y in range(n+1)]
	for i in range(1, n+1):
		for j in range(1, m+1):
			if A[i-1] == B[j-1]:
				M[i][j] = M[i-1][j-1] + 1
			else:
				M[i][j] = max(M[i][j-1], M[i-1][j]) 
	print(explain(M, A, B, n, m))
	return M[n][m]

# produce the Longest Common Subsequence from table M
def explain(M, A, B, n, m):
	if n <= 0 or m <= 0:
		return ""
	elif A[n-1] == B[m-1]:
		return explain(M, A, B, n-1, m-1) + A[n-1]
	elif M[n-1][m] > M[n][m-1]:
		return explain(M, A, B, n-1, m)
	else: # M[n][m-1] > M[n-1][m]
		return explain(M, A, B, n, m-1)

# print(LLCS("","a") == 0)
# print(LLCS("a","a") == 1)
# print(LLCS("a","ab") == 1)
# print(LLCS("abc","ab") == 2)
# print(LLCS("abcd","ebdf") == 2)
# print(LLCS("tycoon","country") == 3)
# print(LLCS("XMJYAUZ","MZJAWXU") == 4)
# print(LLCS("HIEROGLYPHOLOGY","MICHAELANGELO") == 5) #HELLO

# print(memo("","a") == 0)
# print(memo("a","a") == 1)
# print(memo("a","ab") == 1)
# print(memo("abc","ab") == 2)
# print(memo("abcd","ebdf") == 2)
# print(memo("tycoon","country") == 3)
# print(memo("XMJYAUZ","MZJAWXU") == 4)
# print(memo("HIEROGLYPHOLOGY","MICHAELANGELO") == 5) #HELLO

# print(dp("","a") == 0)
# print(dp("a","a") == 1)
# print(dp("a","ab") == 1)
# print(dp("abc","ab") == 2)
# print(dp("abcd","ebdf") == 2)
# print(dp("tycoon","country") == 3)
# print(dp("XMJYAUZ","MZJAWXU") == 4)
# print(dp("HIEROGLYPHOLOGY","MICHAELANGELO") == 5) #HELLO
