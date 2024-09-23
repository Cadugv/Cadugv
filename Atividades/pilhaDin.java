import java.util.Stack;

public class pilhaDin {
    private Stack<Integer> stack;

    public pilhaDin() {
        stack = new Stack<>();
    }

    public void push(int value) {
        stack.push(value);
    }

    public int pop() {
        return stack.pop();
    }

    public boolean isEmpty() {
        return stack.isEmpty();
    }
}


