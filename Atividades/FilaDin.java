import java.util.LinkedList;
import java.util.Queue;

public class FilaDin {
    private Queue<Integer> queue;

    public FilaDin() {
        queue = new LinkedList<>();
    }

    public void enqueue(int value) {
        queue.offer(value);
    }

    public int dequeue() {
        return queue.poll();
    }

    public boolean qIsEmpty() {
        return queue.isEmpty();
    }
}




