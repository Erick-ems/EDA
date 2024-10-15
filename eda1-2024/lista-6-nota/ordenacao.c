void ordena(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Encontra o índice do menor elemento no subvetor não ordenado
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento com o primeiro elemento não ordenado
        if (minIndex != i) {
            int temp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = temp;
        }
    }
}
