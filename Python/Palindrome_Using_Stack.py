class stack:
    def __init__(self):
        self.item = [] 
    
    def  isEmpty(self):
        return self.item == [] 
    
    def  insert(self, data):
        self.item.append(data) 
    
    def remove(self):
        return self.item.pop()

s = stack()
text = input('Enter the string: ') 
for char in text:
    s.insert(char)
reverse = ''
while not s.isEmpty():
    reverse = reverse + s.remove() 
if text == reverse:
    print('\nThe string is palindrome')
else:
    print('\nThe string is not palindrome')