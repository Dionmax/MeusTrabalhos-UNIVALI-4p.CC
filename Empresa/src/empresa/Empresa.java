package empresa;

import java.util.ArrayList;
import java.util.Collection;

public class Empresa {

    private Collection<Despesa> despesa = new ArrayList();

    public void adicionarDespesas(Despesa despesa) {
        this.despesa.add(despesa);
    }

    public double calcularDespesa() {
        double total = 0.0;

        total = despesa.stream().map((despesas) -> despesas.calcularDespesas()).reduce(total, (accumulator, _item) -> accumulator + _item);

        return total;
    }

}
