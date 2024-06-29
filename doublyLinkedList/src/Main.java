public class Main {
    public static void main(String[] args) {
        DoublyLinkedList doublyLinkedList = new DoublyLinkedList();
        doublyLinkedList.add("Nathan");
        doublyLinkedList.add("Ash");
        doublyLinkedList.add("Bob");
        doublyLinkedList.add("Steve");
        doublyLinkedList.add("Light Yagami");

        doublyLinkedList.printAllElementsFromHead();
        System.out.println("----------------");
        doublyLinkedList.printAllElementsFromTail();
    }
}
