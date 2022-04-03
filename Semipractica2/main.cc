#include <iostream>
#include "HashTable.h"
//#include "List.h"
#include "Block.h"
#include "fdModulo.h"
#include "fdSuma.h"
#include "fdPseudoaleatoria.h"
#include "feLineal.h"
#include "feCuadratica.h"
#include "feDobleDispersion.h"
#include "feRedispersion.h"


using Key = long; // Establecemos Key como tipo long

int main() {

    HashTable<Key> *table;
    DispersionFunction<Key> *fd;
    ExplorationFunction<Key> *fe = nullptr;

    unsigned SizeTable = 0, tDispersion = 0, fDispersion = 0; // Apartado A
    unsigned BlockSize = 0, fExploration = 0; // Apartado B
    unsigned option = 0; // Menú
    bool verifica = true;
	Key element;

    std::cout << "[BÚSQUEDA POR DISPERSIÓN]" << std::endl;
    std::cout << "Tamaño de la tabla: ";
    std::cin >> SizeTable;

    std::cout << "Función de dispersión (1-> fdModulo. 2-> fdSuma. 3-> fdPseudoaleatoria):" << std::endl;
    std::cin >> fDispersion;
    while (verifica) {
        switch (fDispersion) {
            case 1:
                fd = new fdModulo<Key>(SizeTable);
                verifica = false;
			    break;

            case 2:
			    fd = new fdSuma<Key>(SizeTable);
                verifica = false;
                break;

            case 3:
				fd = new fdPseudoaleatoria<Key>(SizeTable);
                verifica = false;
                break;

            default:
                break;

	    }
        if (verifica) {
            std::cout << "ERROR Introduce un tipo correcto: ";
            std::cin >> fDispersion;
        }
    }
	verifica = true;


	std::cout << "Técnica de dispersión (1-> Cerrada. 2-> Abierta):" << std::endl;
    std::cin >> tDispersion;
    while (verifica) {
        if (tDispersion != 1 && tDispersion != 2) {
            std::cout << "ERROR Introduce un tipo correcto: ";
            std::cin >> tDispersion;
			verifica = true;
        } else {
			verifica = false;
		}
    }
	verifica = true;

	
	if (tDispersion == 1) {
		std::cout << "Has elegido la técnica de dispersión [CERRADA]" << std::endl;
		std::cout << "Tamaño del bloque: ";
    	std::cin >> BlockSize;

		std::cout << "Función de exploración (1-> feLineal. 2-> feCuadratica. 3-> feDobleDispersion. 4-> feRedispersion):" << std::endl;
    	std::cin >> fExploration;
    	while (verifica) {
        	switch (fExploration) {
            	case 1:
					fe = new feLineal<Key>;
                	verifica = false;
			    	break;

            	case 2:
					fe = new feCuadratica<Key>;
                	verifica = false;
			    	break;

				case 3:
					fe = new feDobleDispersion<Key>(fd);
                	verifica = false;
			    	break;

				case 4:
					fe = new feRedispersion<Key>;
                	verifica = false;
			    	break;

            	default:
                	break;
			}
        	if (verifica) {
            	std::cout << "ERROR Introduce un tipo correcto: ";
            	std::cin >> fExploration;
        	}
    	}
		verifica = true;
	} else {
		std::cout << "Has elegido la técnica de dispersión [ABIERTA]" << std::endl;
	}

	table = new HashTable<Key> (SizeTable, fd, fe, BlockSize);

	switch (tDispersion) {
        case 1:
			std::cout << "QUE EMPIECE LA MAGIA" << std::endl;
			table->EstablishTable(1);
			//table.table_ = new Block<Key>;
            verifica = false;
			break;

        case 2:
			//table.EstablishTable(2);
			std::cout << "ELECCIÓN NO DISPONIBLE" << std::endl;
			//table.table_ = new List<Key>; 
            verifica = false;
            break;
        default:
            break;

	}
	verifica = true;

	std::cout << "[MENU]" << std::endl;
	while (verifica) {
		std::cout << "0 - Finalizar" << std::endl;
		std::cout << "1 - Insertar valores" << std::endl;
		std::cout << "2 - Buscar valores" << std::endl;
		std::cout << "Escoja una opción: ";
		std::cin >> option;

		switch (option) {
		case 0:
			verifica = false;
			break;
		case 1:
			std::cout << "Elemento a introducir: ";
			std::cin >> element;
			if (table->Insert(element)) {
				std::cout << "✔ Introducido correctamente ✔ [" << element << "]" << std::endl;
			} else {
				std::cout << "X ERROR. No se ha podido introducir X [" << element << "]" << std::endl;
			}
			break;

		case 2:
			std::cout << "Elemento a localizar: ";
			std::cin >> element;
			if (table->Search(element)) {
				std::cout << "✔ Hemos encontrado el elemento ✔ [" << element << "]" << std::endl;
			} else {
				std::cout << "X No hemos encontrado el elemento X [" << element << "]" << std::endl;
			}
			break;

		default:
			std::cout << "Opción no válida. Vuelve a intentarlo..." << std::endl;
			break;
		}

		if (!verifica) {
			table->Print();
		}
		
	}

	delete table;

}