#include <iostream>

using namespace std;

class No{

private:
    int conteudo;
    No* prox;

public:
    No() : conteudo(0), prox(nullptr){}

    int getConteudo(){
        return conteudo;
    }

    void setConteudo(int valor){
        conteudo = valor;
    }

    No* getProx(){
        return prox;
    }

    void setProx(No* proximo){
        prox = proximo;
    }
};

class ListaEnc {

private:
    No* cabeca;
    int tamanho;

public:
    ListaEnc() : cabeca(nullptr), tamanho(0) {}

    bool vazio(){
        return tamanho == 0;
    }

    int tamanhoLista(){
        return tamanho;
    }

    int elemento(int pos){
        if(vazio() || pos < 1 || pos > tamanho){
            return -1;
        }

        No* aux = cabeca;
        int cont = 1;
        while(cont < pos){
            aux = aux->getProx();
            cont++;
        }

        return aux->getConteudo();
    }

    int posicao(int dado){
        if(vazio()){
            return -1;
        }

        No* aux = cabeca;
        int cont = 1;
        while(aux != nullptr){
            if(aux->getConteudo() == dado){
                return cont;
            }

            aux = aux->getProx();
            cont++;
        }

        return -1;
    }

    bool insere(int pos, int dado){
        if(pos < 1 || pos > tamanho + 1){
            return false;
        }

        if(pos == 1){
            return insereInicioLista(dado);
        }else if(pos == tamanho + 1){
            return insereFimLista(dado);
        }else{
            return insereMeioLista(pos, dado);
        }
    }

    bool insereInicioLista(int valor){
        No* novoNo = new No();
        novoNo->setConteudo(valor);
        novoNo->setProx(cabeca);
        cabeca = novoNo;
        tamanho++;
        return true;
    }

    bool insereMeioLista(int pos, int dado){
        if(pos < 1 || pos > tamanho + 1){
            return false;
        }

        No* novoNo = new No();
        novoNo->setConteudo(dado);

        No* aux = cabeca;
        int cont = 1;
        while(cont < pos - 1){
            aux = aux->getProx();
            cont++;
        }

        novoNo->setProx(aux->getProx());
        aux->setProx(novoNo);
        tamanho++;
        return true;
    }

    bool insereFimLista(int dado){
        No* novoNo = new No();
        novoNo->setConteudo(dado);

        if(vazio()){
            cabeca = novoNo;
        }else{
            No* aux = cabeca;
            while(aux->getProx() != nullptr){
                aux = aux->getProx();
            }

            aux->setProx(novoNo);
        }

        tamanho++;
        return true;
    }

    int remove(int pos){
        if(vazio() || pos < 1 || pos > tamanho){
            return -1;
        }

        if(pos == 1){
            return removeInicioLista();
        }else{
            return removeNaLista(pos);
        }
    }

    int removeInicioLista(){
        No* p = cabeca;
        int dado = p->getConteudo();
        cabeca = p->getProx();
        delete p;
        tamanho--;
        return dado;
    }

    int removeNaLista(int pos){
        No* aux = cabeca;
        No* antecessor = nullptr;
        int cont = 1;

        while(cont < pos){
            antecessor = aux;
            aux = aux->getProx();
            cont++;
        }

        int dado = aux->getConteudo();
        antecessor->setProx(aux->getProx());
        delete aux;
        tamanho--;
        return dado;
    }
};

int main(void){
    ListaEnc lista;

    cout << "---------- LISTA SIMPLESMENTE ENCADEADA ----------" << endl;

    // VERIFICANDO SE ESTÁ CHEIA OU VAZIA
    if(lista.vazio()){
        cout << "\nA lista esta vazia." << endl;
    }else{
        cout << "\nA lista esta cheia." << endl;
    }

    // INSERINDO ELEMENTOS NAS POSIÇÕES
    lista.insere(1, 4);
    lista.insere(2, 10);
    lista.insere(3, 13);
    lista.insere(4, 17);
    lista.insere(5, 22);

    // EXIBINDO OS ELEMENTOS
    cout << "\nElemento na posicao 1: " << lista.elemento(1) << endl;
    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;
    cout << "Elemento na posicao 3: " << lista.elemento(3) << endl;
    cout << "Elemento na posicao 4: " << lista.elemento(4) << endl;
    cout << "Elemento na posicao 5: " << lista.elemento(5) << endl;

    // VERIFICANDO SE A LISTA ESTÁ CHEIA OU VAZIA
    if(lista.vazio()){
        cout << "\nA lista esta vazia." << endl;
    }else{
        cout << "\nA lista esta cheia." << endl;
    }

    // VERIFICANDO O TAMANHO DA LISTA
    cout << "\nTamanho da lista: " << lista.tamanhoLista() << endl;


    // REMOVENDO UM ELEMENTO DA LISTA
    cout << "\nRemovendo elemento da posicao 1: " << lista.remove(1) << endl;

    // TODOS OS ELEMENTOS QUE FICARAM VAO MOVER PARA A ESQUERDA DA LISTA TOMANDO O ESPAÇO DO ELEMENTO REMOVIDO
    // A ÚLTIMA POSIÇÃO VAI MOSTRAR VALOR -1 PORQUE ESTÁ VAZIA
    cout << "\nElemento na posicao 1: " << lista.elemento(1) << endl;
    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;
    cout << "Elemento na posicao 3: " << lista.elemento(3) << endl;
    cout << "Elemento na posicao 4: " << lista.elemento(4) << endl;
    cout << "Elemento na posicao 5: " << lista.elemento(5) << " (espaco vazio = -1)" << endl;

    //INSERINDO UM NOVO ELEMENTO NO MEIO
    lista.insere(4, 20);

    // EXIBINDO TODA A LISTA NOVAMENTE
    cout << "\nElemento na posicao 1: " << lista.elemento(1) << endl;
    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;
    cout << "Elemento na posicao 3: " << lista.elemento(3) << endl;
    cout << "Elemento na posicao 4: " << lista.elemento(4) << endl;
    cout << "Elemento na posicao 5: " << lista.elemento(5) << endl;

    return 0;
}
