public class DoublyLinkedList {
    private StringNode head;
    private StringNode tail;

    public DoublyLinkedList() {
        head = null;
        tail = null;
    }

    public void add(String value) {
        StringNode newNode = new StringNode(value);
        if (head == null) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail.setNext(newNode);
        newNode.setPrevious(tail);
        tail = newNode;
    }

    public void remove() {
        try {
            StringNode newTail = tail.getPrevious();
            newTail.setNext(null);
            tail = newTail;
        } catch (NullPointerException e) {
        }
    }

    public void printAllElementsFromHead() {
        StringNode currentNode = head;
        do {
            System.out.println(currentNode.getValue());
        } while ((currentNode = currentNode.getNext()) != null);
    }

    public void printAllElementsFromTail() {
        StringNode currentNode = tail;
        do {
            System.out.println(currentNode.getValue());
        } while ((currentNode = currentNode.getPrevious()) != null);
    }
}
