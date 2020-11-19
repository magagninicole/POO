#include "auxiliar.h"

Catalogo* Auxiliar::montaCatalogo(){
    Catalogo* cat = new Catalogo();  // aloca objeto que sera retornado

    ifstream file;  // variavel para abrir arquivo com catalogo
    char c[100];  // vetor de char para ler as linhas do arquivo
    string aux = "0";  // string auxiliar para operações de casting

    Servico* s;  // ponteiro para objetos Servico
    Produto* p;  // ponteiro para objetos Produto

    vector<Servico> vet_S;  // vetor temporario para armazernar servicos lidos do arquivo
    vector<Produto> vet_P;  // vetor temporario para armazernar produtos lidos do arquivo

    file.open("catalogo.txt");  // abre o arquivo
    {
        string nome;  // variaveis temporarias para Servico
        int indice;
        float preco;
        bool produto;

        int quantidade;  // variaveis temporarias exclusivas para Produto
        bool disponivel;

        if(file.getline(c, 100))
        {
            aux = c;

            while(aux != "file_prod_END" and file.is_open())  // repete ate o fim do arquivo
            {
                nome = c;  // atribui nome

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                indice = stoi(aux);  // disponivel recebe casting de aux para int

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                preco = stof(aux);  // preco recebe casting de aux para float

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                produto = (aux == "1");  // produto recebe casting de aux para bool

                if(produto)  // caso o item no arquivo seja um produto, entra no if
                {
                    file.getline(c, 100);
                    aux = c;  // aux recebe a linha
                    quantidade = stoi(aux);  // disponivel recebe casting de aux para int

                    file.getline(c, 100);
                    aux = c;  // aux recebe a linha
                    disponivel = (aux == "1");  // disponivel recebe casting de aux para bool

                    p = new Produto(nome, indice, preco, produto, quantidade, disponivel);  // ponteiro aloca um novo produto com os valores lidos do arquivo

                    vet_P.push_back(*p);  // novo produto eh copiado para o vetor temporario

                    delete p;  // memoria do produto alocado eh liberada
                }
                else  // se nao for um produto, entra no else
                {
                    s = new Servico(nome, indice, preco, produto);  // ponteiro aloca um novo servico com os valores lidos do arquivo

                    vet_S.push_back(*s);  // novo servico eh copiado para o vetor temporario

                    delete s;  // memoria do servico alocado eh liberada
                }

                file.getline(c, 100);
                aux = c;
            }

            file.getline(c, 100);
            aux = c;  // aux recebe a linha
        }
    }
    file.close();  // fecha o arquivo

    cat->setIndice(stoi(aux));  // disponivel recebe casting de aux para int
    cat->setListaServico(vet_S);  // vetores temporarios sao copiados para dentro dos atributos de *cat
    cat->setListaProduto(vet_P);

    return cat;  // retorna o ponteiro para objeto Catalogo alocado
}

vector<Cliente> Auxiliar::recuperaClientes()
{
    vector<Cliente> res;

    ifstream file;  // variavel para abrir arquivo com catalogo
    char c[100];  // vetor de char para ler as linhas do arquivo
    string aux;  // string auxiliar para operações de casting

    file.open("clientes.txt");  // abre o arquivo
    {
        string nome, sexo, cpf, senha;  // variaveis temporarias para Servico
        float telefone;
        Pagamento formaPagamento;

        Animal* animal;
        vector<Servico> vetS;
        vector<Produto> vetP;

        while(file.getline(c, 100) and file.is_open())  // repete ate o fim do arquivo
        {
            nome = c;  // atribui nome

            file.getline(c, 100);
            sexo = c;  // atribui sexo

            file.getline(c, 100);
            cpf = c;  // atribui cpf

            file.getline(c, 100);
            aux = c;  // aux recebe a linha
            telefone = stoi(aux); // comissao recebe casting de aux para float

            file.getline(c, 100);
            senha = c;

            file.getline(c, 100);
            aux = c;  // aux recebe a linha

            switch(stoi(aux))
            {
                case 0:
                {
                    formaPagamento = dinheiro;
                }
                break;
                case 1:
                {
                    formaPagamento = cartao;
                }
                break;
                case 2:
                {
                    formaPagamento = boleto;
                }
                break;
                default:
                {
                    formaPagamento = dinheiro;
                }
                break;
            }

            animal = new Animal();

            file.getline(c, 100);
            animal->setNome(c);

            file.getline(c, 100);
            animal->setSexo(c);

            file.getline(c, 100);
            animal->setEspecie(c);

            file.getline(c, 100);
            animal->setRaca(c);

            file.getline(c, 100);
            aux = c;  // aux recebe a linha
            animal->setPeso(stof(aux));

            file.getline(c, 100);
            aux = c;  // aux recebe a linha
            animal->setIdade(stoi(aux));

            file.getline(c, 100);
            aux = c;  // aux recebe a linha

            while(aux != "lista_serv_END")
            {
                Servico s = Servico();

                s.setNome(c);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                s.setIndice(stoi(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                s.setPreco(stof(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                s.setProduto(aux == "1");

                vetS.push_back(s);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
            }

            file.getline(c, 100);
            aux = c;  // aux recebe a linha

            while(aux != "lista_prod_END")
            {
                Produto p = Produto();

                p.setNome(c);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setIndice(stoi(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setPreco(stof(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setProduto(aux == "1");

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setQuantidade(stoi(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setDisponivel(aux == "1");

                vetP.push_back(p);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
            }

            res.push_back(Cliente(nome, sexo, cpf, telefone, senha, formaPagamento, animal, Carrinho(vetS, vetP)));

            vetS.erase(vetS.begin(), vetS.end());
            vetP.erase(vetP.begin(), vetP.end());
        }
    }
    file.close();  // fecha o arquivo

    return res;
}

vector<Funcionario> Auxiliar::recuperaFuncionarios(float &salario)
{
    vector<Funcionario> res;

    ifstream file;  // variavel para abrir arquivo com catalogo
    char c[100];  // vetor de char para ler as linhas do arquivo
    string aux;  // string auxiliar para operações de casting

    salario = 0;

    file.open("funcionarios.txt");  // abre o arquivo
    {
        string nome, sexo, cpf;  // variaveis temporarias para Servico
        float comissao;

        if(file.getline(c, 100))
        {
            aux = c;

            while(aux != "file_func_END" and file.is_open())  // repete ate o fim do arquivo
            {
                nome = c;  // atribui nome

                file.getline(c, 100);
                sexo = c;  // atribui sexo

                file.getline(c, 100);
                cpf = c;  // atribui cpf

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                comissao = stof(aux); // comissao recebe casting de aux para float

                res.push_back(Funcionario(nome, sexo, cpf, comissao));

                file.getline(c, 100);
                aux = c;
            }

            file.getline(c, 100);
            aux = c;  // aux recebe a linha

            salario = stof(aux);
        }
    }
    file.close();  // fecha o arquivo

    return res;
}

TFila<Pedido> Auxiliar::recuperaPedidos()
{
    TFila<Pedido>* res = new TFila<Pedido>;
    inicializa_fila(res);

    ifstream file;  // variavel para abrir arquivo com catalogo
    char c[100];  // vetor de char para ler as linhas do arquivo
    string aux;  // string auxiliar para operações de casting


    file.open("pedidos.txt");
    {
        Cliente* cli;
        Funcionario* fun;
        Carrinho* car;

        string nomeC, nomeF;
        vector<Servico> vetS;
        vector<Produto> vetP;

        while(file.getline(c, 100) and file.is_open())  // repete ate o fim do arquivo
        {
            nomeC = c;  // atribui nome do cliente

            file.getline(c, 100);
            nomeF = c;  // atribui nome do funcionario

            file.getline(c, 100);
            aux = c;  // aux recebe a linha

            while(aux != "lista_serv_END")
            {
                Servico s = Servico();

                s.setNome(c);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                s.setIndice(stoi(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                s.setPreco(stof(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                s.setProduto(aux == "1");

                vetS.push_back(s);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
            }

            file.getline(c, 100);
            aux = c;  // aux recebe a linha

            while(aux != "lista_prod_END")
            {
                Produto p = Produto();

                p.setNome(c);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setIndice(stoi(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setPreco(stof(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setProduto(aux == "1");

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setQuantidade(stoi(aux));

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
                p.setDisponivel(aux == "1");

                vetP.push_back(p);

                file.getline(c, 100);
                aux = c;  // aux recebe a linha
            }

            cli = new Cliente();
            fun = new Funcionario();
            car = new Carrinho();

            cli->setNome(nomeC);
            fun->setNome(nomeF);
            car->setItensServico(vetS);
            car->setItensProduto(vetP);

            QUEUE(res, Pedido(*cli, *fun, *car));

            delete cli;
            delete fun;
            delete car;

            vetS.erase(vetS.begin(), vetS.end());
            vetP.erase(vetP.begin(), vetP.end());
        }
    }
    file.close();

    return *res;
}

void Auxiliar::setupAdm(AdmPetShop *&adm){
    float salario;
    Catalogo* cat = Auxiliar::montaCatalogo();

    adm = new AdmPetShop(33716638, *cat, Auxiliar::recuperaClientes(), Auxiliar::recuperaFuncionarios(salario));

    adm->setFilaPedido(recuperaPedidos());

    delete cat;
}

void Auxiliar::salvaFuncionarios(vector<Funcionario> fun){
    ofstream file;  // variavel para abrir arquivo com catalogo

    float salario = Funcionario::getSalario();

    file.open("funcionarios.txt");  // abre o arquivo
    {
        for(unsigned int i = 0; i < fun.size(); i++) // percorre vetor de servicos
        {
            file << fun[i].getNome() << "\n";
            file << fun[i].getSexo() << "\n";
            file << fun[i].getCpf() << "\n";
            file << fun[i].getComissao() << "\n";
        }

        file << "file_func_END" << "\n";
        file << salario;
    }
    file.close();  // fecha o arquivo
}

void Auxiliar::salvaClientes(vector<Cliente> clienteLista){ //********DESISTI DA VIDA***************QUERO MORRE*************PARTIU JOGA*************
    ofstream file;  // variavel para abrir arquivo com catalogo

    file.open("clientes.txt");  // abre o arquivo
    {
        for(unsigned int i = 0; i < clienteLista.size(); i++) // percorre vetor de clientes
        {
            Cliente cliente = clienteLista[i];
            vector<Servico> vetS = cliente.getCarrinho().getItensServico();
            vector<Produto> vetP = cliente.getCarrinho().getItensProduto();
            Animal *animal = cliente.getAnimal();

            file << cliente.getNome() << "\n";
            file << cliente.getSexo() << "\n";
            file << cliente.getCpf() << "\n";
            file << cliente.getTelefone() << "\n";
            file << cliente.getSenha() << "\n";
            file << cliente.getFormaPagamento() << "\n";

            file << animal->getNome() << "\n";
            file << animal->getSexo() << "\n";
            file << animal->getEspecie() << "\n";
            file << animal->getRaca() << "\n";
            file << animal->getPeso() << "\n";
            file << animal->getIdade() << "\n";


            for(unsigned int j = 0; j < vetS.size(); j++)
            {
                file << vetS[j].getNome() << "\n";

                file << vetS[j].getIndice() << "\n";

                file << vetS[j].getPreco() << "\n";

                file << vetS[j].getProduto() << "\n";
            }

            file << "lista_serv_END" << "\n";



            for(unsigned int j = 0; j < vetP.size(); j++)
            {
                file << vetP[j].getNome() << "\n";

                file << vetP[j].getIndice() << "\n";

                file << vetP[j].getPreco() << "\n";

                file << vetP[j].getProduto() << "\n";

                file << vetP[j].getQuantidade() << "\n";

                file << vetP[j].getDisponivel() << "\n";
            }

            file << "lista_prod_END" << "\n";
        }

    file.close();  // fecha o arquivo
    }
}

void Auxiliar::salvaCatalogo(Catalogo cat){
    ofstream file;  // variavel para abrir arquivo com catalogo

    vector<Servico> vet_S = cat.getListaServico();  // vetor temporario para armazernar servicos lidos do arquivo
    vector<Produto> vet_P = cat.getListaProduto();  // vetor temporario para armazernar produtos lidos do arquivo
    int indice = cat.getIndice();

    file.open("catalogo.txt");  // abre o arquivo
    {
        for(unsigned int i = 0; i < vet_S.size(); i++) // percorre vetor de servicos
        {
            Servico svc = vet_S[i];

            file << svc.getNome() << "\n";
            file << svc.getIndice() << "\n";
            file << svc.getPreco() << "\n";
            file << svc.getProduto() << "\n";
        }

        for(unsigned int i = 0; i < vet_P.size(); i++) // percorre vetor de servicos
        {
            Produto prd = vet_P[i];

            file << prd.getNome() << "\n";
            file << prd.getIndice() << "\n";
            file << prd.getPreco() << "\n";
            file << prd.getProduto() << "\n";
            file << prd.getQuantidade() << "\n";
            file << prd.getDisponivel() << "\n";
        }

        file << "file_prod_END" << "\n";
        file << indice;
    }
    file.close();  // fecha o arquivo
}

void Auxiliar::salvaPedidos(TFila<Pedido> ped)
{
    ofstream file;  // variavel para abrir arquivo com catalogo

    TFila<Pedido>* fila = &ped;

    Pedido* aux;
    vector<Servico> vetS;
    vector<Produto> vetP;

    aux = primeiro_elemento(*fila);

    file.open("pedidos.txt");
    {
        while(aux)
        {
            file << aux->getC().getNome() << "\n";



            file << aux->getF().getNome() << "\n";



            vetS = aux->getCar().getItensServico();

            for(unsigned i = 0; i < vetS.size(); i++)
            {
                file << vetS[i].getNome() << "\n";

                file << vetS[i].getIndice() << "\n";

                file << vetS[i].getPreco() << "\n";

                file << vetS[i].getProduto() << "\n";
            }

            file << "lista_serv_END" << "\n";



            vetP = aux->getCar().getItensProduto();

            for(unsigned i = 0; i < vetP.size(); i++)
            {
                file << vetP[i].getNome() << "\n";

                file << vetP[i].getIndice() << "\n";

                file << vetP[i].getPreco() << "\n";

                file << vetP[i].getProduto() << "\n";

                file << vetP[i].getQuantidade() << "\n";

                file << vetP[i].getDisponivel() << "\n";
            }

            file << "lista_prod_END" << "\n";



            DEQUEUE(fila);
            aux = primeiro_elemento(*fila);
        }
    }
    file.close();
}
