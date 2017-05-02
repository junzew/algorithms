def merge_sort(A):
	
	def merge_sort_helper(A):
		if len(A) <= 1: return A
		mid = len(A) // 2
		left = merge_sort_helper(A[:mid])
		right = merge_sort_helper(A[mid:])
		return merge(left, right)
	
	def merge(l1, l2):
		result = []
		i = j = 0
		while i < len(l1) and j < len(l2):
			if l1[i] < l2[j]:
				result += [l1[i]]
				i += 1
			else:
				result += [l2[j]]
				j += 1
		if i != len(l1):
			result += l1[i:]
		if j != len(l2):
			result += l2[j:]
		return result

	return merge_sort_helper(A)

print(merge_sort([]))
print(merge_sort([1]))
print(merge_sort([3,1,2,0]))
print(merge_sort([9,3,-2,1,0,-3,5,10]))
print(merge_sort([3,-2,6,2,9,8,-1,0,4,7,5,1,10]))