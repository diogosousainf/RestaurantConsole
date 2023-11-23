#include "Restaurante.h"
#include <iostream>
#include <iomanip> // especialmente para manipular a formatação de dados de output, como definição de largura, precisão, alinhamento
#include <string> //  para usar a classe string
#include <cctype> // para controlar o fluxo de caracteres e verificar se um caractere é um dígito ou uma letra
#include <algorithm> // busca e manipulação de elementos 
#include <ctime> // para usar a função time
#include <chrono> // para usar a função put_time
#include <thread> // para usar a função sleep_for
#include <cmath> // para usar a função round
// size_t é um tipo de dados inteiro sem sinal que é usado para representar o tamanho de um objeto
// push_back() adiciona um elemento ao final do vetor
// setw() define a largura do campo de saída
// resize() altera o tamanho do vetor
// erase() remove um elemento do vetor

Restaurante::Restaurante() {
    //definicao de pratos
    Prato prato1 = { "Prego de Novilho", 14.99,100,"10-12-23"};
    Prato prato2 = { "Hamburguer de Boi", 15.50,100,"17-12-23" }; 
    Prato prato3 = { "Costeletao ", 50.00,100,"20-12-23" }; 
    Prato prato4 = { "Bife da Vazia ", 50.00,100,"30-12-23" }; 
    Prato prato5 = { "Vazia Maturada Premium ", 125.00,100,"02-12-23" }; 
    Prato prato6 = { "Costeletao Maturado Premium ", 165.00,100,"15-12-23" }; 

    //adicao de pratos ao vetor ementa.pratos
    ementaPratos.push_back(prato1);
    ementaPratos.push_back(prato2);
    ementaPratos.push_back(prato3);
    ementaPratos.push_back(prato4);
    ementaPratos.push_back(prato5);
    ementaPratos.push_back(prato6);


    Bebida bebida1 = {"Agua", 1.50};
    Bebida bebida2 = { "Coca-Cola", 2.50 };
    Bebida bebida3 = { "Sumo de Laranja", 2.00 };
    Bebida bebida4 = { "Sumo de Ananas", 2.00 };
    Bebida bebida5 = { "Vinho tinto", 20.00 };
    Bebida bebida6 = { "Vinho branco", 15.00 };
    Bebida bebida7 = { "Sangria", 25.00 };

    ementaBebidas.push_back(bebida1);
    ementaBebidas.push_back(bebida2);
    ementaBebidas.push_back(bebida3);
    ementaBebidas.push_back(bebida4);
    ementaBebidas.push_back(bebida5);
    ementaBebidas.push_back(bebida6);
    ementaBebidas.push_back(bebida7);

    //contagem de vendas por prato e bebida, inicializa os vetores a 0
    vendasPorPrato.resize(ementaPratos.size(), 0);
    vendasPorBebida.resize(ementaBebidas.size(), 0);

}

//Pedido Cliente/////////////////////////////////////////////////////////////////////////////////////
void Restaurante::inserirPedidoCliente() {
    if (ementaPratos.empty())
    {
        cout << "Ementa vazia, hoje nao ha nada para servir!";
        return;
    }
    int numMesa, numCliente;
    string nomeCliente, telefoneCliente, enderecoCliente;

    cout << "Digite o numero da mesa para fazer o pedido: ";
    while (!(cin >> numMesa)) {
        cout << "Por favor, digite um numero valido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//descartar carateres existentes e evita loop infinito
    }

    cout << "\nDigite o nome do cliente: ";
    cin.ignore();
    while (true) {
        getline(cin, nomeCliente);

        bool apenasLetrasEEspacos = true;
        for (char c : nomeCliente) {
            if (!isalpha(c) && !isspace(c)) {
                apenasLetrasEEspacos = false;
                break;
            }
        }
        if (apenasLetrasEEspacos) {
            break;
        }
        else {
            cout << "Por favor, digite um nome  apenas letras e espacos: ";
        }
    }
    cout << "\n";

    cout << "Digite o telefone do cliente: ";
    while (true) {
        getline(cin, telefoneCliente);

        bool apenasNumeros = true;
        for (char c : telefoneCliente) {
            if (!isdigit(c)) {
                apenasNumeros = false;
                break;
            }
        }

        if (apenasNumeros && telefoneCliente.size() == 9) {
            break;
        }
        else {
            cout << "Por favor, digite um numero com exatemente 9 numeros ";
        }
    }

    cout << "Digite o endereco do cliente: ";
    getline(cin, enderecoCliente);

    cout << "Digite o numero do cliente: ";
    while (!(cin >> numCliente)) {
        cout << "Por favor, digite um numero valido: ";
        cin.clear();//limpa estado de erro do objeto cin para que a entrada possa continuar
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//descartar carateres existentes e evita loop infinito
    }

    int opcaoPrato, opcaoBebida;
    int quantidadePrato, quantidadeBebida;
    cout<<"______________________________________________________________________________________\n\n";
    cout << "Registo de pedido para: " << nomeCliente <<"." << endl;
    cout<<"______________________________________________________________________________________\n";
   
    do {
        cout << "\nEmenta de Pratos:\n";
        for (size_t i = 0; i < ementaPratos.size(); ++i) {//correr todos os elementos do vetor
            cout << i + 1 << ". " << ementaPratos[i].nome << " - " << ementaPratos[i].preco << " euros";
            if (ementaPratos[i].quantidadeEmStock <= 0) {
                cout << " (Indisponivel)";
            }
            cout << endl;
        }

        cout << "\nEscolha um prato: ";
        while (!(cin >> opcaoPrato) || opcaoPrato < 1 || opcaoPrato > ementaPratos.size() || ementaPratos[opcaoPrato - 1].quantidadeEmStock <= 0) {
            if (opcaoPrato < 1 || opcaoPrato > ementaPratos.size()) {
                cout << "Por favor, escolha um prato dentro da ementa: ";
            }
            else if (ementaPratos[opcaoPrato - 1].quantidadeEmStock <= 0) {
                cout << "Desculpe, o prato escolhido nao esta disponivel. Escolha outro prato: ";
            }
            else {
                cout << "Por favor, escolha um prato valido: ";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Qual a quantidade do prato " << ementaPratos[opcaoPrato - 1].nome << "? ";
        cin >> quantidadePrato;

        if (ementaPratos[opcaoPrato - 1].quantidadeEmStock > 0) {
            cout << "Voce escolheu: " << quantidadePrato <<" unidades de "<< ementaPratos[opcaoPrato - 1].nome << endl;
            ementaPratos[opcaoPrato - 1].quantidadeEmStock ; // Reduz a quantidade em stock do prato escolhido
        }
        else {
            cout << "Desculpe, o prato selecionado nao esta mais disponivel." << endl;
        }
       

        cout << "\nEmenta de Bebidas:\n";
        for (size_t i = 0; i < ementaBebidas.size(); ++i) {
            cout << i + 1 << ". " << ementaBebidas[i].nome << " - " << ementaBebidas[i].preco << " euros" << endl;
        }

        cout << "\nEscolha uma bebida: ";
        while (!(cin >> opcaoBebida) || opcaoBebida < 1 || opcaoBebida > ementaBebidas.size()) {
            if (opcaoBebida<1 || opcaoBebida>ementaBebidas.size())
            {
                cout << "Por favor, escolha uma bebida dentro da ementa: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (ementaBebidas[opcaoBebida - 1].quantidadeEmStock <= 0) {
                cout << "Desculpe, a bebida escolhida nao esta disponivel. Escolha outra bebida: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
        }
        cout << "Qual a quantidade da bebida " << ementaBebidas[opcaoBebida - 1].nome << "? ";
        cin >> quantidadeBebida;

        if (ementaPratos[opcaoBebida - 1].quantidadeEmStock > 0) {
            cout << "Voce escolheu: " << quantidadeBebida << " unidades de " << ementaBebidas[opcaoBebida - 1].nome << endl;
            ementaBebidas[opcaoBebida - 1].quantidadeEmStock--; // Reduz a quantidade em stock do prato escolhido
        }
        else {
            cout << "Desculpe, a bebida selecionado nao esta  disponivel." << endl;
        }


        if (quantidadePrato > 0 && quantidadeBebida > 0) {
            break; // se valido sai do loop
        }
        else {
            cout << "As quantidades devem ser valores positivos. Por favor, tente novamente.\n";
        }
    } while (true);



    if (opcaoPrato >= 1 && opcaoPrato <= ementaPratos.size()) {
        // Verificar se o prato está disponível em stocl«k
        if (verificarStockPrato(ementaPratos[opcaoPrato - 1].nome)) {
            cout << "Desculpe, o prato selecionado nao esta disponivel no momento.\n";
        }
        else {
            Cliente novoCliente(nomeCliente, telefoneCliente, enderecoCliente, numCliente);
            Pedido novoPedido(ementaPratos[opcaoPrato - 1], quantidadePrato, ementaBebidas[opcaoBebida - 1], quantidadeBebida, numMesa, novoCliente);
            pedidos.push_back(novoPedido);
            vendasPorPrato[opcaoPrato - 1] += quantidadePrato;
            vendasPorBebida[opcaoBebida - 1] += quantidadeBebida;
            clientes.push_back(novoCliente);
            cout << "\nPedido registrado com sucesso!\n";
        }
        if (verificarsorteado(pedidos.back())) {
            cout << "\nEste pedido foi sorteado para nao pagamento!\n";
        }
    }
    else {
        cout << "\nOpcao invalida!\n";
        cout << "Pedido nao registado!\n";
    }
    int randomChance = rand() % 100;
    if (randomChance < 10) {
        pedidos.back().setSorteado(true);
        cout << "\nEste pedido foi sorteado para nao pagamento!\n";
        return;
    }
}

void Restaurante::verPedidoCliente() const
{
    if (pedidos.empty()) {
        cout << "\nNao ha pedidos registados.\n";
        return;
    }

    cout << "\nEscolha o numero da mesa que deseja ver o pedido:\n";
    for (size_t i = 0; i < pedidos.size(); ++i) {
        cout << i + 1 << ". Mesa " << pedidos[i].getNumMesa() << endl;
    }

    int opcaoMesa;
    cout << "Mesa: ";
    cin >> opcaoMesa;

    // Limpar o buffer após a leitura do número da mesa
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool mesaEncontrada = false;
    for (const auto& pedido : pedidos) {
        if (pedido.getNumMesa() == opcaoMesa) {
            if (!mesaEncontrada) {
                cout << "                                     _____________________________________ " << "\n";
                cout << "                                    |                                     |" << "\n";
                cout << "\n                                             PEDIDO DA MESA " << opcaoMesa << "\n";
                cout << "                                    |                                     |" << "\n";
                cout << "                                    |_____________________________________|" << "\n";
                cout << fixed << setprecision(2);
                mesaEncontrada = true;
            }

            cout << "                                     | Numero do Pedido: " << pedido.getNumMesa() << "\n";
            cout << "                                     | Numero do Cliente: " << pedido.getCliente().getNumCliente()  << "\n";
            cout << "                                     | Nome do prato: " << pedido.getPrato().nome <<  "\n";
            cout << "                                     | Preco do prato: " << pedido.getPrato().preco  << " euros" <<  "\n";
            cout << "                                     | Quantidade do prato: " << pedido.getQuantidadePrato() <<   "\n";
            cout << "                                     | Nome da bebida: " << pedido.getBebida().nome << setw(18) <<  "\n";
            cout << "                                     | Preco da bebida: " << pedido.getBebida().preco  << " euros" << "\n";
            cout << "                                     | Quantidade da bebida: " << pedido.getQuantidadeBebida() << "\n";
            cout << "                                     |_____________________________________|"  << endl;
        }
    }
}
// & vai buscar o endereco de memoria da variavel
double Restaurante::calcularTotalPedido(const Pedido& pedido) const {
    // Aumentar o preço do prato em 30%
    double precoPratoComAumento = pedido.getPrato().preco * 1.3;

    return (precoPratoComAumento * pedido.getQuantidadePrato()) + (pedido.getBebida().preco * pedido.getQuantidadeBebida());
}

bool Restaurante::verificarsorteado(const Pedido& pedido) const {
    return pedido.foiSorteado();
}

void Restaurante::imprimirRecibo() const {

    if (pedidos.empty()) {
        cout << "\nNenhum pedido registrado.\n";
        return;
    }

    cout << "\nInsira o numero da mesa para imprimir o recibo:\n";
    for (size_t i = 0; i < pedidos.size(); ++i) {
        cout << i + 1 << ". Mesa " << pedidos[i].getNumMesa() << endl;
    }

    int opcaoMesa;
    cout << "Mesa: ";
    cin >> opcaoMesa;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Armazenar o resultado da mesa
    bool mesaEncontrada = false;
    // Armazenar o resultado da sorteio
    bool pedidoSorteado = false;
    
    cout << "Deseja adicionar o numero de contribuinte? (S/N): ";
    char opcao;
    cin >> opcao;
    int numeroContribuinte = 0;
    if (toupper(opcao) == 'S') {
        cout << "Numero de contribuinte: ";
        cin >> numeroContribuinte;
    }
    //percorrer todos os pedidos e guardar o pedido que tem o numero da mesa igual ao numero da mesa escolhida
    for (const auto& pedido : pedidos) {
        if (pedido.getNumMesa() == opcaoMesa) {
            if (!mesaEncontrada) {


                cout << "\n";
                cout <<setw(35)<< " ___________________________________________________________\n";
                cout << setw(35) << "|                                                           |\n";
                cout << setw(35) <<"|                       RECIBO DA MESA " << setw(3) << opcaoMesa << "                  |\n";
                cout <<setw(35)<< "|___________________________________________________________|\n";

                dataRecibo();
                cout << fixed << setprecision(2);
                mesaEncontrada = true;
                pedidoSorteado = verificarsorteado(pedido); // Armazenar o resultado
            }

            cout << "| Pedido: " << setw(2) << pedido.getNumMesa() << "                                                |\n";
            cout << "| Cliente: " << setw(2) << pedido.getCliente().getNumCliente() << "                                               |\n";

            if (numeroContribuinte != 0) {
                cout << "| Numero de Contribuinte: " << setw(2) << numeroContribuinte << "\n";
            }

            cout << "| Prato" << setw(34) << "  Preco" << setw(11) << "  Quantidade       |\n";
            cout << "|___________________________________________________________|\n";
            cout << "| " << setw(26) << std::left << " " << setw(15) << std::right << "  " << setw(19)  << "|\n";
            cout << "| " << setw(28) << std::left << pedido.getPrato().nome << setw(11) << std::right << pedido.getPrato().preco << setw(11) << pedido.getQuantidadePrato() << setw(10)<<"|\n";
            cout << "| " << setw(28) << std::left << pedido.getBebida().nome << setw(11) << std::right << pedido.getBebida().preco << setw(11) << pedido.getQuantidadeBebida()<< setw(10) << "|\n";

            double subtotal = (pedido.getPrato().preco * pedido.getQuantidadePrato()) + (pedido.getBebida().preco * pedido.getQuantidadeBebida());
            cout << "|___________________________________________________________|\n";
            cout << "| Total s/IVA " << setw(28) << subtotal << "euros"<< setw(15) << "|\n";
        }
    }

    if (mesaEncontrada) {
        cout << "| Total a pagar para a Mesa " << setw(2) << opcaoMesa << ": ";
        if (pedidoSorteado) {
            cout << "Pedido sorteado, valor 0.00";
        }
        else {
            double totalMesa = calcularTotalMesa(opcaoMesa);
            cout << setw(10) << totalMesa << "euros" << setw(15) << "|\n";
        }
        cout << "|___________________________________________________________|\n";
    }
    else {
        cout << "Opcao de Pedido invalida ou pedidos nao encontrados!\n";
    }
}

void Restaurante::dataRecibo() const {
    tm localTime;
    time_t now = time(0);
    localtime_s(&localTime, &now);
    cout << "| Data do Recibo: " << put_time(&localTime, "%Y-%m-%d %H:%M:%S") << setw(25) << "|\n";
}

double Restaurante::calcularTotalMesa(int numMesa) const
{
    double totalMesa = 0.0;

    for (const auto& pedido : pedidos) {
        if (pedido.getNumMesa() == numMesa && !pedido.foiSorteado()) {
            totalMesa += calcularTotalPedido(pedido);
        }
    }

    return totalMesa;
}


// BEBIDA Cliente/////////////////////////////////////////////////////////////////////////////////////
void Restaurante::adicionarBebida(const string& nome, double preco)
{
    Bebida novaBebida;
	novaBebida.nome = nome;
	novaBebida.preco = preco;
	ementaBebidas.push_back(novaBebida);
	cout << fixed << setprecision(2);
	cout << "\nBebida adicionada com sucesso!" << endl;
}

void Restaurante::removerBebida()
{
    if (ementaBebidas.empty()) {
		cout << "\nA ementa esta vazia. Nao ha bebidas para remover.\n";
		return;
	}

	cout << "\nEscolha o numero da bebida que deseja remover:\n";
    for (size_t i = 0; i < ementaBebidas.size(); ++i) {
		cout << i + 1 << ". " << ementaBebidas[i].nome << " - " << ementaBebidas[i].preco << " euros" << endl;
	}

	int opcao;
	cout << "Opcao: ";
	cin >> opcao;

    if (opcao >= 1 && opcao <= ementaBebidas.size()) {
		ementaBebidas.erase(ementaBebidas.begin() + opcao - 1);
		cout << "\nBebida removida com sucesso!\n";
	}
    else {
		cout << "\nOpcao invalida!\n";
		cout << "Bebida nao removida!\n";
	}
}

void Restaurante::editarBebida()
{
    if (ementaBebidas.empty()) {
		cout << "\nA ementa esta vazia. Nao ha bebidas para editar.\n";
		return;
	}

	cout << "\nEscolha o numero da bebida que deseja editar:\n";
    for (size_t i = 0; i < ementaBebidas.size(); ++i) {
		cout << i + 1 << ". " << ementaBebidas[i].nome << " - " << ementaBebidas[i].preco << " euros" << endl;
	}

	int opcao;
	cout << "Opcao: ";
	cin >> opcao;

    if (opcao >= 1 && opcao <= ementaBebidas.size()) {
		Bebida novaBebida;
		cin.ignore(); 
		cout << "\nNome da bebida: ";
		getline(cin, novaBebida.nome);
		cout << "Preco da bebida: ";
		cin >> novaBebida.preco;
		ementaBebidas[opcao - 1] = novaBebida;
		cout << "\nBebida editada com sucesso!\n";
	}
    else {
		cout << "\nOpcao invalida!\n";
		cout << "Bebida nao editada!\n";
	}
}

void Restaurante::verEmentaBebidas()
{
    if (ementaBebidas.empty()) {
		cout << "\nA ementa esta vazia.\n";
	}
    else {
		cout << "\n_____________EMENTA________________\n" << endl;
		cout << fixed << setprecision(2);
        for (const auto& bebida : ementaBebidas) {
			cout << "\nNome da bebida: " << bebida.nome << endl;
			cout << "Preco da bebida: " << bebida.preco << " euros" << endl;
			cout << "___________________________________" << endl;
		}
	}
}

//RELATORIOS////////////////////////////////////////////////////////////////////////////////////
void Restaurante::relatorioStock()
{
    cout << "Relatorio de Stock:\n";

    for (size_t i = 0; i < ementaPratos.size(); ++i) {
        int stockDisponivel = ementaPratos[i].quantidadeEmStock - vendasPorPrato[i];
        cout << ementaPratos[i].nome << ": " << stockDisponivel << " unidades em stock";

        // Verifica se o estoque do prato é menor ou igual a zero
        if (verificarStockPrato(ementaPratos[i].nome)) {
            cout << " (Fora de stock)";
        }
        cout << "\n";
    }
}

void Restaurante::relatorioVendasPorPrato(string nome)
{
    cout << "Relatorio de Vendas por Prato para " << nome << ":\n";
    int totalVendido = 0;
    for (const auto& pedido : pedidos) {
        if (pedido.getPrato().nome == nome) { // Comparar o nome do prato no pedido com o nome fornecido
            totalVendido += pedido.getQuantidadePrato(); // Use a função apropriada para obter a quantidade de pratos
        }
    }
    cout << "Total vendido: " << totalVendido << " unidades\n";
}

void Restaurante::rVendasPorPrato()
{
    if (ementaPratos.empty()) {
		cout << "\nA ementa esta vazia. Nao ha pratos para ver.\n";
		return;
	}

	cout << "\nEscolha o numero do prato que deseja ver:\n";
    for (size_t i = 0; i < ementaPratos.size(); ++i) {
		cout << i + 1 << ". " << ementaPratos[i].nome << " - " << ementaPratos[i].preco << " euros" << endl;
	}

	int opcao;
	cout << "Opcao: ";
	cin >> opcao;

    if (opcao >= 1 && opcao <= ementaPratos.size()) {
		relatorioVendasPorPrato(ementaPratos[opcao - 1].nome);
	}
    else {
		cout << "\nOpcao invalida!\n";
		cout << "Prato nao encontrado!\n";
	}
}

void Restaurante::relatorioVendasTotal()
{
    double totalVendas = 0;
    for (const auto& pedido : pedidos) {
		totalVendas += (pedido.getPrato().preco * pedido.getQuantidadePrato()) + (pedido.getBebida().preco * pedido.getQuantidadeBebida());
	}
	cout << "Total de Vendas: " << totalVendas << " euros\n";
}

void Restaurante::relatorioPratoMaisVendido()
{
    	int maisVendido = 0;
        for (size_t i = 0; i < vendasPorPrato.size(); ++i) {
            if (vendasPorPrato[i] > vendasPorPrato[maisVendido]) {
			maisVendido = i;
		}
	}
	cout << "Prato mais vendido: " << ementaPratos[maisVendido].nome << endl;
	cout << "Quantidade vendida: " << vendasPorPrato[maisVendido] << endl;
}

void Restaurante::relatorioPratoMenosVendido()
{
        int menosVendido = 0;
        for (size_t i = 0; i < vendasPorPrato.size(); ++i) {
            if (vendasPorPrato[i] < vendasPorPrato[menosVendido]) {
                menosVendido = i;
            }
        }
        cout << "Prato menos vendido: " << ementaPratos[menosVendido].nome << endl;
        cout << "Quantidade vendida: " << vendasPorPrato[menosVendido] << endl;
}

void Restaurante::relatorioPratoMaiorLucro()
{
    double pratoMaiorLucro = 0;
    for (size_t i = 0; i < ementaPratos.size(); ++i) {
		double lucro = (vendasPorPrato[i] * ementaPratos[i].preco) - (vendasPorPrato[i] * ementaPratos[i].preco);
        if (lucro > pratoMaiorLucro) {
			pratoMaiorLucro = lucro;
		}
	}
    cout << "Prato com maior lucro: " << ementaPratos[pratoMaiorLucro].nome << endl;
    cout << "Lucro: " << pratoMaiorLucro << endl;


}

void Restaurante::relatorioClienteMaisComprou()
{
    int maisComprou = 0;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].getNome() > clientes[maisComprou].getNome()) {
			maisComprou = i;
		}
	}
	cout << "Cliente que mais comprou: " << clientes[maisComprou].getNome() << endl;
	cout << "Telefone: " << clientes[maisComprou].getTelefone() << endl;
	cout << "Endereco: " << clientes[maisComprou].getEndereco() << endl;
    
}

bool Restaurante::verificarStockPrato(const string& nome) const
{
    for (const auto& prato : ementaPratos) {
        if (prato.nome == nome) {
            return prato.quantidadeEmStock <= 0;
        }
    }
    return true;  // Assume que o prato não está no menu (sem stock).
}


int Restaurante::lerInteiro() {
    int num;
    while (!(cin >> num)) {
        cout << "Introduza um numero valido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

/////////////////////////////PRATO////////////////////////////////////////////////////////////////////////////////////////////////
void Restaurante::adicionarPrato() {
    cout << "  _________________\n";
    cout << " |                 |\n";
    cout << " | Adicionar Prato |\n";
    cout << " |_________________|\n\n";
    Prato novoPrato;
    cin.ignore();
    cout << "\n\nNome do prato: ";
    getline(cin, novoPrato.nome);
    cout << "Preco do prato: ";
    cin >> novoPrato.preco;
    cout << "Validade do prato: ";
    cin >> novoPrato.dataValidade;
    ementaPratos.push_back(novoPrato);
    cout << fixed << setprecision(2);
    cout << "\nPrato adicionado com sucesso!\n\n";
}

void Restaurante::armazenarPrato(string nome, double preco, string dataValidade) {
    Prato novoPrato;
    novoPrato.nome = nome;
    novoPrato.preco = preco;
    novoPrato.dataValidade = dataValidade;  
    ementaPratos.push_back(novoPrato);
    cout << fixed << setprecision(2);
    cout << "\nPrato adicionado com sucesso!" << endl;
}

void Restaurante::removerPrato() {
    if (ementaPratos.empty()) {
        cout << "\nA ementa esta vazia. Nao ha pratos para remover.\n";
        return;
    }

    cout << "\nEscolha o numero do prato que deseja remover:\n";
    for (size_t i = 0; i < ementaPratos.size(); ++i) {
        cout << i + 1 << ". " << ementaPratos[i].nome << " - " << ementaPratos[i].preco << " euros" << endl;
    }

    int opcao;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao >= 1 && opcao <= ementaPratos.size()) {
        ementaPratos.erase(ementaPratos.begin() + opcao - 1);
        cout << "\nPrato removido com sucesso!\n";
    }
    else {
        cout << "\nOpcao invalida!\n Prato nao removido!\n";
    }
}

void Restaurante::verEmenta() {
    cout << "\nEmenta de Pratos\n";
    cout << "-------------------------------------------------------------\n";
    for (size_t i = 0; i < ementaPratos.size(); ++i) {
        cout << i + 1 << ". " << ementaPratos[i].nome << " - " << ementaPratos[i].preco << " euros" <<" - " << ementaPratos[i].dataValidade ;
        cout << endl;
        cout <<"-------------------------------------------------------------\n";
    }
}

void Restaurante::adicionarStockaPrato() {
    if (ementaPratos.empty()) {
        cout << "\nA ementa esta vazia. Não ha pratos para ver ou adicionar stock.\n";
        return;
    }

    cout << "\nEscolha o numero do prato que deseja adicionar stock:\n";
    for (size_t i = 0; i < ementaPratos.size(); ++i) {
        cout << i + 1 << ". " << ementaPratos[i].nome << " - Stock: " << ementaPratos[i].quantidadeEmStock << endl;
        cout << "   - Validade: " << ementaPratos[i].dataValidade << endl;
    }

    int opcao;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao >= 1 && opcao <= ementaPratos.size()) {
        cout << "\nNome do prato: " << ementaPratos[opcao - 1].nome << endl;
        cout << "Stock atual: " << ementaPratos[opcao - 1].quantidadeEmStock << endl;

        int quantidade;
        cout << "\nQuantidade a adicionar: ";
        cin >> quantidade;

        if (quantidade > 0) {
            ementaPratos[opcao - 1].quantidadeEmStock += quantidade;
            cout << "\nStock adicionado com sucesso!\n";
        }
        else {
            cout << "\nA quantidade deve ser um valor positivo.\n";
        }
    }
    else {
        cout << "\nOpção inválida!\n";
        cout << "Prato não encontrado ou stock não adicionado!\n";
    }


}

/// /////////////////////////////////CLIENTE////////////////////////////////////////////////////////////////////////////////////////////////
void Restaurante::adicionarCliente(const string& nome, const string& telefone, const string& endereco, int numCliente) {
    Cliente novoCliente(nome, telefone, endereco,numCliente);
    clientes.push_back(novoCliente);
}

void Restaurante::addCliente()
{
    cout << "                                      _______________________\n";
    cout << "                                     |                       |\n";
    cout << "                                     | Registar Novo Cliente |\n";
    cout << "                                     |_______________________|\n\n";

    int numCliente;
    string nomeCliente, telefoneCliente, enderecoCliente;

    cout << "                                     Digite o nome do cliente: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        getline(cin, nomeCliente);

        //verifica se a string contem apenas letras e espacos
        if (all_of(nomeCliente.begin(), nomeCliente.end(), [](char c) { return isalpha(c) || isspace(c); })) 
        {
            break; 
        }
        else {
            cout << "Por favor, digite um nome valido apenas com letras e espaços: ";
        }
    }
    cout << endl;
    cout << "                                     Digite o numero do cliente: ";
    while (!(cin >> numCliente)) {
        cout << "                                     Por favor, digite um numero valido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl;
    cout << "                                     Digite o telefone do cliente (9 digitos): ";
    while (true) {
        getline(cin, telefoneCliente);

        // Verifica se a string contém apenas números e tem tamanho 9
        if (all_of(telefoneCliente.begin(), telefoneCliente.end(), [](char c) { return isdigit(c); }) && telefoneCliente.size() == 9) {
            break;
        }
        else {
            cout << "                                     Por favor, digite um numero de telefone valido com 9 digitos: ";
        }
    }
    cout << endl;
    cout << "                                     Digite o endereco do cliente: ";
    getline(cin, enderecoCliente);

    cout << "\n";

    Cliente novoCliente(nomeCliente, telefoneCliente, enderecoCliente, numCliente);
    clientes.push_back(novoCliente);
    cout << "                                     Cliente adicionado com sucesso!\n\n";
}

void Restaurante::removerCliente(const string& nome) {
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->getNome() == nome) {
            it = clientes.erase(it);
            cout << "Cliente removido com sucesso.\n";
            return;
        }
    }
    cout << "Cliente nao encontrado.\n";
}

void Restaurante::apagarCliente() {
    if (clientes.empty()) {
        cout << "\nNao ha clientes registados.\n";
        return;
    }

    cout << "\nEscolha o numero do cliente que deseja remover:\n";
    for (size_t i = 0; i < clientes.size(); ++i) {
        cout << i + 1 << ". " << clientes[i].getNome() << endl;
    }

    int opcao;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao >= 1 && opcao <= clientes.size()) {
        clientes.erase(clientes.begin() + opcao - 1);
        cout << "\nCliente removido com sucesso!\n";
    }
    else {
        cout << "\nOpcao invalida!\n";
        cout << "Cliente nao removido!\n";
    }
}

void Restaurante::alterarNomeCliente(const string& nome, const string& novoNome) {
    for (auto& cliente : clientes) {
        if (cliente.getNome() == nome) {
            cliente.setNome(novoNome);
            cout << "Nome do cliente alterado com sucesso.\n";
            return;
        }
    }
    cout << "Cliente nao encontrado.\n";
}

void Restaurante::editarCliente() {
    if (clientes.empty()) {
        cout << "\nNao ha clientes registados.\n";
        return;
    }

    cout << "\nEscolha o numero do cliente que deseja editar:\n";
    for (size_t i = 0; i < clientes.size(); ++i) {
        cout << i + 1 << ". " << clientes[i].getNome() << endl;
    }

    int opcao;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao >= 1 && opcao <= clientes.size()) {
        cin.ignore();
        string novoNome;
        cout << "\nNovo nome do cliente: ";
        getline(cin, novoNome);
        clientes[opcao - 1].setNome(novoNome);
        cout << "\nNome do cliente alterado com sucesso!\n";
    }
    else {
        cout << "\nOpcao invalida!\n";
        cout << "Nome do cliente nao alterado!\n";
    }
}

void Restaurante::imprimirClientes() {
    if (clientes.empty()) {
        cout << "Nao ha clientes registados.\n";
        return;
    }
    cout << "           Clientes\n";
    cout << "--------------------------------\n";
    for (const auto& cliente : clientes) {
        cout << "Nome: " << cliente.getNome();
        cout << "\nTelefone: " << cliente.getTelefone();
        cout << "\nEndereco: " << cliente.getEndereco();
        cout << "\nNumero: " << cliente.getNumCliente();
        cout << "\n--------------------------------\n";
        

    }
}

///////////////////////////////////MENUS/////////////////////////////////////////////////////////////////////////////
void Restaurante::menuInicial()
{
    
    cout << "                                      ____________________________________________\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |             Restaurante Almada             |\n";
    cout << "                                     |____________________________________________|\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |     1. Mesa                                |\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |     2. Inserir Pratos                      |\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |     3. Adicionar stock                     |\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |     4. Remover prato do menu               |\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |     5. Relatorios(stock/vendas/etc)        |\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |     6. Registos(Cliente)                   |\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |     7. Sair                                |\n";
    cout << "                                     |                                            |\n";
    cout << "                                     |____________________________________________|\n";

    cout << "\n Opcao: ";

}

void Restaurante::menuMesa()
{
    cout << "                                        ________________________________\n";
    cout << "                                       |                                |\n";
    cout << "                                       |              Mesa              |\n";
    cout << "                                       |________________________________|\n";
    cout << "                                       |                                |\n";
    cout << "                                       |     1. Registar Pedido         |\n";
    cout << "                                       |     2. Ver Pedidos             |\n";
    cout << "                                       |     3. Tirar Fatura            |\n";
    cout << "                                       |     4. Voltar ao Menu Inicial  |\n";
    cout << "                                       |________________________________|\n";
    cout << "\n Opcao: ";

}

void Restaurante::menuEmenta()
{
    cout << "                                         ________________________________\n";
    cout << "                                        |                                |\n";
    cout << "                                        |         Adicionar Pratos       |\n";
    cout << "                                        |________________________________|\n";
    cout << "                                        |                                |\n";
    cout << "                                        |     1. Adicionar Prato         |\n";
    cout << "                                        |     2. Ver Ementa              |\n";
    cout << "                                        |     3. Voltar ao Menu Inicial  |\n";
    cout << "                                        |________________________________|\n";
    cout << "\n Opcao: ";
}

void Restaurante::menuCliente()
{
    cout << "                                          __________________________________\n";
    cout << "                                         |                                  |\n";
    cout << "                                         |            Clientes              |\n";
    cout << "                                         |__________________________________|\n";
    cout << "                                         |                                  |\n";
    cout << "                                         |     1. Registar Novo Cliente     |\n";
    cout << "                                         |     2. Remover Cliente           |\n";
    cout << "                                         |     3. Alterar nome do Cliente   |\n";
    cout << "                                         |     4. Ver Clientes              |\n";
    cout << "                                         |     5. Voltar ao Menu Inicial    | \n";
    cout << "                                         |__________________________________|\n";
    cout << "\n Opcao: ";
}

void Restaurante::menuRelatorio()
{
    cout << "                                           ___________________________________\n";
    cout << "                                          |                                   |\n";
    cout << "                                          |            Relatorios             |\n";
    cout << "                                          |___________________________________|\n";
    cout << "                                          |                                   |\n";
    cout << "                                          |     1. Stock                      |\n";
    cout << "                                          |     2. Vendas por prato           |\n";
    cout << "                                          |     3. Relatorio de vendas total  |\n";
    cout << "                                          |     4. Voltar ao Menu Inicial     |\n";
    cout << "                                          |___________________________________|\n";
    cout << "\n Opcao: ";
}

void Restaurante::entrarPrograma()
{
    for (int i = 0; i < 10; ++i) {
        cout << "\n";
    }
    // Linha decorativa
    cout << setw(86) << "*********************************************************\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    // Mensagem de boas-vindas
    cout << setw(86) << "*          Bem-vindo ao Restaurante Almada!             *\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    // Efeito de carregamento
    cout << setw(86) << "*               A carregar o sistema                    *\n";
   
    // Linha decorativa
    cout << setw(86) << "*********************************************************\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    // Aguarde por 3 segundos antes de encerrar
    cout << "\033[1;33m";
    for (int i = 0; i < 20; ++i) {
        cout  << "\r";
        cout << setw(44) << "[" << string(i, '#') << string(20 - i, ' ') << "] " << i * 5 << "%";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "\033[0m";

    // Adicionando linhas vazias após o carregamento
    for (int i = 0; i < 5; ++i) {
        cout << "\n";
    }

   
    system("cls");

    for (int i = 0; i < 10; ++i) {
        cout << "\n";
    }

  
    //ID do funcionário
    cout << setw(86) << "*********************************************************\n";
    cout << setw(86) << "*                                                       *\n";
    cout << setw(68) << "Insira o ID do funcionario: ";
// Ler o ID do funcionário
    int idFuncionario;
    cin >> idFuncionario;
  

    for (int i = 0; i < 10; ++i) {
        cout << "\n";
    }
    //verifica o ID do funcionário
    cout << "\033[1;31m";
    if (idFuncionario != 1234) {
        cout << setw(75) << "ID incorreto. A sair...\n";
        system("pause");
        system("cls");
    }
    cout << "\033[0m";

    system("cls");
    for (int i = 0; i < 10; ++i) {
        cout << "\n";
    }
    //senha do funcionário
    cout << setw(86) << "*********************************************************\n";
    cout << setw(86) << "*                                                       *\n";
    cout << setw(68) << "Insira a senha do funcionario: ";
    // Ler o semha do funcionário
    int senhaFuncionario;
    cin >> senhaFuncionario;

    cout << setw(60) << "A verificar a senha";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        //efeito de verificação
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl;

    //verifica a senha do funcionário
    cout << "\033[1;33m";

    if (senhaFuncionario != 1234) {
        cout << setw(75) << "Senha incorreta. A sair...\n";
        system("pause");
        system("cls");
    }
    cout << "\033[0m";
    system("cls");

    for (int i = 0; i < 10; ++i) {
        cout << "\n";
    }
    cout << "\033[1;33m";

    cout << setw(86) << "*****************************************************************\n";
    cout << setw(75) << "Autenticacao bem-sucedida! Bem-vindo, funcionario " << idFuncionario << "!\n";
    cout << setw(60) << "A preparar o sistema...";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "\033[0m";
    cout << endl;
}

