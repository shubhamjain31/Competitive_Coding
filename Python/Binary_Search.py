def BinearSearch(arr, size, element):
	low = 0
	high = size - 1
	while low <= high:
		mid = int((low + high)/2)
		if arr[mid] == element:
			return mid
		if arr[mid] < element:
			low = mid + 1
		else:
			high = mid - 1
	return -1
	
arr = [12, 29, 48, 63, 84]
size = len(arr)
element = 63
pos = BinearSearch(arr, size, element)

if pos == -1:
	print("{} is not found".format(element))
else:
	print("Element found at index {}".format(pos))