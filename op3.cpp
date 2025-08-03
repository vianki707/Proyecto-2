#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Restriccion {
    double x1, x2, resultado;
    char signo; // '<' para <=, '=' para =, '>' para >=
};
// Función optimizar
vector<Restriccion> restricciones;
double P1 = 0, P2 = 0;

// Calcula intersección entre dos restricciones
bool calcularInterseccion(const Restriccion& r1, const Restriccion& r2, double& x1, double& x2) {
    double det = r1.x1 * r2.x2 - r2.x1 * r1.x2;
    if (fabs(det) < 1e-8) return false; // Líneas paralelas
    x1 = (r1.resultado * r2.x2 - r2.resultado * r1.x2) / det;
    x2 = (r1.x1 * r2.resultado - r2.x1 * r1.resultado) / det;
    return true;
}

// Verifica si el punto cumple con todas las restricciones
bool esFactible(double x1, double x2) {
    for (const auto& r : restricciones) {
        double izquierda = r.x1 * x1 + r.x2 * x2;
        if (r.signo == '<' && izquierda > r.resultado + 1e-6) return false;
        if (r.signo == '>' && izquierda < r.resultado - 1e-6) return false;
        if (r.signo == '=' && fabs(izquierda - r.resultado) > 1e-6) return false;
    }
    return true;
}

// Opción 3: Calcular solución óptima
void calcularSolucionOptima() {
    vector<pair<double, double>> puntosFactibles;
    // Busca el espacio de soluciones factibles
    for (size_t i = 0; i < restricciones.size(); i++) {
        for (size_t j = i + 1; j < restricciones.size(); j++) {
            double x1, x2;
            if (calcularInterseccion(restricciones[i], restricciones[j], x1, x2)) {
                if (esFactible(x1, x2)) {
                    puntosFactibles.emplace_back(x1, x2);
                }
            }
        }
    }
    // Agregar el origen si es factible
    if (esFactible(0, 0)) {
        puntosFactibles.emplace_back(0, 0);
    }

    // Evaluar función objetivo Z = fx1*x1 + fx2*x2
    double zMax = -numeric_limits<double>::infinity();
    double optX1 = 0, optX2 = 0;
    for (const auto& punto : puntosFactibles) {
        double x1 = punto.first;
        double x2 = punto.second;
        double z = P1 * x1 + P2 * x2;
        if (z > zMax) {
            zMax = z;
            optX1 = x1;
            optX2 = x2;
        }
    }
    if (puntosFactibles.empty()) {
        cout << "No hay soluciones factibles.\n";
    } else {
        cout << "Z máxima = " << zMax << " en (x1 = " << optX1 << ", x2 = " << optX2 << ")\n";
    }
}

// Entrada manual de datos para pruebas
void cargarDatosPrueba() {
    // Restricción 1: funcion optimizar = r1
    Restriccion r1;
    r1.x1 = 2; r1.x2 = 1; r1.resultado = 18; r1.signo = '<';
    restricciones.push_back(r1);

    // Restricción 2
    Restriccion r2;
    r2.x1 = 2; r2.x2 = 3; r2.resultado = 42; r2.signo = '<';
    restricciones.push_back(r2);

    // Restricción 3
    Restriccion r3;
    r3.x1 = 3; r3.x2 = 1; r3.resultado = 24; r3.signo = '<';
    restricciones.push_back(r3);

    // Función optimizar
    P1 = 3;
    P2 = 2;
}
