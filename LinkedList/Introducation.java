class Node {
    int data;
    Node next;

    Node(int data1, Node next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = null;
    }
};

public class Introducation {

    public static void main(String[] args) {

        Node y = new Node(3, null);
        System.err.println(y.data);
    }
};