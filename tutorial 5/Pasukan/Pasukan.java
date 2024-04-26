import java.util.*;

public class Pasukan {
    private List<Integer> list;
    private int n;

    public Pasukan(List<Integer> list, int n) {
        this.list = list;
        this.n = n;
    }

    public void reset() {
        list.clear();
        for (int i = 0; i < n; i++) {
            list.add(0);
        }
    }

    public long get(int idx) {
        reset();
        long begin = Util.getTime();
        list.get(idx);
        long end = Util.getTime();
        return end-begin;
    }
    
    public long del(int idx, int t) {
        reset();
        long begin = Util.getTime();
        for (int i = 0; i < t; i++) {
            list.remove(idx);
        }
        long end = Util.getTime();
        return end-begin;
    }
}