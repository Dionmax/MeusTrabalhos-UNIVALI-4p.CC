package empresa;

public class Conta implements Despesa {

    final String nome;
    final double valor;

    public Conta(String nome, double valor) {
        this.nome = nome;
        this.valor = valor;
    }

    @Override
    public double calcularDespesas() {
        return valor;
    }
}
