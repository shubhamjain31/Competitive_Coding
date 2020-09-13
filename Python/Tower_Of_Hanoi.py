def TOH(n, source, auxiliary, destination):
	if n == 1:
		print("Move from {} to {}".format(source,destination))
	else:
		TOH(n-1, source, destination, auxiliary)
		TOH(1, source, auxiliary, destination)
		TOH(n-1, auxiliary, source, destination)
		
print("Enter number of disks:\n")
n = int(input())
TOH(n, 'A', 'B', 'C')