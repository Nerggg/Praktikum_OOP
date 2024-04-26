import java.util.*;
import java.util.stream.*;

public class GameKata {
  public static void run(String[] tito, String[] wiwid) {
    Map<String, Integer> exists = new HashMap<>();

    Stream<String> titoStream = Arrays.stream(tito);
    titoStream.forEach(x -> exists.put(x,1));
    
    Stream<String> wiwidStream = Arrays.stream(wiwid);
    wiwidStream.filter(exists::containsKey).distinct().forEach(System.out::println);
  }
}
