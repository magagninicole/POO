#ifndef CLIENTE_H
#define CLIENTE_H

#include "pessoa.h"
#include "animal.h"
#include "carrinho.h"

enum Pagamento {dinheiro, cartao, boleto};

class Cliente : public Pessoa //Cliente é herança de pessoa
{
public:
    Cliente();
    Cliente(const string &nome, const string &sexo,const string &cpf, int telefone, string senha, Pagamento pagamento, Animal* animal, Carrinho carrinho); //Construtor inicializado

    ~Cliente(); //Destrutor de classe

    int getTelefone() const;
    void setTelefone(int value);

    string getSenha() const;
    void setSenha(const string &value);

    Pagamento getFormaPagamento() const;
    void setFormaPagamento(const Pagamento &value);

    Animal *getAnimal() const;
    void setAnimal(Animal *value);

    Carrinho getCarrinho() const;
    void setCarrinho(const Carrinho &value);


    void imprime() const; //Função para impressão
    bool finalizarCompra(); //Função para finalizar ou não a compra

private:
    int telefone;
    string senha;
    Pagamento formaPagamento;
    Animal *animal;
    Carrinho carrinho;
};

#endif // CLIENTE_H
