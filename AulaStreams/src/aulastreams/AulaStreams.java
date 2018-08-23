/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aulastreams;

import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;

/**
 *
 * @author dionm
 */
public class AulaStreams {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {

        //InputStream fis = new FileInputStream("dados.txt");
        URL link = new URL("https://www.univali.br/Paginas/default.aspx");

        InputStream fis = link.openStream();

        long tempoInicio = System.currentTimeMillis();

        OutputStream fos = new FileOutputStream("teste.txt");

        int byteLido = -1;
        do {
            byteLido = fis.read();

            if (byteLido >= 0) {
                fos.write(byteLido);
            }

            // System.out.print((char) byteLido);
        } while (byteLido != -1);

        long tempoFinal = System.currentTimeMillis();

        System.out.println(tempoFinal - tempoInicio);

        fos.close();
    }

}
