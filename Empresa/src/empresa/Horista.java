package empresa;

class Horista extends Funcionario {

    private final double horas;
    private final int horaValor;
    public double salario;

    public Horista(int horas, int horaValor, double salario) {
        this.horas = horas;
        this.horaValor = horaValor;
        this.salario = salario;
    }

    @Override
    public double receberSalario() {
        return this.salario += (this.horas * this.horaValor);
    }

    @Override
    public double calcularDespesas() {
        return receberSalario();
    }
}
