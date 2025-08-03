#include <iostream>
#include <iomanip>
using namespace std;

// Esta función calcula y muestra la solución óptima del problema
void calcularSolucionOptima(double precioDeVentaMesa,
                            double precioDeVentaSilla,
                            int coeficienteMesaHoras,
                            int coeficienteSillaHoras)
{
    // Validación básica
    if (precioDeVentaMesa <= 0 || precioDeVentaSilla <= 0 ||
        coeficienteMesaHoras <= 0 || coeficienteSillaHoras <= 0)
    {
        cout << "Error: Datos insuficientes o no válidos. Asegúrese de ingresar los precios y restricciones correctamente.\n";
        return;
    }

    // Restricciones fijas del problema (según el enunciado)
    const int maxHorasCarpinteria = 240;
    const int maxHorasPintura = 100;
    const int maxSillas = 60;

    // Coeficientes fijos de uso de recursos por producto
    const int horasCarpinteriaPorMesa = 4;
    const int horasCarpinteriaPorSilla = 3;
    const int horasPinturaPorMesa = 2;
    const int horasPinturaPorSilla = 1;

    int mejorCantidadMesas = 0;
    int mejorCantidadSillas = 0;
    double gananciaMaxima = 0.0;

    // Búsqueda exhaustiva en el espacio de soluciones
    for (int mesas = 0; mesas <= maxHorasCarpinteria / horasCarpinteriaPorMesa; mesas++)
    {
        for (int sillas = 0; sillas <= maxSillas; sillas++)
        {
            int totalCarpinteria = horasCarpinteriaPorMesa * mesas + horasCarpinteriaPorSilla * sillas;
            int totalPintura = horasPinturaPorMesa * mesas + horasPinturaPorSilla * sillas;

            if (totalCarpinteria <= maxHorasCarpinteria &&
                totalPintura <= maxHorasPintura)
            {
                double ganancia = precioDeVentaMesa * mesas + precioDeVentaSilla * sillas;

                if (ganancia > gananciaMaxima)
                {
                    gananciaMaxima = ganancia;
                    mejorCantidadMesas = mesas;
                    mejorCantidadSillas = sillas;
                }
            }
        }
    }

    // Mostrar resultado
    cout << fixed << setprecision(2);
    cout << "\nSolución óptima:\n";
    cout << "Número de mesas a fabricar: " << mejorCantidadMesas << endl;
    cout << "Número de sillas a fabricar: " << mejorCantidadSillas << endl;
    cout << "Ganancia máxima: $" << gananciaMaxima << endl;
}
