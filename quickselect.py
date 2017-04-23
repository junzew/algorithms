# return k-th largest element of A
# pre-condition: len(A) >= k
def quickselect(A, k):
	if len(A) >= 1:
		p = A[0]
		lesser = [v for v in A if v < p]
		greater = [v for v in A if v > p]
		kp = len(greater) + 1
		if (kp == k):
			return p
		elif (kp > k):
			return quickselect(greater, k)
		else:
			return quickselect(lesser, k-kp)

# print(quickselect([1,4,2,5,3], 3) == 3)
# print(quickselect([1,4,2,5,3], 2) == 4)
# print(quickselect([1,3,5,7,9,11], 4) == 5)