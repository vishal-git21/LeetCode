import java.util.Stack;
import java.util.HashSet;

public class RemoveDuplicatesFromStack {
    private Stack<Integer> stack;

    public RemoveDuplicatesFromStack() {
        stack = new Stack<>();
    }

    public void push(int element) {
        stack.push(element);
    }

    public void remove_Duplicates() {
        HashSet<Integer> uniqueElements = new HashSet<>();
        Stack<Integer> tempStack = new Stack<>();
        while (!stack.isEmpty()) {
            int currentElement = stack.pop();
            if (uniqueElements.add(currentElement)) {
                tempStack.push(currentElement);
            }
        }
        while (!tempStack.isEmpty()) {
            stack.push(tempStack.pop());
        }
    }

    public void printStack() {
        System.out.println("Stack elements after removing duplicates: " + stack);
    }

    public static void main(String[] args) {
        RemoveDuplicatesFromStack stackWithDuplicates = new RemoveDuplicatesFromStack();
        stackWithDuplicates.push(5);
        stackWithDuplicates.push(2);
        stackWithDuplicates.push(8);
        stackWithDuplicates.push(2);
        stackWithDuplicates.push(5);
        stackWithDuplicates.push(1);
        System.out.println("Stack elements before removing duplicates: " +
                stackWithDuplicates.stack);
        stackWithDuplicates.remove_Duplicates();
        stackWithDuplicates.printStack();
    }
}
