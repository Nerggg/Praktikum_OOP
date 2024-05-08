import java.util.ArrayList;
import java.util.List;

public class Deque<T> {

    private List<T> data;

    private int lastElmIdx, size;

    private final static int DEFAULT_Deque_SIZE = 500;

    public Deque() {
        this(DEFAULT_Deque_SIZE);
    }

    public Deque(int n) {
        data = new ArrayList<T>(n);
        lastElmIdx = -1;
        size = n;
    }

    public Deque(final Deque<T> q) {
        data = new ArrayList<T>(q.data);
        lastElmIdx = q.lastElmIdx;
        size = q.size;
    }

    public void pushFront(T t) throws Exception {
        if (isFull()) {
            throw new Exception("Deque is full");
        }
        data.add(0, t);
        lastElmIdx++;
    }

    public void pushBack(T t) throws Exception {
        if (isFull()) {
            throw new Exception("Deque is full");
        }
        data.add(t);
        lastElmIdx++;
    }

    public T popFront() throws Exception {
        if (isEmpty()) {
            throw new Exception("Deque is empty");
        }
        T t = data.get(0);
        data.remove(0);
        lastElmIdx--;
        return t;
    }

    public T popBack() throws Exception {
        if (isEmpty()) {
            throw new Exception("Deque is empty");
        }
        T t = data.get(lastElmIdx);
        data.remove(lastElmIdx);
        lastElmIdx--;
        return t;
    }

    public void reverse() {
        List<T> temp = new ArrayList<T>(data);
        for (int i = 0; i <= lastElmIdx; i++) {
            data.set(i, temp.get(lastElmIdx - i));
        }
    }

    public boolean isEmpty() {
        return lastElmIdx == -1;
    }

    public boolean isFull() {
        return lastElmIdx == size - 1;
    }

    public int size() {
        return lastElmIdx + 1;
    }
}