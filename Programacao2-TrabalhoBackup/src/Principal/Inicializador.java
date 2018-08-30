/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Principal;

import ClasseBackup.Backup;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
/**
 *
 * @author dionm
 */
public class Inicializador {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        InputStream fis = new FileInputStream("C:/Users/dionm/Downloads/Faculdade/4P/Programação/TrabalhoM1/5Mb.txt");
        
        OutputStream fos = new FileOutputStream("Teste.txt");
        
        Backup aaa = new Backup();
        
        double tempo = aaa.fazerBackup(fis, fos);
        
        System.out.println(tempo);
    }
}
