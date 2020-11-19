#ifndef ADMPETSHOP_H
#define ADMPETSHOP_H

#include "catalogo.h"
#include "cliente.h"
#include "funcionario.h"
#include "pedido.h"
#include "fila.h"
#include <vector>

using namespace std;

class AdmPetShop
{
public:
    AdmPetShop();

    AdmPetShop(int t, Catalogo cat); //Construtor inicializado
    AdmPetShop(int t, Catalogo cat, vector<Cliente> cli, vector<Funcionario> fun); //Construtor inicializado

    int getTelefone() const;
    void setTelefone(int value);

    Catalogo getCatalogo() const;
    void setCatalogo(const Catalogo &value);

    vector<Cliente> getListaCliente() const;
    void setListaCliente(const vector<Cliente> &value);

    vector<Funcionario> getListaFuncionario() const;
    void setListaFuncionario(const vector<Funcionario> &value);

    TFila<Pedido> getFilaPedido() const;
    void setFilaPedido(const TFila<Pedido> &value);

    float realizarPagamento();

    void cadastraProduto(Produto* p);

    void imprimeClientes();
    void cadastraCliente(Cliente c);

    Cliente* retornaCliente(string nome, string senha); //Função de entrada para o cliente

    void imprimeFuncionarios();
    void cadastraFuncionario(Funcionario f);

    Funcionario* retornaFuncionario(string nome); //Função que retorna qual o funcionario selecionado pelo nome

    void reajustaSalario(float value);//Função para ajustar o salário do funcionário

    void inserirPedido(Pedido p);

    void rotacionarFuncionarios();

private:
    int telefone;
    Catalogo catalogo;
    vector<Cliente>listaCliente;
    vector<Funcionario>listaFuncionario;
    TFila<Pedido>filaPedido;
};

#endif // ADMPETSHOP_H
