package linkedlist;

public class StringList {
	public Node head;
	
	public StringList() {
		head = null;
	}
	
	public void add(String data) {
		Node newNode = new Node(data);
		newNode.next = head;
		head = newNode;
	}
	
	@Override
	public String toString() {
		Node listNode = this.head;
 		String string = "";
		while(listNode != null) {
			string += listNode.data + " ";
			listNode = listNode.next;
		}
		return string;
	}
}