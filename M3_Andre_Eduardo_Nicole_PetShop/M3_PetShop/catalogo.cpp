#include "catalogo.h"

/**************************************** CONSTRUTORES ****************************************/

Catalogo::Catalogo()
{

}

Catalogo::Catalogo(vector<Servico> ls, vector<Produto> lp) :
    listaServico(ls),  // inicia o vetor de servicos com valor padrao
    listaProduto(lp)   // ****** * ***** ** produtos *** ***** ******
{

}


/****************************************** METODOS *******************************************/


/********************************************************
 * GETTERS E SETTERS
 *
 ********************************************************/

vector<Servico> Catalogo::getListaServico() const
{
    return listaServico;
}

void Catalogo::setListaServico(const vector<Servico> &value)
{
    listaServico = value;
}

vector<Produto> Catalogo::getListaProduto() const
{
    return listaProduto;
}

void Catalogo::setListaProduto(const vector<Produto> &value)
{
    listaProduto = value;
}


/********************************************************
 * FUNCOES DE RETORNO
 *
 ********************************************************/

Servico Catalogo::retornaServico(string nome) const
{
    for(unsigned int i = 0; i < this->listaServico.size(); i++)
    {
        if(this->listaServico[i].getNome() == nome)
        {
            return getListaServico()[i];  // Retorna servico na posicao do vetor indicada
        }
    }

    return Servico(-1);
}

Servico Catalogo::retornaServico(int ind) const //Função para retornar os serviços
{
    for(unsigned int i = 0; i < this->listaServico.size(); i++)
    {
        if(this->listaServico[i].getIndice() == ind)
        {
            return getListaServico()[i];  // Retorna servico na posicao do vetor indicada
        }
    }

    return Servico(-1); // condicao de falha ao encontrar servico
}

Produto Catalogo::retornaProduto(string nome) const
{
    for(unsigned int i = 0; i < this->listaProduto.size(); i++)
    {
        if(this->listaProduto[i].getNome() == nome)
        {
            return getListaProduto()[i];  // Retorna produto na posicao do vetor indicada
        }
    }

    return Produto(false);
}

Produto Catalogo::retornaProduto(int ind) const
{
    for(unsigned int i = 0; i < this->listaProduto.size(); i++)
    {
        if(this->listaProduto[i].getIndice() == ind)
        {
            return getListaProduto()[i];  // Retorna produto na posicao do vetor indicada
        }
    }

    return Produto(false); // condicao de falha ao encontrar produto
}



/********************************************************
 * FUNCOES DE MANIPULACAO DOS VETORES
 *
 ********************************************************/

bool Catalogo::adicionar(Servico svc)
{
    this->listaServico.push_back(svc); // insere servico recebido por parametro no fim do vetor de servicos

    return true;
}

bool Catalogo::adicionar(Produto prd)
{
    this->listaProduto.push_back(prd); // insere produto recebido por parametro no fim do vetor de servicos

    return true;
}

bool Catalogo::remover(string nome)
{
    for(unsigned int i = 0; i < this->listaServico.size(); i++)
    {
        if(this->listaServico[i].getNome() == nome) //Remove serviço a partir da busca de nome do mesmo
        {
            this->listaServico.erase(this->listaServico.begin() + i);
            return true;
        }
    }

    for(unsigned int i = 0; i < this->listaProduto.size(); i++)
    {
        if(this->listaProduto[i].getNome() == nome) //Remove produto a partir da busca de nome do mesmo
        {
            this->listaProduto.erase(this->listaProduto.begin() + i);
            return true;
        }
    }

    return false;
}

bool Catalogo::remover(int ind)
{
    for(unsigned int i = 0; i < this->listaServico.size(); i++)
    {
        if(this->listaServico[i].getIndice() == ind) //Remove serviço a partir da busca de nome do mesmo
        {
            this->listaServico.erase(this->listaServico.begin() + i);
            return true;
        }
    }

    for(unsigned int i = 0; i < this->listaProduto.size(); i++)
    {
        if(this->listaProduto[i].getIndice() == ind) //Remove produto a partir da busca de nome do mesmo
        {
            this->listaProduto.erase(this->listaProduto.begin() + i);
            return true;
        }
    }

    return false;
}

bool Catalogo::alterarQuantidade(string nome, unsigned int quant) //Altera a quantidade de produtos
{
    for(unsigned int i = 0; i < this->listaProduto.size(); i++)
    {
        if(this->listaProduto[i].getNome() == nome) //Encontra o produto com base no nome
        {
            this->listaProduto[i].setQuantidade(quant); //Recebe a nova quantidade

            if(quant == 0)
            {
                this->listaProduto[i].setDisponivel(false); //Se for 0, deixa o produto indisponível
            }
            else
            {
                this->listaProduto[i].setDisponivel(true); //Se maior, o produto fica disponível
            }

            return true;
        }
    }

    return false;
}

bool Catalogo::alterarQuantidade(int ind, unsigned int quant) //Altera a quantidade de produtos
{
    for(unsigned int i = 0; i < this->listaProduto.size(); i++)
    {
        if(this->listaProduto[i].getIndice() == ind) //Encontra o produto com base no nome
        {
            this->listaProduto[i].setQuantidade(quant); //Recebe a nova quantidade

            if(quant == 0)
            {
                this->listaProduto[i].setDisponivel(false); //Se for 0, deixa o produto indisponível
            }
            else
            {
                this->listaProduto[i].setDisponivel(true); //Se maior, o produto fica disponível
            }

            return true;
        }
    }

    return false;
}


/********************************************************
 * FUNCAO DE IMPRESSAO
 *
 ********************************************************/

void Catalogo::imprime()
{
    cout << "===================================================================================" << endl << endl; //
    cout << "    CATALOGO" << endl << endl;                                                                        //
    cout << "===================================================================================" << endl << endl; // imprime cabecalhos
    cout << "    SERVICOS: " << endl;                                                                              //
    cout << "___________________________________________________________________________________" << endl << endl; //

    for(unsigned int i = 0; i < this->listaServico.size(); i++) // percorre vetor de servicos
    {
        cout << i << " - ";
        this->listaServico[i].imprime(); // invoca metodo do objeto servico para imprimi-lo na tela no modo catalogo
        cout << endl;
    }

    cout << "===================================================================================" << endl << endl; //
    cout << "    PRODUTOS: " << endl;                                                                              // imprime cabecalho
    cout << "___________________________________________________________________________________" << endl << endl; //

    for(unsigned int i = 0; i < this->listaProduto.size(); i++) // percorre vetor de servicos
    {
        if(this->listaProduto[i].getDisponivel())
        {
            cout << i << " - ";
            this->listaProduto[i].imprime(); // invoca metodo do objeto produto para imprimi-lo na tela no modo catalogo
            cout << endl;
        }
    }
}

int Catalogo::getIndice() const
{
    return indice;
}

void Catalogo::setIndice(int value)
{
    indice = value;
}
