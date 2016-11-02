class Node{
	int data;
	Node next;
	Node(int x){
		data=x;
		next=null;
	}
}
class List{
	Node root;
	List(){
		root=null;
	}
	void add(int x){
		if(root!=null){
			Node tmp=root;
			while(tmp.next!=root){
				tmp=tmp.next;
			}
			tmp.next=new Node(x);
			tmp.next.next=root;
			//System.out.println("added: "+tmp.next.data);
		}
		else{
			root=new Node(x);
			root.next=root;
			//System.out.println("added: "+root.data);
		}
	}
	void traverse(){
		if(root==null) return ;
		Node tmp=root;
		do{
			System.out.println(tmp.data);
			tmp=tmp.next;
		}while(tmp!=root);
	}
	boolean search(int key){
		Node tmp=root;
		if(root==null) return false;
		do{
			if(tmp.data==key) return true;
			tmp=tmp.next;
		}while(tmp!=root);
		return false;
	}
	void del(int key){
		if(root==null) return;
		Node tmp=root;
		boolean f=true;
		do{
			if(key==tmp.data) {
				f=false;
				break;
			}
			tmp=tmp.next;
		}while(tmp!=root);
		if(f) return;
		Node foo=tmp;
		while(foo.next!=tmp) foo=foo.next;
		foo.next=tmp.next;
		root=foo;
	}
}
public class circularLinkedList {
	public static void main(String str[]){
		List l=new List();
		for(int i=0;i<11;i++) l.add(i*10);
		l.traverse();
		System.out.println(l.search(100));
		System.out.println(l.search(400));
		l.del(100);
		l.add(55);
		System.out.println(l.search(55));
		System.out.println(l.search(400));
		l.traverse();
		l.del(55);
		l.traverse();
	}
}
