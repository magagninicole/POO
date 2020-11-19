#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std;
class Animal
{
public:
    Animal();
    Animal(string n, string s, string esp, string r, float peso,  int idade);//Construtor inicializado

    virtual ~Animal(); //Destrutor virutal

    string getNome() const;
    void setNome(const string &value);

    string getSexo() const;
    void setSexo(const string &value);

    string getEspecie() const;
    void setEspecie(const string &value);

    float getPeso() const;
    void setPeso(float value);

    int getIdade() const;
    void setIdade(int value);

    string getRaca() const;
    void setRaca(const string &value);

private:
    string nome;
    string sexo;
    string especie;
    string raca;
    float peso;
    int idade;

};

#endif // ANIMAL_H
