#include "carrinho.h"

Carrinho::Carrinho()
{

}
//Construtor vazio
Carrinho::Carrinho(vector<Servico> is, vector<Produto> ip) :
    itensServico(is),
    itensProduto(ip)
{

}
//Construtor

vector<Servico> Carrinho::getItensServico() const
{
    return itensServico;
}

void Carrinho::setItensServico(const vector<Servico> &value)
{
    itensServico = value;
}

vector<Produto> Carrinho::getItensProduto() const
{
    return itensProduto;
}

void Carrinho::setItensProduto(const vector<Produto> &value)
{
    itensProduto = value;
}


Servico Carrinho::retornaServico(string nome) const //Função para retornar os serviços
{
    for(unsigned int i = 0; i < this->itensServico.size(); i++)
    {
        if(this->itensServico[i].getNome() == nome)
        {
            return getItensServico()[i];  // Retorna servico na posicao do vetor indicada
        }
    }

    return Servico(-1); // condicao de falha ao encontrar servico
}

Servico Carrinho::retornaServico(int ind) const //Função para retornar os serviços
{
    for(unsigned int i = 0; i < this->itensServico.size(); i++)
    {
        if(this->itensServico[i].getIndice() == ind)
        {
            return getItensServico()[i];  // Retorna servico na posicao do vetor indicada
        }
    }

    return Servico(-1); // condicao de falha ao encontrar servico
}

Produto Carrinho::retornaProduto(string nome) const
{
    for(unsigned int i = 0; i < this->itensProduto.size(); i++)
    {
        if(this->itensProduto[i].getNome() == nome)
        {
            return getItensProduto()[i];  // Retorna produto na posicao do vetor indicada
        }
    }

    return Produto(false); // condicao de falha ao encontrar produto
}

Produto Carrinho::retornaProduto(int ind) const
{
    for(unsigned int i = 0; i < this->itensProduto.size(); i++)
    {
        if(this->itensProduto[i].getIndice() == ind)
        {
            return getItensProduto()[i];  // Retorna produto na posicao do vetor indicada
        }
    }

    return Produto(false); // condicao de falha ao encontrar produto
}


bool Carrinho::adicionar(Servico svc) //Adiciona serviço///SOBRECARGA
{
    this->itensServico.push_back(svc); //Insere serviço no fim do vetor

    return true;
}

bool Carrinho::adicionar(Produto prd) //Adiciona produto///SOBRECARGA
{
    this->itensProduto.push_back(prd); //Adiciona produto no fim do vetor

    return true;
}

bool Carrinho::remover(string nome) //Remove produto ou servico pelo nome
{
    for(unsigned int i = 0; i < this->itensServico.size(); i++)
    {
        if(this->itensServico[i].getNome() == nome)
        {
            this->itensServico.erase(this->itensServico.begin() + i);
            return true; //Encontra o servico no vetor pelo nome e o remove
        }
    }

    for(unsigned int i = 0; i < this->itensProduto.size(); i++)
    {
        if(this->itensProduto[i].getNome() == nome)
        {
            this->itensProduto.erase(this->itensProduto.begin() + i);
            return true;  //Encontra o produto no vetor pelo nome e o remove
        }
    }

    return false;
}

bool Carrinho::remover(int ind) //Remove produto ou serviço pelo indice
{
    for(unsigned int i = 0; i < this->itensServico.size(); i++)
    {
        if(this->itensServico[i].getIndice() == ind)
        {
            this->itensServico.erase(this->itensServico.begin() + i);
            return true; //Encontra o servico no vetor pelo indice e o remove
        }
    }

    for(unsigned int i = 0; i < this->itensProduto.size(); i++)
    {
        if(this->itensProduto[i].getIndice() == ind)
        {
            this->itensProduto.erase(this->itensProduto.begin() + i);
            return true;  //Encontra o produto no vetor pelo indice e o remove
        }
    }

    return false;
}

bool Carrinho::alterarQuantidade(string nome, unsigned int quant) //Altera quantidade de produtos
{
    for(unsigned int i = 0; i < this->itensProduto.size(); i++)
    {
        if(this->itensProduto[i].getNome() == nome) //Encontra o produto pelo nome
        {
            this->itensProduto[i].setQuantidade(quant); //Escolhe a nova quantidade

            if(quant == 0)
            {
                remover(nome); //Se for 0, chama a função de remover produto para o produto
            }

            return true;
        }
    }

    return false;
}

bool Carrinho::alterarQuantidade(int ind, unsigned int quant) //Altera quantidade de produtos
{
    for(unsigned int i = 0; i < this->itensProduto.size(); i++)
    {
        if(this->itensProduto[i].getIndice() == ind) //Encontra o produto pelo nome
        {
            this->itensProduto[i].setQuantidade(quant); //Escolhe a nova quantidade

            if(quant == 0)
            {
                remover(ind); //Se for 0, chama a função de remover produto para o produto
            }

            return true;
        }
    }

    return false;
}

void Carrinho::imprime()
{
    cout << "    SERVICOS: " << endl << endl;          // imprime cabecalhos

    for(unsigned int i = 0; i < this->itensServico.size(); i++) // percorre vetor de servicos
    {
        cout << i << " - ";
        this->itensServico[i].imprime(); // invoca metodo do objeto servico para imprimi-lo na tela no modo carrinho
        cout << endl;
    }

    cout << endl << "    PRODUTOS: " << endl << endl;  // imprime cabecalho

    for(unsigned int i = 0; i < this->itensProduto.size(); i++) // percorre vetor de produtos
    {
        if(this->itensProduto[i].getDisponivel())
        {
            cout << i << " - ";
            this->itensProduto[i].imprime(); // invoca metodo do objeto produto para imprimi-lo na tela no modo carrinho
            cout << endl;
        }
    }
}
