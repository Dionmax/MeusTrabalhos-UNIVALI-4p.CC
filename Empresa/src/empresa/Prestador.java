package empresa;

public class Prestador implements Despesa {

    final String nome;
    final double valor;

    public Prestador(String nome, double valor) {
        this.valor = valor;
        this.nome = nome;
    }

    @Override
    public double calcularDespesas() {
        return valor;
    }
}
