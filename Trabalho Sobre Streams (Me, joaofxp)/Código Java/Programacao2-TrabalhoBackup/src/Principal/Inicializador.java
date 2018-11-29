/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Principal;

import ClasseBackup.Backup;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
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
        InputStream fis = new BufferedInputStream(new FileInputStream("C:/Users/dionm/Downloads/Faculdade/4P/Programação/TrabalhoM1/50Mb"));
        
        OutputStream fos = new FileOutputStream("C:/Users/dionm/Downloads/Faculdade/4P/Programação/TrabalhoM1/AquivosPosBackup/TesteBuffer50Mb5.txt");
        
        BufferedOutputStream bos = new BufferedOutputStream(fos);
        
        Backup Streams = new Backup();
        
        double tempo = Streams.fazerBackup(fis, bos);
        
        System.out.println(tempo);
    }
}
