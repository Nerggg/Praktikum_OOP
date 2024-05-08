import java.util.ArrayList;
import java.util.List;

public class Stack<T> {

    private List<T> data;

    private int lastElmIdx, size;

    private final static int DEFAULT_STACK_SIZE = 500;

    public Stack() {
        this(DEFAULT_STACK_SIZE);
    }

    public Stack(int n) {
        data = new ArrayList<T>(n);
        lastElmIdx = -1;
        size = n;
    }

    public Stack(final Stack<T> q) {
        data = new ArrayList<T>(q.data);
        lastElmIdx = q.lastElmIdx;
        size = q.size;
    }

    public void push(T t) throws Exception {
        if (isFull()) {
            throw new Exception("Stack is full");
        }
        data.add(t);
        lastElmIdx++;
    }

    public T pop() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack is empty");
        }
        T t = data.get(lastElmIdx);
        data.remove(lastElmIdx);
        lastElmIdx--;
        return t;
    }

    public boolean isEmpty() {
        return lastElmIdx == -1;
    }

    public boolean isFull() {
        return lastElmIdx == size - 1;
    }
}