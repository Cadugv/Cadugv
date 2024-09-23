public class Fila {
    private int total; // Total de Elementos
    private int comeco; // Começo da Fila
    private int fim; // Final da Fila
    private Object[] memorando; // Vetor para armazenar os elementos
    private int MAX; // Tamanho máximo da Fila Estática

    // Inicializa a Fila em estado vazio
    public Fila() {
        MAX = 1000;
        memorando = new Object[MAX];
        total = 0;
        comeco = 0;
        fim = 0;
    }

    // Verifica se a Fila está vazia
    public boolean qIsEmpty() {
        return (total == 0);
    }

    // Verifica se a Fila está cheia
    private boolean qIsFull() {
        return (total == MAX);
    }

    // Insere um elemento na Fila
    public void enqueue(Object x) {
        if (!qIsFull()) {
            memorando[fim++] = x;
            fim %= MAX;
            total++;
        } else {
            System.out.println("Fila Cheia!!");
        }
    }

    // Remove um elemento do início da Fila
    public Object dequeue() {
        if (!qIsEmpty()) {
            Object resp;
            resp = memorando[comeco++];
            comeco %= MAX;
            total--;
            return resp;
        } else {
            return null;
        }
    }

    // Imprime o conteúdo da Fila
    public void qPrint() {
        if (!qIsEmpty()) {
            String saida = "";
            int cont = comeco;
            for (int i = 0; i < total; i++) {
                saida += memorando[cont].toString() + ", ";
                cont++;
                cont %= MAX;
            }

            System.out.println("F:[ " + saida + " ]");
        } else {
            System.out.println("Fila Vazia");
        }
    }

    // Método principal (main) para executar o programa
    public static void main(String[] args) {
        // Criando uma fila
        Fila fila = new Fila();
        
        // Enfileirando alguns elementos
        fila.enqueue("Elemento 1");
        fila.enqueue("Elemento 2");
        fila.enqueue("Elemento 3");
        
        // Imprimindo a fila
        fila.qPrint();
        
        // Desenfileirando um elemento
        System.out.println("Desenfileirado: " + fila.dequeue());
        
        // Imprimindo a fila novamente
        fila.qPrint();
    }
}


