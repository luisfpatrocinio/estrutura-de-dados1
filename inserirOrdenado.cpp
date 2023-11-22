#include <iostream>
using namespace std;

const int MAX_ALUNOS = 30;

struct Aluno {
    int mat;
    string nome;
};

Aluno lista[MAX_ALUNOS];
int tamanho = 0;  // Tamanho atual da lista

// Funcao para incluir um aluno desordenado na lista
void incluirDesordenado(Aluno e) {
    if (tamanho < MAX_ALUNOS) {
        lista[tamanho] = e;
        tamanho++;
        cout << "Aluno incluido com sucesso!" << endl;
    } else {
        cout << "A lista está cheia. Não é possível incluir mais alunos." << endl;
    }
}

// Função para incluir um aluno ordenado na lista
void incluirOrdenado(Aluno e){
    // Checa se a lista já tá lotada.
	if (tamanho > MAX_ALUNOS){
		cout << "A lista está cheia. Não é possível incluir mais alunos."<< endl;
	} else {
		int aux = 0;
		// Se a lista tiver vazia, adicionar o primeiro item.
		if (tamanho == 0){
			lista[aux] = e;
			tamanho++;
		} else {
		    // Percorre a lista até encontrar o primeiro item maior que o que será adicionado.
            while ((aux<tamanho) && (lista[aux].mat<e.mat)) { 
				aux++;				
			}			
			// No final do while teremos aux = índice onde o novo item vai ficar.
			for (int i = tamanho; i > aux; i--) {
			    lista[i] = lista[i - 1];
			}
			lista[aux] = e;
			tamanho++;
		}	
    }  
}
	
	
// Função para procurar um aluno pelo número de matrícula e retornar sua posição.
int procura(int mat) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i].mat == mat) {
            return i;  // Retorna a posição do aluno.
        }
    }
    return -1;  // Retorna -1 se o aluno não for encontrado.
}

// Função para mostrar os dados de um aluno na tela
void mostrar(int pos) {
    if (pos >= 0 && pos < tamanho) {
        cout << "Matrícula: " << lista[pos].mat << ", Nome: " << lista[pos].nome << endl;
    } else {
        cout << "Posição inválida." << endl;
    }
}

// Função para mostrar todos os alunos da lista
void mostra() {
    cout << "Lista de Alunos:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "Matrícula: " << lista[i].mat << ", Nome: " << lista[i].nome << endl;
    }
}

// Estratégia 1: Remover um aluno substituindo-o pelo último aluno da lista
void remover00(int mat) {
    int pos = procura(mat);
    if (pos != -1) {
        lista[pos] = lista[tamanho - 1];  // Substitui o aluno pelo último da lista
        tamanho--;
        cout << "Aluno removido com sucesso!" << endl;
    } else {
        cout << "Aluno não encontrado." << endl;
    }
}

void remover01(int mat){
	int pos = procura(mat);
	if (pos==-1){
		cout<< "Aluno nao encontrado!!"<<endl;
	}
	else{
		int i=0;
		while (i<(tamanho-1)){
			lista[i]=lista[i+1];
			i++;			
		}
		tamanho--;
		
	}
	
	
}

int main() {
    Aluno novo;
    novo.mat=10;
    novo.nome="maria";
    incluirOrdenado(novo);
    
    novo.mat=5;
    novo.nome="katia";
    incluirOrdenado(novo);
    
    novo.mat=7;
    novo.nome="ana";
    incluirOrdenado(novo);

    novo.mat = 6;
    novo.nome = "luis";
    incluirOrdenado(novo);
    mostra();
}

