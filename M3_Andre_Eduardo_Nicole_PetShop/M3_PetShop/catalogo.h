#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "listaprodutos.h"

class Catalogo : ListaProdutos
{
public:
    Catalogo(); // Construtor
    Catalogo(vector<Servico> ls, vector<Produto> lp); // Construtor inicializado
    
    vector<Servico> getListaServico() const;
    void setListaServico(const vector<Servico> &value);

    vector<Produto> getListaProduto() const;
    void setListaProduto(const vector<Produto> &value);

    Servico retornaServico(string nome) const; // Retorna um servico da lista em posicao indicada por parametro
    Servico retornaServico(int ind) const;
    Produto retornaProduto(string nome) const; // Retorna um produto da lista em posicao indicada por parametro
    Produto retornaProduto(int ind) const;

    bool adicionar(Servico svc);  // Adiciona novo servico ao vetor
    bool adicionar(Produto prd);  // Adiciona novo produto ao vetor
    bool remover(string nome);  // Remove um servico ou produto do vetor pelo nome indicado por parametro
    bool remover(int ind);  // Remove um servico ou produto do vetor pelo indice indicado por parametro

    bool alterarQuantidade(string nome,unsigned int quant);  // Altera quantidade de um produto no vetor listaProduto
    bool alterarQuantidade(int ind, unsigned int quant); //Função para alterar a quantidade de produtos

    void imprime(); // Imprime todo o catalogo, separando em servicos e produtos

    int getIndice() const;
    void setIndice(int value);

private:
    vector<Servico> listaServico; // Vetor que armazena servicos
    vector<Produto> listaProduto; // Vetor que armazena servicos
    int indice;

};

#endif // CATALOGO_H
