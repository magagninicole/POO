#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "admpetshop.h"
#include "carrinho.h"
#include "catalogo.h"
#include "produto.h"

#include <fstream>
using namespace std;

class Auxiliar
{
public:
    static Catalogo* montaCatalogo();
    static vector<Cliente>recuperaClientes();
    static vector<Funcionario> recuperaFuncionarios(float &salario);
    static TFila<Pedido> recuperaPedidos();
    static void setupAdm(AdmPetShop *&adm);
    static void salvaFuncionarios(vector<Funcionario> fun);
    static void salvaClientes(vector<Cliente> clienteLista);
    static void salvaCatalogo(Catalogo cat);
    static void salvaPedidos(TFila<Pedido> ped);
private:
    Auxiliar();
};

#endif // AUXILIAR_H
