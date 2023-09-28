// Escreva a documentação correta da função abaixo.


///1.1.1
// esta função recebe um tamanho n e um vetor v
// soma os elementos do vetor e retorna em x
int soma (int n, int v[]) {
int i, x = 0;
for (i = 0; i < n; i++) x += v[i];
return x; }

//1.1.2
// recebe 3 valores, tamanho do vetor, elemento inteiro
// vai contar o numero de elementos de um vetor
int onde (int x, int v[], int n) {
int j = 0;
while (j < n && v[j] != x) j += 1;
return j; 

