/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Principal;

import empresa.*;

/**
 *
 * @author dionm
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Empresa empresa = new Empresa();

        Funcionario prestador1 = new Assalariado(2.2, 2.0);

        empresa.adicionarDespesas(prestador1);
        empresa.adicionarDespesas(new Comissionado(2.3, 20.9, 3.0));
        
        System.out.println(empresa.calcularDespesa());
        
    }

}
