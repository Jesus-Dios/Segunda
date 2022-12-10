#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

int opcion, id = 1, z, op, contleer = 0, contleer2 = 0, in = 0;
bool a = true;

struct videojuego {
	int alo;
	string nombres, clasificaciones, caracteristicas, descripcion, genero;
	float precio, impuesto, total;
}juego[100];

void agregar();
void lista();
void modificar();
void eliminar();
void guardararchivo();
void leerarchivo();

void main()
{
	if (in == 0)
	{
		leerarchivo();
	}
	while (a)
	{
		cout << "\t\t=========Welcome========" << endl;
		cout << "\t\t======Menu==== = " << endl;
		cout << "\t1-.Agregar Articulo" << endl;
		cout << "\t2-.Modificar Articulo" << endl;
		cout << "\t3-.Eliminar Articulo" << endl;
		cout << "\t4-.Lista de Articulos" << endl;
		cout << "\t5-.Limpiar Pantalla" << endl;
		cout << "\t6-.Salir" << endl;
		cout << "\t\Ingrese una opcion: ";
		cin >> opcion;
		cin.ignore();

		switch (opcion)
		{
		case 1:
		{
			agregar();
			break;
		}
		case 2:
		{
			modificar();
			break;
		}
		case 3:
		{
			guardararchivo();
			eliminar();
			break;
		}
		case 4:
		{
			lista();
			break;
		}
		case 5:
		{
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			guardararchivo();
			a = false;
			cout << "saliendo" << endl;
			break;

		}
		default:
		{
			cout << "opcion Incorrecta" << endl;
			break;
		}
		}
	}
	system("pause");
}

void agregar()
{
	system("cls");
	cout << "Cuantos juegos deseas dar de alta?: "; cin >> z;
	cin.ignore();
	for (int i = 0; i < z; i++)
	{
		if ((juego[i].nombres).empty())
		{
			cout << "Nombre del videojuego que desea dar de alta: ";
			getline(cin, (juego[i].nombres));
			cout << "Ingrese el anio de lanzamiento: "; cin >> (juego[i].alo);
			cin.ignore();
			cout << "Ingrese la CLasificacion del videojuego:";
			getline(cin, (juego[i].clasificaciones));
			cout << "Ingresa las caracteristicas del videjuego: ";
			getline(cin, (juego[i].caracteristicas));
			cout << "Ingresa la descripcion del videojuego: ";
			getline(cin, (juego[i].descripcion));
			cout << "Ingrese el genero del videojuego: ";
			getline(cin, (juego[i].genero));
			cout << "Ingrese el precio unitario: ";
			cin >> (juego[i].precio);
			(juego[i].impuesto) = (juego[i].precio) * 0.13;
			cin.ignore();
			cout << "El impuesto es de: " << (juego[i].impuesto) << endl;
			(juego[i].total) = (juego[i].precio) + (juego[i].impuesto);
			cin.ignore();
			cout << "El precio total es: " << (juego[i].total) << endl;
			cin.ignore();
		}
		else {
			z++;
		}
	}
}

void lista()
{
	system("cls");
	cout << "Lista de articulos vigentes: " << endl;
	for (int i = 0; i < z; i++)
	{
		cout << id + i << ": " << juego[i].nombres << endl;
		cout << "\tAnio: " << juego[i].alo << endl;
		cout << "\tClasificacion: " << juego[i].clasificaciones << endl;
		cout << "\tCaracteristicas: " << juego[i].caracteristicas << endl;
		cout << "\tDescripcion: " << juego[i].descripcion << endl;
		cout << "\tGenero: " << juego[i].genero << endl;
		cout << "\tPrecio Unitario: " << juego[i].precio << endl;
		cout << "\tImpuesto: " << juego[i].impuesto << endl;
		cout << "\tPrecio Total: " << juego[i].total << endl;
	}
}

void modificar()
{
	string strJuego, NueJuego, NueClas, NueCaract, NueDescri, NueGen;
	int dato, NueAlo;
	float NuePrecio;
	bool encontrarJuego = false, b = true;

	cout << "Ingrese el nombre que desea modificar: ";
	cin >> strJuego;

	for (int i = 0; i < 100; i++)
	{
		if (juego[i].nombres == strJuego)
		{
			cout << "\tJuego:" << id << juego[i].nombres << endl;
			cout << "\tAnio: " << juego[i].alo << endl;
			cout << "\tClasificacion: " << juego[i].clasificaciones << endl;
			cout << "\tCaracteristicas: " << juego[i].caracteristicas << endl;
			cout << "\tDescripcion: " << juego[i].descripcion << endl;
			cout << "\tGenero: " << juego[i].genero << endl;
			cout << "\tPrecio Unitario: " << char(36) << juego[i].precio << endl;
			cout << "\tImpuesto: " << char(36) << juego[i].impuesto << endl;
			cout << "\tPrecio Total: " << char(36) << juego[i].total << endl;
			encontrarJuego = true;

			while (b)
			{
				cout << "Que dato deaseas modificar?" << endl;
				cout << "1. Nombre" << endl;
				cout << "2. Anio" << endl;
				cout << "3. Clasificacion" << endl;
				cout << "4. Caracteristicas" << endl;
				cout << "5. Descripcion" << endl;
				cout << "6. Genero" << endl;
				cout << "7. Precio unitario" << endl;
				cout << "8. Salir" << endl;
				cout << "Eliga una opcion" << endl;
				cin >> dato;

				switch (dato)
				{
				case 1:
				{
					cout << "nuevo nombre del juego: ";
					cin >> NueJuego;
					cin.ignore();
					(juego[i].nombres) = NueJuego;
					break;
				}
				case 2:
				{
					cout << "nuevo anio del juego: ";
					cin >> NueAlo;
					cin.ignore();
					(juego[i].alo) = NueAlo;
					break;
				}
				case 3:
				{
					cout << "nueva clasifiacion: ";
					cin >> NueClas;
					cin.ignore();
					(juego[i].clasificaciones) = NueClas;
					break;
				}
				case 4:
				{
					cout << "nuevas caracteristicas: ";
					cin >> NueCaract;
					cin.ignore();
					(juego[i].caracteristicas) = NueCaract;
					break;
				}
				case 5:
				{
					cout << "nueva descripcion: ";
					cin >> NueDescri;
					cin.ignore();
					(juego[i].descripcion) = NueDescri;
					break;
				}
				case 6:
				{
					cout << "nuevo genero: ";
					cin >> NueGen;
					cin.ignore();
					(juego[i].genero) = NueGen;
					break;
				}
				case 7:
				{
					cout << "nuevo precio unitario: ";
					cin >> NuePrecio;
					cin.ignore();
					(juego[i].precio) = NuePrecio;
					break;
				}
				case 8:
				{
					b = false;
					break;
				}
				default:
				{
					cout << "Opcion Incorrecta" << endl;
					break;
				}
				}
			}
		}
	}
	if (encontrarJuego == false)
	{
		system("cls");
		cout << "No se encontraron juegos con el nombre: " << strJuego << endl;
	}
}

void eliminar()
{
	int elim, o;

	cout << "Nombre del juego que desea eliminar: ";
	cin >> elim;
	if (elim == 0)
	{
		cout << "No existe ese nombre de juego" << endl;
	}
	else
	{
		elim = elim - 1;

		if (elim >= z)
		{
			cout << "No se ha registrado ese nombre de juego" << endl;
		}
		else
		{
			cout << "Quieres borrar este juego? ----- 1. aceptar/2.cancelar: ";
			cin >> o;
			if (o == 1)
			{
				(juego[elim].nombres) = (juego[elim].nombres).empty();
				(juego[elim].alo) = 0;
				(juego[elim].clasificaciones) = (juego[elim].clasificaciones).empty();
				(juego[elim].caracteristicas) = (juego[elim].caracteristicas).empty();
				(juego[elim].descripcion) = (juego[elim].descripcion).empty();
				(juego[elim].genero) = (juego[elim].genero).empty();
				(juego[elim].impuesto) = 0;
				(juego[elim].precio) = 0;
				(juego[elim].total) = 0;
				cout << "\nBorrado correctamente" << endl;
			}
		}
	}
}

void leerarchivo()
{
	{
		int contleer = 0;
		char c;
		string texto;
		ifstream archivo("juegos.txt", ios::in);
		if (archivo.is_open())
		{

			while (!archivo.eof())
			{
				getline(archivo, texto);
				contleer2++;
				if (contleer2 == 2)
				{
					juego[contleer].nombres = texto;

				}
				if (contleer2 == 3)
				{
					istringstream(texto) >> juego[contleer].alo;
				}
				if (contleer2 == 4)
				{
					juego[contleer].clasificaciones = texto;
				}
				if (contleer2 == 5)
				{
					juego[contleer].caracteristicas = texto;
				}
				if (contleer2 == 6)
				{
					juego[contleer].descripcion = texto;
				}
				if (contleer2 == 7)
				{
					juego[contleer].genero = texto;
				}
				if (contleer2 == 8)
				{
					istringstream(texto) >> juego[contleer].precio;
				}
				if (contleer2 == 9)
				{
					istringstream(texto) >> juego[contleer].impuesto;
				}
				if (contleer2 == 10)
				{
					istringstream(texto) >> juego[contleer].total;
					contleer2 = 0;
					contleer++;
					z++;
				}

			}

			archivo.close();

		}
	}
}

void guardararchivo()
{
	ofstream archivo;
	archivo.open("juegos.txt", ios::out);
	for (int i = 0; i < z; i++)
	{
		if (archivo.fail())
		{
			cout << "ERROR NO SE PUDO CREAR";
			exit(1);
		}
		if (!juego[i].nombres.empty())
		{
			archivo << "Numero de juego " << i + 1 << endl;
			archivo << juego[i].nombres << endl;
			archivo << juego[i].alo << endl;
			archivo << juego[i].clasificaciones << endl;
			archivo << juego[i].caracteristicas << endl;
			archivo << juego[i].descripcion << endl;
			archivo << juego[i].genero << endl;
			archivo << juego[i].precio << endl;
			archivo << juego[i].impuesto << endl;
			archivo << juego[i].total << endl;
		}
	}
}