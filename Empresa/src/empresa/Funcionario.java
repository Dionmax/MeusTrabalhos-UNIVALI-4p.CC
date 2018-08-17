package empresa;

public abstract class Funcionario implements Despesa {

    String endereco = "";
    String nome = "";
    double salario = 0;

    abstract double receberSalario();
}
