#include <iostream>

/* Osservazioni 
 *
 * - Arrays
 * Gli arrays hanno una disposizione degli elementi in memoria come segue:
 *
 * ad (double: gli elementi hanno una dimensione di 8 bytes):  
 *     |      ad[0]      |      ad[1]      |      ad[2]      |      ad[3]      | 
 *     ^                 ^                 ^                 ^                 
 *   base             base+8             base+16           base+24
 *
 * af (float: gli elementi hanno una dimensione di 4 bytes):  
 *     |      af[0]      |      af[1]      |      af[2]      |      af[3]      |      .....
 *     ^                 ^                 ^                 ^                 ^
 *   base             base+4             base+8           base+16            base+24    .....
 *
 * ai (int: gli elementi hanno una dimensione di 4 bytes):  
 *     |      ai[0]      |      ai[1]      |      ai[2]      |  
 *     ^                 ^                 ^                 
 *   base             base+4             base+8           
 *
 * Questa disposizione è confermata dal programma (che mostra gli indirizzi in esadecimale).
 *
 * - Scalari
 * Utilizzando il compilatore clang, si osserva che l'istruzione 
 *     (&y)[1] = 0;
 * ha un impatto sul valore di x, che risulta essere uguale a 0. La cosa non si verifica usando gcc.
 *
 * Al di là delle differenze fra i compilatori, l'istruzione qui sopra è errata poiché la variabile y è trattata come un array, sebbene sia uno scalare.
 * La sintassi di estrazione dell'indirizzo (&y) e di indicizzazione [] lo permette; tuttavia, l'effetto è di scrivere il valore 0 sul secondo elemento di y, elemento che si trova
 * è al di là della memoria allocata per y. Nel caso di clang, evidentemente la memoria allocata per la variabile x è contigua e immediatamente successiva a quella per y, e quindi il valore
 * di x risulta modificato in 0. Nel caso di gcc, la variabile x è allocata in un'area di memoria non contigua a quella per y, e quindi l'istruzione qui sopra non ha un effetto su x. 
 * Anche in questo caso, tuttavia, ha l'effetto di corrompere un'area di memoria non riservata a y.
 *
 */
 
int main(void)
{
    // Arrays
    double ad[4] = { 0.0, 1.1, 2.2, 3.3 };
    float af[8] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    int ai[3] = { 0, 1, 2 };

	// Display addresses of the elements of ad
	std::cout << "Array of double - sizeof(double) = " << sizeof(double) << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "&ad[" << i << "] = " <<  &ad[i] << std::endl;
    }
    std::cout << std::endl;

	// Display addresses of the elements of af
	std::cout << "Array of float - sizeof(float) = " << sizeof(float) << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << "&af[" << i << "] = " << &af[i] << std::endl;
    }
    std::cout << std::endl;

	// Display addresses of the elements of ai
	std::cout << "Array of int - sizeof(int) = " << sizeof(int) << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "&ai[" << i << "] = " << &ai[i] << std::endl;
    }
    std::cout << std::endl;

    // Scalars
    int x = 1;
    float y = 1.1;

    // Memory corruption (always present, but visible on x cd only when compiling with clang)
    (&y)[1] = 0;
    std::cout << "x = " << x << std::endl;

    return 0;
}
