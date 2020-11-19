#include "admpetshop.h"



AdmPetShop::AdmPetShop()
{
    inicializa_fila(&this->filaPedido);
}
//Construtor vazio
AdmPetShop::AdmPetShop(int t, Catalogo cat) :
    telefone(t),
    catalogo(cat)
{
    inicializa_fila(&this->filaPedido);
} //Construtor

AdmPetShop::AdmPetShop(int t, Catalogo cat, vector<Cliente> cli, vector<Funcionario> fun) :
    telefone(t),
    catalogo(cat),
    listaCliente(cli),
    listaFuncionario(fun)
{
    inicializa_fila(&this->filaPedido);
}

int AdmPetShop::getTelefone() const
{
    return telefone;
}

void AdmPetShop::setTelefone(int value)
{
    telefone = value;
}

Catalogo AdmPetShop::getCatalogo() const
{
    return catalogo;
}

void AdmPetShop::setCatalogo(const Catalogo &value)
{
    catalogo = value;
}

vector<Cliente> AdmPetShop::getListaCliente() const
{
    return listaCliente;
}

void AdmPetShop::setListaCliente(const vector<Cliente> &value)
{
    listaCliente = value;
}

vector<Funcionario> AdmPetShop::getListaFuncionario() const
{
    return listaFuncionario;
}

void AdmPetShop::setListaFuncionario(const vector<Funcionario> &value)
{
    listaFuncionario = value;
}

TFila<Pedido> AdmPetShop::getFilaPedido() const
{
    return filaPedido;
}

void AdmPetShop::setFilaPedido(const TFila<Pedido> &value)
{
    filaPedido = value;
}

float AdmPetShop::realizarPagamento()
{
    float precoFinal = 0;
    Pedido *p;

    p = primeiro_elemento(filaPedido);

    if(p)
    {
       // p = DEQUEUE(&filaPedido);

        for(unsigned int i = 0; i < p->getCar().getItensServico().size(); i++) // navega vetor de servicos
        {
             precoFinal += p->getCar().getItensServico()[i].getPreco(); // adiciona preco de cada servico ao preco final
        }

        for(unsigned int i = 0; i < p->getCar().getItensProduto().size(); i++) // navega vetor de produtos
        {
             precoFinal += p->getCar().getItensProduto()[i].getPreco() /*PRECO*/*/*QUANTIDADE*/ p->getCar().getItensProduto()[i].getQuantidade(); // adiciona preco de cada produto vezes sua quantidade ao preco final
        }
    }
        return precoFinal;
}

void AdmPetShop::cadastraProduto(Produto* p)
{
    Servico svc;
    Produto prd;

    p->setIndice(catalogo.getIndice());
    catalogo.setIndice(catalogo.getIndice() + 1);

    svc = Servico(*p);
    prd = Produto(*p);

    p->getProduto() ? catalogo.adicionar(prd) : catalogo.adicionar(svc); // verifica se produto ou servico e chama sobrecarga adequada de adicionar()
}

void AdmPetShop::imprimeClientes() //Impressão da lista de clientes
{
    for(unsigned int i = 0; i< listaCliente.size();i++) //Enquanto i for menor que o número de clientes
    {
        listaCliente[i].imprime(); //Chama a função de impressão
        cout << endl;
    }
}

void AdmPetShop::cadastraCliente(Cliente c)
{
    listaCliente.push_back(c); //Cadastra cliente no vetor "Cliente"
}

Cliente* AdmPetShop::retornaCliente(string nome, string senha) //Função para retornar os dados do cliente quando o mesmo solicitar
{
    for(unsigned int i = 0; i < listaCliente.size(); i++)
    {
        if(listaCliente[i].getNome() == nome and listaCliente[i].getSenha() == senha) //Encontra o cliente com os dados compatíveis
        {
            return &listaCliente[i]; //Retorna a posição em que está o cliente solicitado no vetor cliente
        }
    }

    return NULL;
}



void AdmPetShop::imprimeFuncionarios() //Impressão da lista de Funcionarios
{
    for(unsigned int i = 0; i< listaFuncionario.size();i++) //Enquanto i for menor que o número de Funcionarios
    {
        listaFuncionario[i].imprime(); //Chama a função de impressão
        cout << endl;
    }
}

void AdmPetShop::cadastraFuncionario(Funcionario f)
{
    listaFuncionario.push_back(f); //Cadastra cliente no vetor "Cliente"
}

Funcionario* AdmPetShop::retornaFuncionario(string nome) //Função para retornar os dados do cliente quando o mesmo solicitar
{
    for(unsigned int i = 0; i < listaFuncionario.size(); i++)
    {
        if(listaFuncionario[i].getNome() == nome) //Encontra o cliente com os dados compatíveis
        {
            return &listaFuncionario[i]; //Retorna a posição em que está o cliente solicitado no vetor funcionario
        }
    }

    return NULL;
}

void AdmPetShop::reajustaSalario(float value)
{
    Funcionario::setSalario(value);
}

void AdmPetShop::inserirPedido(Pedido p){
    TFila<Pedido>*pedir;

    pedir = &this->filaPedido;

    QUEUE(pedir,p);
}

void AdmPetShop::rotacionarFuncionarios(){
    Funcionario fun = this -> listaFuncionario[0];
    listaFuncionario.erase(listaFuncionario.begin());
    listaFuncionario.push_back(fun);
 }

