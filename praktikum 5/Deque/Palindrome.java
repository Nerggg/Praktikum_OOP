public class Palindrome<T> {
    public boolean isPalindrome(Deque<T> dq) {
        try {
            Deque<T> temp = new Deque<>(dq);

            while (temp.size() > 1) {
                T front = temp.popFront();
                T back = temp.popBack();

                if (!front.equals(back)) {
                    return false;
                }
            }

            return true;

        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
}