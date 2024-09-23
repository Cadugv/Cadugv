import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ListaOrd {
    private List<Integer> list;

    public ListaOrd() {
        list = new ArrayList<>();
    }

    public void ins(int value) {
        list.add(value);
        Collections.sort(list);
    }

    public void print() {
        System.out.println("Lista: " + list);
    }
}


