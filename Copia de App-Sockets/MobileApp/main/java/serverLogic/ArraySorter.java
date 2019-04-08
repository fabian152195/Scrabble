package serverLogic;

public class ArraySorter {




    //Codigo obtenido de: https://www.geeksforgeeks.org/bubble-sort/
    /** Funcion principal que ejecuta Bubblesort
     * @param arr Arreglo de datos
     */
    public int bubbleSort(int arr[])
    {
        int cont = 0;
        int n = arr.length;
        boolean flag = true;
        for (int i = 0; i < n-1 && flag == true; i++) {
            flag = false;
            for (int j = 0; j < n - i - 1; j++) {
                cont ++;
                if (arr[j] > arr[j + 1]) {
                    // swap temp and arr[i]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = true;
                }
            }
        }
        return cont;
    }

    //Codigo obtenido de: https://www.geeksforgeeks.org/quick-sort/
    /** Funcion principal que ejecuta Quicksort
     * @param arr Arreglo de datos
     * @param low numero menor a la izquierda del pivote
     * @param high numero mayor a la derecha del pivote
     */
    public int quicksort(int arr[], int low, int high)
    {
        int cont = 0;
        if (low < high)
        {
            /* pi is partitioning index, arr[pi] is
              now at right place */
            int[] array = partition(arr, low, high);
            int pi = array[0];
            cont = array[1];
            // Recursively sort elements before
            // partition and after partition
            cont += quicksort(arr, low, pi-1);
            cont += quicksort(arr, pi+1, high);
        }

        return cont;
    }

    //FUNCIONES SECUNDARIAS
    /** Toma como ultimo elemento como pivote,
     lo coloca en la posicion correcta de una
     manera ordenada, y coloca todos los numeros
     menores que el pivote a la izquierda y los
     mayores a la derecha
     * @param arr Arreglo por ordenar
     * @param low index del inicio
     * @param high index del final
     */
    private int[] partition(int arr[], int low, int high)
    {
        int cont = 0;
        int pivot = arr[high];
        int i = (low-1); // index of smaller element
        for (int j=low; j<high; j++)
        {
            cont++;
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;

                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap arr[i+1] and arr[high] (or pivot)
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        // set resultado
        int[] resultado = new int[2];
        resultado[0] = i+1;
        resultado[1] = cont;
        return resultado;
    }



    /** Imprime el arreglo
     * @param arr Arreglo a imprimir
     */
    public void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

}
