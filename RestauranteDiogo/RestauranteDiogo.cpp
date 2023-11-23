#include "Restaurante.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <limits>//numeric_limits
#include <cstdlib>  // system("cls")
#include <ctime>    

using namespace std;



int main() {
    Restaurante r;
    vector<Cliente> clientes;
    vector<Pedido> pedidos;
    vector<Prato> ementaPratos;
    r.entrarPrograma();
    system("color 8F");


    int opcao;

    while (true) {
        system("cls");
        r.menuInicial();
        opcao = r.lerInteiro();


        switch (opcao) {
        case 1: {
            int opcaoMesa;
            system("cls");
            do {
                r.menuMesa();
                opcaoMesa = r.lerInteiro();

                switch (opcaoMesa) {
                case 1:
                    // registrar pedido
                    r.inserirPedidoCliente();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    //  ver pedido
                    r.verPedidoCliente();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    r.imprimirRecibo();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    cout << "\nVoltando ao Menu Inicial...\n";
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Opçao invalida. Tente novamente.\n";
                    system("pause");
                    system("cls");
                    break;
                }
            } while (opcaoMesa != 4); 
            break;
        }
        case 2: {
            system("cls");
            int opcaoEmenta;
            do {
                r.menuEmenta();
                opcaoEmenta = r.lerInteiro();

                switch (opcaoEmenta) {
                case 1:
                    // adicionar prato à ementa
                    r.adicionarPrato();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    // ver ementa
                    r.verEmenta();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    cout << "Voltando ao Menu Inicial...\n";
                    system("pause");
                    system("cls");
                    break;                
                default:
                    cout << "Opçao invalida. Tente novamente.\n";
                    system("pause");
                    system("cls");
                    break;
                }
            } while (opcaoEmenta != 3);
            break;
        }
        case 3: {
            //  adicionar stock
            system("cls");
            r.adicionarStockaPrato();
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            // remover prato do menu
            r.removerPrato();
            system("pause");
            system("cls");
            break;
        }
        case 5: {//RELATORIOS
                system("cls");
                int opcaoRelatorio;
                do {
                    r.menuRelatorio();
                    opcaoRelatorio = r.lerInteiro();

                    switch (opcaoRelatorio) {
                    case 1:
                        // stock
                        r.relatorioStock();
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        // vendas por prato 
                        r.rVendasPorPrato();
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        // relatório de vendas total
                        r.relatorioVendasTotal();
                        r.relatorioPratoMaisVendido();
                        r.relatorioPratoMenosVendido();
                        r.relatorioClienteMaisComprou();
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        cout << "Voltando ao Menu Inicial...\n";
                        system("pause");
                        system("cls");
                        break;
                    default:
                        cout << "Opcao invalida. Tente novamente.\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                } while (opcaoRelatorio != 4);
                break;
            }
        
        case 6: {
            // Registro de cliente
            int opcaoCliente;
            system("cls");
            do {
                r.menuCliente();
                opcaoCliente = r.lerInteiro();

                switch (opcaoCliente) {
                case 1: {// Registrar Novo Cliente       
                    r.addCliente();
                    system("pause");
                    system("cls");
                    break;
                }
                case 2: { // Remover Cliente     
                    r.apagarCliente();   
                    system("pause");
                    system("cls");
                    break;
                }
                case 3: { // Alterar nome do Cliente   
                    r.editarCliente();     
                    system("pause");
                    system("cls");
                    break;
                }
                case 4: { // Imprimir clientes  
                    r.imprimirClientes();  
                    system("pause");
                    system("cls");
                    break;
                }
                case 5:
                    cout << "\nVoltando ao Menu Inicial...\n";
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Opcao invalida. Tente novamente.\n";
                    system("pause");
                    system("cls");
                    break;
                }
            } while (opcaoCliente != 5);
            break;
        }

        case 7: {
           cout << "A sair ...\n";
           system("pause");
           system("cls");
            return 0;
        }
        default: {
            cout << "Opcao invalida. Tente novamente.\n";
            system("pause");
            system("cls");
            break;
        }
        }
    }

}




    


  


 

