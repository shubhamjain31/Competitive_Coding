#function to left rotate an array by one position
def leftRotationByOne(arr, n):
	temp = arr[0]
	for i in range(n-1):
		arr[i] = arr[i+1]
	arr[n-1] = temp
	
#function to left rotate an array by d positions
def leftRotation(arr, d, n):
	for i in range(d):
		leftRotationByOne(arr, n)

if __name__ == '__main__':
	arr  = [1,2,3,4,5]
	n = len(arr)
	d = 3
	leftRotation(arr, d, n)
	
	for i in range(n):
		print(arr[i],end =' ')