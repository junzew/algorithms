def quicksort(A):
	if len(A) >= 1:
		p = A[0]
		lesser = [v for v in A if v < p]
		greater = [v for v in A if v > p]
		return quicksort(lesser) + [p] + quicksort(greater)
	else:
		return A

# print(quicksort([1]))
# print(quicksort([3,2,1]))
# print(quicksort([1,3,2]))
# print(quicksort([7,3,2,1,4,6,5]))