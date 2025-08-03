#include <iostream>
using namespace std;

// Función que permite ingresar restricciones de producción
void ingresarRestricciones(int &coeficienteMesaHoras, int &coeficienteSillaHoras) {
    do {
        cout << "Ingrese el coeficiente de horas de carpinteria por cada MESA: ";
        cin >> coeficienteMesaHoras;
        if (coeficienteMesaHoras <= 0)
            cout << "El coeficiente debe ser un valor positivo.\n";
    } while (coeficienteMesaHoras <= 0);

    do {
        cout << "Ingrese el coeficiente de horas de carpinteria por cada SILLA: ";
        cin >> coeficienteSillaHoras;
        if (coeficienteSillaHoras <= 0)
            cout << "El coeficiente debe ser un valor positivo.\n";
    } while (coeficienteSillaHoras <= 0);

    cout << "\nRestricciones registradas correctamente:\n";
    cout << "Mesa: " << coeficienteMesaHoras << " h de carpinteria\n";
    cout << "Silla: " << coeficienteSillaHoras << " h de carpinteria\n";
}
