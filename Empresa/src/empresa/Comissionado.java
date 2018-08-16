package empresa;

public class Comissionado extends Funcionario {

    public double salario;
    private final double valorBase;
    private final double comissao;

    public Comissionado(double valorBase, double comissao, double salario) {
        this.valorBase = valorBase;
        this.comissao = comissao;
        this.salario = salario;
    }

    @Override
    public double receberSalario() {
        this.salario += this.valorBase;
        this.salario += this.comissao;
        return this.salario;
    }

    @Override
    public double calcularDespesas() {
        return receberSalario();
    }
}
