#Maximum Subarray Problem

def maxSumarray(nums, size):
	max_ending_here = 0
	max_sum_so_far = 0
	for i in range(0, size):
		max_ending_here = max_ending_here + nums[i]
		if max_ending_here < 0:
			max_ending_here = 0
		if max_sum_so_far < max_ending_here:
			max_sum_so_far = max_ending_here
	return max_sum_so_far
		
	
a = []
size = int(input("Enter the size of array: "))
print("Enter the elements of the array: ")
for i in range(0, size):
	a.append(input())
nums = [int(i) for i in a]
max_sum = maxSumarray(nums, size)
print("Maximum sum of the subarray is: {}".format(max_sum))