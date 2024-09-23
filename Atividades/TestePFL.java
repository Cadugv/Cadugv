public class TestePFL {

    public static void main(String args[]) {

        pilhaDin P = new pilhaDin();
        FilaDin F = new FilaDin();
        ListaOrd L = new ListaOrd();

        // Enfileira e empilha elementos
        for (int i = 3; i < 8; i += 3) {
            F.enqueue(i + 1);  // Fila recebe i+1
            P.push(i - 1);     // Pilha recebe i-1
        }

        // Transfere elementos da fila para a lista ordenada
        while (!F.qIsEmpty()) {
            L.ins(F.dequeue());
        }

        // Transfere elementos da pilha para a lista ordenada
        while (!P.isEmpty()) {
            L.ins(P.pop());
        }

        // Imprime a lista ordenada
        L.print();
    }
}

