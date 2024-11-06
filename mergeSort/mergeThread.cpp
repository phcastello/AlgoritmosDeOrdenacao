#include <bits/stdc++.h>
#define nl std::cout<<"\n";


void merge(std::vector<int> &vetor, int inicio, int meio, int fim) {
    std::vector<int> temp(fim - inicio + 1);
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    while (i <= meio){
        temp[k++] = vetor[i++];
    }

    while (j <= fim){
        temp[k++] = vetor[j++];
    }

    for (int i = inicio; i <= fim; ++i) {
        vetor[i] = temp[i - inicio];
    }
}

void mergeParalelo(std::vector<int> &vetor, int inicio, int fim, int profundidade = 0) {
    if (inicio >= fim) return;

    int meio = inicio + (fim - inicio) / 2;

    if (profundidade <= 3){
        std::thread left(mergeParalelo, std::ref(vetor), inicio, meio, profundidade + 1);
        std::thread right(mergeParalelo, std::ref(vetor), meio + 1, fim, profundidade + 1);

        left.join();
        right.join();
    } else {
        mergeParalelo(vetor, inicio, meio, profundidade + 1);
        mergeParalelo(vetor, meio + 1, fim, profundidade + 1);
    }

    merge(vetor, inicio, meio, fim);
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

int main() {
    std::string arquivoLeitura = "contagem100k.txt";

    std::string diretorio = "arquivosSaidas/";
    std::string nomeBase = "contagemT";
    std::string extensaoArquivo = ".txt";
    int contagem = 0;

    if(!std::filesystem::exists(diretorio)){
        std::cout << "criando diretorio " << diretorio;nl
        std::filesystem::create_directories(diretorio);

    }

    while(std::filesystem::exists(diretorio + nomeBase + std::to_string(contagem) + extensaoArquivo)){
        contagem++;
    }

    std::string arquivoSaida = diretorio + nomeBase + std::to_string(contagem) + extensaoArquivo;

    std::vector<int> vetor = lerArquivo(arquivoLeitura);

    if (vetor.empty()) {
        std::cerr << "Arquivo vazio ou erro na leitura.";nl
        return 1;
    }

    auto inicio = std::chrono::high_resolution_clock::now();

    mergeParalelo(vetor, 0, vetor.size() - 1);

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    double duracaoMicro = duracao.count();
    double duracaoSegundos = duracaoMicro / 1e6;

    std::cout << "duração microsegundos: " << duracao.count();nl
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "duração segundos: " << duracaoSegundos;nl

    escreverArquivo(arquivoSaida, vetor);
    std::cout << "Vetor ordenado salvo em " << arquivoSaida;nl

    return 0;
}