#include <iostream>
#include "op4.cpp"
#include "op2.cpp"
using namespace std;



bool esNegativo(double precioDeVenta){
    if(precioDeVenta<0){
        return true;
    }return false;
}   


int main()
{

    //se declaran las variables que se van a utilizar
    int opcion, coeficienteSillaHoras, coeficienteMesaHoras, coeficiente; 
    double precioDeVentaSilla, precioDeVentaMesa;


    do
    {
        cout << "\n*******MENU********" << endl;
        cout << "Opcion 1: Ingreso de precios de venta" << endl;
        cout << "Opcion 2: Ingreso de restricciones de produccion" << endl;
        cout << "Opcion 3: Ingreso de la funcion de ganancia" << endl;
        cout << "Opcion 4: Calculo de la solucion optima" << endl;
        cout << "Opcion 5: Solucion grafica del problema de optimizacion" << endl;
        cout << "Opcion 6: Salir del programa" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {   
            cout<<"Ingrese el precio de venta de las sillas"<<endl;    
            
            do{
                cin>>precioDeVentaSilla;
                if(esNegativo(precioDeVentaSilla)){
                cout<<"El precio debe ser positivo";
            }
            }while(precioDeVentaSilla<0);

            cout<<"Ingrese el precio de venta de las mesas"<<endl;    

            do{
                cin>>precioDeVentaMesa;
                if(esNegativo(precioDeVentaMesa)){
                cout<<"El precio debe ser positivo";
            }
            }while(precioDeVentaMesa<0);

            cout<<"Los precios fueron registrados: Mesas USD "<<precioDeVentaMesa<<" y sillas USD "<<precioDeVentaSilla;
        }
        break;
        case 2:
        {
            ingresarRestricciones(coeficienteMesaHoras, coeficienteSillaHoras);
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
             calcularSolucionOptima(precioDeVentaMesa,
                           precioDeVentaSilla,
                           coeficienteMesaHoras,
                           coeficienteSillaHoras);
        }
        break;
        case 5:
        {
        }
        break;
        case 6:
        {
            cout << "Gracias por usar el programa" << endl;
        }
        break;
        default:
        {
            cout << "La opcion debe estar entre 1 y 6" << endl;
        }
        }

    } while (opcion != 6);

    return 0;
}