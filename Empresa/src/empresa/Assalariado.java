package empresa;

public class Assalariado extends Funcionario {

    private final double salarioBase;
    public double salario;

    public Assalariado(double salario, double salarioBase) {
        this.salarioBase = salarioBase;
        this.salario = salario;
    }

    @Override
    double receberSalario() {
        return salario;
    }

    @Override
    public double calcularDespesas() {
        return salario;
    }
}
