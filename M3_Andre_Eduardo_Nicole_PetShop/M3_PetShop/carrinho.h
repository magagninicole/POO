#ifndef CARRINHO_H
#define CARRINHO_H

#include <vector>
#include "listaprodutos.h"

class Carrinho : ListaProdutos
{
public:
    Carrinho();
    Carrinho(vector<Servico> is, vector<Produto> ip); //Construtor inicializado

    vector<Servico> getItensServico() const;
    void setItensServico(const vector<Servico> &value);

    vector<Produto> getItensProduto() const;
    void setItensProduto(const vector<Produto> &value);

    Servico retornaServico(string nome) const;
    Servico retornaServico(int ind) const;
    Produto retornaProduto(string nome) const;
    Produto retornaProduto(int ind) const;

    bool adicionar(Servico svc); //Adiciona servico
    bool adicionar(Produto prd);//Adiciona produto
    bool remover(string nome); //Remove servico ou produto
    bool remover(int ind); //Remove servico ou produto

    bool alterarQuantidade(string nome, unsigned int quant); //Função para alterar a quantidade de produtos
    bool alterarQuantidade(int ind, unsigned int quant); //Função para alterar a quantidade de produtos

    void imprime();

private:
    vector<Servico> itensServico; //Vetor contendo serviços
    vector<Produto> itensProduto; //Vetor contendo produtos

};

#endif // CARRINHO_H
