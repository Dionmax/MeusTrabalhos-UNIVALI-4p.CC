/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ClasseBackup;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 *
 * @author dionm
 */
public class Backup {

    long tempoInicio,
            tempoFinal;

    public double fazerBackup(InputStream fis, OutputStream fos) throws IOException {

        try {
            int byteLido = -1;
            
            tempoInicio = System.currentTimeMillis();
            do {
                byteLido = fis.read();

                if (byteLido >= 0) {
                    fos.write(byteLido);
                }

            } while (byteLido != -1);

            tempoFinal = System.currentTimeMillis();

        } catch (Exception e) {
        }

        fos.close();
        
        return tempoFinal - tempoInicio;
    }
}
