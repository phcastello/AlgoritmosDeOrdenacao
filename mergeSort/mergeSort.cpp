#include<bits/stdc++.h>
#define nl std::cout<<"\n";

void merge(std::vector<int> &array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftarray(n1), rightarray(n2);

    // Copia dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        leftarray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightarray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftarray[i] <= rightarray[j]) {
            array[k] = leftarray[i];
            i++;
        } else {
            array[k] = rightarray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftarray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightarray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(array, left, mid, right);
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
    std::string arquivoSaida = "mergeOutput.txt";

    std::vector<int> vetor = lerArquivo(arquivoLeitura);

    if (vetor.empty()) {
        std::cerr << "Arquivo vazio ou erro na leitura.";nl
        return 1;
    }


    auto inicio = std::chrono::high_resolution_clock::now();

    mergeSort(vetor, 0, vetor.size()-1);

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