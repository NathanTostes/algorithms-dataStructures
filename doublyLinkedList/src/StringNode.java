public class StringNode {
    private StringNode next;
    private StringNode previous;
    private String value;

    public StringNode(String value) {
        this.value = value;
    }

    public StringNode getNext() {
        return next;
    }

    public StringNode getPrevious() {
        return previous;
    }

    public String getValue() {
        return value;
    }

    public void setNext(StringNode next) {
        this.next = next;
    }

    public void setPrevious(StringNode previous) {
        this.previous = previous;
    }
}
