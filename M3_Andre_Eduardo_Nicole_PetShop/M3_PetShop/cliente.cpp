#include "cliente.h"

Cliente::Cliente() :
    Pessoa(),
    carrinho(Carrinho())
{

}
//Construtor vazio

Cliente::Cliente(const string &nome, const string &sexo, const string &cpf, int telefone, string senha, Pagamento pagamento, Animal* animal, Carrinho carrinho) :
    Pessoa(nome, sexo, cpf),
    telefone(telefone),
    senha(senha),
    formaPagamento(pagamento),
    animal(animal),
    carrinho(carrinho)
{

}
//Construtor

Cliente::~Cliente()
{

}
//Destrutor

int Cliente::getTelefone() const
{
    return this->telefone;
}

void Cliente::setTelefone(int value)
{
    this->telefone = value;
}

string Cliente::getSenha() const
{
    return senha;
}

void Cliente::setSenha(const string &value)
{
    senha = value;
}

Pagamento Cliente::getFormaPagamento() const
{
    return formaPagamento;
}

void Cliente::setFormaPagamento(const Pagamento &value)
{
    formaPagamento = value;
}

Animal *Cliente::getAnimal() const
{
    return animal;
}

void Cliente::setAnimal(Animal *value)
{
    animal = value;
}

Carrinho Cliente::getCarrinho() const
{
    return this->carrinho;
}

void Cliente::setCarrinho(const Carrinho &value)
{
    this->carrinho = value;
}


bool Cliente::finalizarCompra() //Função para finalizar compra
{
    int finaliza = 0;

    do
    {
        system("cls");

        this->carrinho.imprime();//Imprime o carrinho

        cout << "\n\n    Deseja Finalizar a compra?" << endl;
        cout << endl << "    1 - Sim";
        cout << endl << "    2 - Nao";
        cout << endl << endl << "    ";

        cin >> finaliza;
    }
    while(finaliza != 1 and finaliza != 2);

    if(finaliza == 1)
        return true;
    else
        return false;
}

void Cliente::imprime() const //Imprime o cliente
{
    Pessoa::imprime();

    cout << "Telefone: " << telefone << endl << endl;
    cout << "Animal: " << endl;
    cout << "  Nome: " << animal->getNome() << endl;
    cout << "  Sexo: " << animal->getSexo() << endl;
    cout << "  Especie: " << animal->getEspecie()<< endl;
    cout << "  Raca: " << animal->getRaca() << endl;
    cout << "  Peso: " << animal->getPeso() << endl;
    cout << "  Idade: " << animal->getIdade()<< endl;


}
