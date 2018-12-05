//============================================================================
// Name        : CodigoFinal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
using namespace std;
	const int capacidadInventario = 30;
	const int capacidadPedido = 10;

	string listaProductoInventario[capacidadInventario];
	int stockProductoInventario[capacidadInventario];
	int totalInventario = 0;

	int listaProductoPedido[capacidadPedido];
	int cantidadProductoPedido[capacidadPedido];
	int totalPedido = 0;

	void CargarInventario(){

		listaProductoInventario[0] = "Monitor Samsung LC27F591FDLXPE, 27 LED Curved, 1920x1080, HDMI/DP/VGA";
		stockProductoInventario[0] = 10;

		listaProductoInventario[1] = "Teclado Gamer Cybertel Twister Led Luces";
		stockProductoInventario[1] = 30;

		listaProductoInventario[2] = "Mouse Usb Gamer Dragon Mic 663 7 Luces Programable Macro";
		stockProductoInventario[2] = 60;

		listaProductoInventario[3] = "Core i3 ";
		stockProductoInventario[3] = 115;

		listaProductoInventario[4] = "Memoria Corsair Vengeance Lpx Ddr4 8gb 2400mhz Con Disipador";
		stockProductoInventario[4] = 10;

		totalInventario = 5;
	}
	void ListarProductoInventario(int posicion){

		if(posicion < 0){
			for(int i=0;i<totalInventario;i++){
				cout<<"Indice Producto: ";
				cout<<i;
				cout<<"\n";
				cout<<"Producto: ";
				cout<<listaProductoInventario[i];
				cout<<"\n";
				cout<<"Cantidad: ";
				cout<<stockProductoInventario[i];
				cout<<"\n\n";
			}
		}
		else{
			cout<<"Indice Producto: ";
			cout<<posicion;
			cout<<"\n";
			cout<<"Producto: ";
			cout<<listaProductoInventario[posicion];
			cout<<"\n";
			cout<<"Cantidad: ";
			cout<<stockProductoInventario[posicion];
			cout<<"\n\n";
		}
	}


	void Inventario(){

		int opcionMenuInventario = 0;
		do{
			cout<<"\n - Menu Inventario - \n\n";
			cout<<"1. Ingresar Producto\n";
			cout<<"2. Eliminar Producto\n";
			cout<<"3. Listar Inventario\n";
			cout<<"0. Salir\n\n";
			cout<<"Ingresa Opcion: ";
			cin>>opcionMenuInventario;

			if(opcionMenuInventario == 1){

				string producto;
				int cantidad;
				for(int i = totalInventario; i < totalInventario + 1;i++){
					cout<<"\n";
					cout<<"Indice Inventario: ";
					cout<<i;
					cout<<"\n";
					cout<<"Producto: ";
					cin>>producto;
					cout<<"Cantidad: ";
					cin>>cantidad;

					listaProductoInventario[i] = producto;
					stockProductoInventario[i] = cantidad;
				}

				totalInventario++;
			}
			else if(opcionMenuInventario == 2){

				int posicionEliminar;
				int eliminar;
				cout<<"\n";
				cout<<"Indice Inventario a eliminar: ";
				cin>>posicionEliminar;

				cout<<"\n";

				cout<<"Deseas eliminar el producto mostrado?\n\n";

				ListarProductoInventario(posicionEliminar);

				cout<<"Si = 1     No = 0\n\nOpcion: ";
				cin>>eliminar;

				if(eliminar){
					for(int i = posicionEliminar; i < totalInventario - 1;i++){
						listaProductoInventario[i] = listaProductoInventario[i+1];
						stockProductoInventario[i] = stockProductoInventario[i+1];
					}

					cout<<"\n Eliminado! \n";

					totalInventario--;

				}else cout<<"\n No fue Eliminado! \n";

			}
			else if(opcionMenuInventario == 3){
				cout<<"Lista Inventario\n\n";
				ListarProductoInventario(-1);
			}

		}while(opcionMenuInventario != 0);

	}

	void RegistrarPedido(){

		int opcionMenuPedido = 0;

		do{

			cout<<"\n - Menu Registrar Pedido - \n\n";
			cout<<"1. Agregar Producto\n";
			cout<<"2. Eliminar Producto\n";
			cout<<"3. Ver Pedido\n";
			cout<<"4. Procesar Pedido\n";
			cout<<"0. Salir\n\n";
			cout<<"Ingresa Opcion: ";
			cin>>opcionMenuPedido;

			if(opcionMenuPedido == 1){

				int indice;
				int cantidad;

				for(int i = totalPedido; i < totalPedido + 1;i++){
					cout<<"\n";
					cout<<"Indice Pedido: ";
					cin>>indice;
					cout<<"Cantidad: ";
					cin>>cantidad;

					listaProductoPedido[i] = indice;
					cantidadProductoPedido[i] = cantidad;
				}

				totalPedido++;

			}
			else if(opcionMenuPedido == 2){

				int posicionEliminar;
				int eliminar;
				int posicionProducto;

				cout<<"\n";
				cout<<"Indice Pedido a eliminar: ";
				cin>>posicionEliminar;

				cout<<"\n";

				cout<<"Deseas eliminar del pedido el producto mostrado?\n\n";

				posicionProducto = listaProductoPedido[posicionEliminar];

				ListarProductoInventario(posicionProducto);

				cout<<"Si = 1     No = 0\n\nOpcion: ";
				cin>>eliminar;

				if(eliminar){

					for(int i = posicionEliminar; i < totalPedido - 1;i++){
						listaProductoPedido[i] = listaProductoPedido[i+1];
						cantidadProductoPedido[i] = cantidadProductoPedido[i+1];
					}

					totalPedido--;

				}else cout<<"\n No fue Eliminado! \n";

			}
			else if(opcionMenuPedido == 3){

				int posicionProducto;

				cout<<"\n Pedido\n\n";

				if(totalPedido > 0){
					for(int i=0;i<totalPedido;i++){
						cout<<"Indice Pedido: ";
						cout<<i;
						cout<<"\n";

						posicionProducto = listaProductoPedido[i];

						cout<<"Producto: ";
						cout<<listaProductoInventario[posicionProducto];
						cout<<"\n";
						cout<<"Cantidad: ";
						cout<<cantidadProductoPedido[i];
						cout<<"\n\n";
					}
				}else cout<<"Vacio! \n";

			}
			else if(opcionMenuPedido == 4){
				cout<<"4";
			}

		}while(opcionMenuPedido != 0);
	}


	int main(int argc, char** argv) {

		CargarInventario();
		cout<<"-Productos de la empresa-"<<endl;
        cout<<"1.-Monitor Samsung LC27F591FDLXPE, 27 LED Curved, 1920x1080, HDMI/DP/VGA"<<endl;
        cout<<"2.-Teclado Gamer Cybertel Twister Led Luces"<<endl;
        cout<<"3.-Mouse Usb Gamer Dragon Mic 663 7 Luces Programable Macro"<<endl;
        cout<<"4.-Core i3"<<endl;
        cout<<"5.-Memoria Corsair Vengeance Lpx Ddr4 8gb 2400mhz Con Disipador"<<endl;
		int opcionMenuPrincipal = 0;

		do{
			cout<<"\n--Bienvenido a Electrodomax--\n";
                        cout<<"---------------------------------";
			cout<<"\n - Menu Principal - \n\n";
			cout<<"1. Registrar Pedido\n";
			cout<<"2. Inventario\n";
			cout<<"0. Salir\n\n";
			cout<<"Ingresa Opcion: ";
			cin>>opcionMenuPrincipal;

			if(opcionMenuPrincipal == 1){
				RegistrarPedido();
			}
			else if(opcionMenuPrincipal == 2){
				Inventario();
			}

		}while(opcionMenuPrincipal != 0);
	return 0;
}
//gracias
