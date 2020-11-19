#include "animal.h"

Animal::Animal()
{

}
//Construtor vazio
Animal:: Animal(string n, string s, string esp, string r, float peso,  int idade):
    nome(n),
    sexo(s),
    especie(esp),
    raca(r),
    peso(peso),
    idade(idade)
{

}
//Construtor
Animal::~Animal()
{

}
//Destrutor

string Animal::getNome() const
{
    return nome;
}

void Animal::setNome(const string &value)
{
    nome = value;
}

string Animal::getSexo() const
{
    return sexo;
}

void Animal::setSexo(const string &value)
{
    sexo = value;
}

float Animal::getPeso() const
{
    return peso;
}

void Animal::setPeso(float value)
{
    peso = value;
}

int Animal::getIdade() const
{
    return idade;
}

void Animal::setIdade(int value)
{
    idade = value;
}

string Animal::getRaca() const
{
    return raca;
}

void Animal::setRaca(const string &value)
{
    raca = value;
}

string Animal::getEspecie() const
{
    return especie;
}

void Animal::setEspecie(const string &value)
{
    especie = value;
}
