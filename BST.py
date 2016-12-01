class Node:
    def __init__(self,x):
        self.data=x
        self.right=None
        self.left=None
class binaryTree:
    def __init__(self):
        self.root=None
    def add(self,x):
        def ADD(tmp,x):
            if(tmp==None):
                tmp=Node(x)
                return tmp
            if(x>tmp.data):
                tmp.right=ADD(tmp.right,x)
                return tmp
            else:
                tmp.left=ADD(tmp.left,x)
                return tmp
        self.root=ADD(self.root,x)
    def Traverse(self):
        tmp=self.root
        def traverse(tmp):
            if(tmp==None):
                return
            traverse(tmp.left)
            print(tmp.data)
            traverse(tmp.right)
        traverse(tmp)
    def delete(self,x):
        def HDelete(node,x):
            if(node==None):
                return None
            elif(node.data==x):
                if(node.left==None and node.right==None):
                    del node
                    return None
                elif(node.left!=None):
                    x=node.left
                    del node
                    return x
                elif(node.right!=None):
                    x=node.right
                    del node
                    return x
                else:
                    succ=node.right
                    while(succ.left!=None):
                        succ=succ.left
                    node.data=succ.data
                    del succ
                    return node
            elif(node.data<x):
                node=HDelete(node.right,x)
                return node
            else:
                node=HDelete(node.left,x)
                return node
        self.root=HDelete(self.root,x)
    def search(self,x):
        tmp=self.root
        def BSearch(tmp,x):
            if(tmp==None):
                return False
            elif(tmp.data==x):
                return True
            elif(tmp.data<x):
                return BSearch(tmp.right,x)
            else:
                return BSearch(tmp.left,x)
        return BSearch(tmp,x)
bt=binaryTree()
import random as rdm
for i in range(10000):
    x=rdm.randrange(-100000000,100000000)
    bt.add(x)
    if not bt.search(x):
        print("Bad implemetation")
        break
#bt.Traverse()
for i in range(10000):
    x=rdm.randrange(-100000000,100000000)
    bt.delete(x)
    if bt.search(x):
        print("Bad implemetation")
        break

print("good implemetation!")
