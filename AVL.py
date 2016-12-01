class Node:
    def __init__(self,x):
        self.left=None
        self.right=None
        self.height=1
        self.data=x
class AVL:
    def __init__(self):
        self.root=None
    def H(self,node):
        if(node==None):
            return 0
        else:
            return node.height
    def leftRotate(self,node):
        tmp=node.right
        node.right=tmp.left
        node.height=max(self.H(node.right),self.H(node.left))+1
        tmp.left=node
        tmp.height=max(self.H(tmp.right),self.H(tmp.left))+1
        return tmp
    def rightRoatate(self,node):
        tmp=node.left
        node.left=tmp.right
        node.height=max(self.H(node.right),self.H(node.left))+1
        tmp.right=node
        tmp.height=max(self.H(tmp.right),self.H(tmp.left))+1
        return tmp
    def insert(self,x):
        def __insert(node,x):
            if(node==None):
                return Node(x)
            if(node.data<x):
                node.right=__insert(node.right,x)
            else:
                node.left=__insert(node.left,x)
            node.height=max(self.H(node.left),self.H(node.right))+1
            bal=self.H(node.left)-self.H(node.right)
            if(bal>1):
                if(x>node.left.data):
                    node.left=self.leftRoatate(node.left)
                    return self.rightRoatate(node)
                else:
                    return self.rightRoatate(node)
            if(bal<-1):
                if(x>node.right.data):
                    return self.leftRotate(node)
                else:
                    node.right=self.rightRoatate(node.right)
                    return self.leftRotate(node)
            return node

        self.root=__insert(self.root,x)
    def hp(self): # for hieght printing
        tmp=self.root
        def __hp(tmp):
            if(tmp==None):
                return
            __hp(tmp.left )
            print("key",tmp.data,":height",tmp.height)
            __hp(tmp.right)
        __hp(tmp)
avl=AVL()
for i in range(2000):
    avl.insert((i))
avl.hp()