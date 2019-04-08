package serverLogic;

import java.lang.reflect.Array;
import java.util.Random;
import java.util.Random;

public class ArrayGenerator {

    private static Random numRandom;
    private static int topNumber;

    /**
     * Constuctor principal
     */
    public ArrayGenerator(){
        numRandom = new Random();
        topNumber = 100;
    }

    /**
     * Constuctor con parametro de entrada
     * @param topNumber Indica el tope al que pueden llegar los numeros random, desde 0 hasta este numero
     */
    public ArrayGenerator(int topNumber){
        numRandom = new Random();
        this.topNumber = topNumber;
    }

    /**
     * Funcion encargada de generar arreglos con numeros random del 1 al
     * @param largo
     * @return
     */
    public static int[] generateArray(int largo){

        int[] array = new int[largo];
        int cont = 0;

        while (cont<largo){

            array[cont] = numRandom.nextInt(topNumber+1);
            cont++;

        }
        return array;
    }


    //SETTER & GETTER

    public static int getTopNumber() {
        return topNumber;
    }

    public static void setTopNumber(int topNumber) {
        ArrayGenerator.topNumber = topNumber;
    }

}
