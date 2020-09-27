class Tree:
    def __init__(node,value):
        node.value = value
        node.right = None
        node.left = None
    
    def createNode(node,value):
        if (node.value is None):
            node.value = value
        else:
            if( value < node.value ):
                if (node.left is None): 
                    node.left = Tree(value)
                else:
                    node.left.createNode(value)
            elif( value > node.value ):
                if ( node.right is None):
                    node.right = Tree(value)
                else:
                    node.right.createNode(value)
    
    def Inorder( node, Root ): 
        if( Root is None ):
            return
        node.Inorder(Root.left)
        print(Root.value,end = ' ')
        node.Inorder(Root.right)
     
    def Preorder( node, Root ): 
        if( Root is None ):
            return
        print(Root.value,end = ' ')
        node.Preorder(Root.left)
        node.Preorder(Root.right)
        
    def Postorder( node, Root ): 
        if( Root is None ):
            return
        node.Postorder(Root.left)
        node.Postorder(Root.right)
        print(Root.value,end = ' ')
    
Root = Tree(5)
Root.createNode(7)
Root.createNode(2)
Root.createNode(3)
Root.createNode(6)
Root.createNode(1)
Root.createNode(8)

print('Postorder traversal')
Root.Inorder(Root)

print('\n')
print('Inorder traversal')
Root.Preorder(Root)

print('\n')
print('Preorder traversal')
Root.Postorder(Root)