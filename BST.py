class Node:
    def __init__(self,x):
        self.data=x
        self.right=None
        self.left=None
class binaryTree:
    def __init__(self):
        self.root=None
    def add(self,x):
        self.root=self.ADD(self.root,x)
    def ADD(self,tmp,x):
        if(tmp==None):
            tmp=Node(x)
            return tmp
        if(x>tmp.data):
            tmp.right=self.ADD(tmp.right,x)
            return tmp
        else:
            tmp.left=self.ADD(tmp.left,x)
            return tmp
    def Traverse(self):
        tmp=self.root
        self.traverse(tmp)
    def traverse(self,tmp):
        if(tmp==None):
            return
        self.traverse(tmp.left)
        print(tmp.data)
        self.traverse(tmp.right)
    def delete(self,x):
        self.root=self.HDelete(self.root,x)
    def HDelete(self,node,x):
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
            node=self.HDelete(node.right,x)
            return node
        else:
            node=self.HDelete(node.left,x)
            return node

    def search(self,x):
        tmp=self.root
        return self.BSearch(tmp,x)
    def BSearch(self,tmp,x):
        if(tmp==None):
            return False
        elif(tmp.data==x):
            return True
        elif(tmp.data<x):
            return self.BSearch(tmp.right,x)
        else:
            return self.BSearch(tmp.left,x)



bt=binaryTree()
import random as rdm
for i in range(1000):
    x=rdm.randrange(-10000,10000)
    bt.add(x)
    if not bt.search(x):
        print("Bad implemetation")
bt.Traverse()

print("good implemetation!")