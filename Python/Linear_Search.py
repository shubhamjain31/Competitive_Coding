def LinearSearch(arr, size, element):
	for i in range(0, size):
		if arr[i] == element:
			return i
	return -1
	
arr = [52, 29, 18, 63, 34]
size = len(arr)
element = 187
pos = LinearSearch(arr, size, element)

if pos == -1:
	print("{} is not found".format(element))
else:
	print("Element found at index {}".format(pos))