#include<bits/stdc++.h>
#define nl std::cout<<"\n";

int buscaBinaria(std::vector<int> &array, int baixo, int alto, int elementoInserir){
    while (baixo <= alto) {
        int medio = baixo + (alto - baixo) / 2;

        if (array[medio] == elementoInserir)
            return medio;

        if (array[medio] < elementoInserir)
            baixo = medio + 1;

        else
            alto = medio - 1;
    }

    return baixo;
}

void insertionSort(std::vector<int> &array) {
    for (long long i = 1; i < array.size(); i++) {
        int chave = array[i];
        int j = i - 1;

        long novaPosicao = buscaBinaria(array, 0, j, chave);

        while (j >= novaPosicao) {
            array[j + 1] = array[j];
            j--;
        }
        array[novaPosicao] = chave;
    }
}

std::vector<int> lerArquivo(const std::string &nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::vector<int> vetor;
    int numero;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo;nl
        return vetor;
    }

    while (arquivo >> numero) {
        vetor.push_back(numero);
    }

    arquivo.close();
    return vetor;
}

void escreverArquivo(const std::string& nomeArquivo, const std::vector<int> &vetor) {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo;nl
        return;
    }

    for (int num: vetor) {
        arquivo << num << " ";
    }

    arquivo.close();
}

int main(){
    std::string arquivoLeitura = "aleatorio100k.txt";
    std::string arquivoSaida = "insertionOutput.txt";

    std::vector<int> vetor = lerArquivo(arquivoLeitura);

    if (vetor.empty()) {
        std::cerr << "Arquivo vazio ou erro na leitura.";nl
        return 1;
    }

    auto inicio = std::chrono::high_resolution_clock::now();

    insertionSort(vetor);

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    double duracaoMicro = duracao.count();
    double duracaoSegundos = duracaoMicro / 1e6;

    std::cout << "duracao microsegundos: " << duracao.count();nl
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "duracao segundos: " << duracaoSegundos;nl

    escreverArquivo(arquivoSaida, vetor);
    std::cout << "Arquivo usado para ordenar: " << arquivoLeitura;nl
    std::cout << "Vetor ordenado salvo em: " << arquivoSaida;nl
}