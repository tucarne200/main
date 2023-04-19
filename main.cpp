#include <iostream>
#include <cmath>
#define PI 3.141592
#define Gm 9.81
#define Gp 32.174

using namespace std;

void msge(string mensaje){
    cout << mensaje << endl;
}

void msg(string mensaje){
    cout << mensaje;
}

double alturaMaxima (double v0, double theta){
  
    theta = theta * M_PI / 180;// Convertimos el ángulo de grados a radianes

    double h = (v0 * v0 * sin(theta) * sin(theta)) / (2 * Gm);// Calculamos la altura maxima

    return h;//retornamos valor final/resultado
}

double tiempoDeVuelo(double v0, double theta) {

    theta = theta * M_PI / 180;// Convertimos el ángulo de grados a radianes

    double t = (2 * v0 * sin(theta)) / Gm;// Calculamos el tiempo de vuelo

    return t;//retornamos valor final/resultado
}

double alcanceMaximo(double v0, double theta) {
    
    theta = theta * M_PI / 180;// Convertimos el ángulo de grados a radianes

    double R = (v0 * v0 * sin(2 * theta)) / Gm;// Calculamos el alcance maximo

    return R;//retornamos valor final/resultado
}

double velocidadHorizontal(double v0, double theta) {
    
    theta = theta * M_PI / 180;// Convertimos el ángulo de grados a radianes

    double Vx = v0 * cos(theta);    // Calculamos la velocidad horizontal

    return Vx;//retornamos valor final/resultado
}

double velocidadVertical(double v0, double theta, double t) {
    
    theta = theta * M_PI / 180;// Convertimos el ángulo de grados a radianes
    
    double Vy = v0 * sin(theta) - Gm * t;// Calculamos la velocidad vertical

    return Vy;//retornamos valor final/resultado
}

double magnitudVelocidad(double Vx, double Vy) {
    
    double V = sqrt(pow(Vx, 2) + pow(Vy, 2));// Calculamos la magnitud de la velocidad

    return V;//retornamos valor final/resultado
}

void tiroParabolico(double v0, double theta) {
    
    double t = tiempoDeVuelo(v0, theta);// Calculamos el tiempo de vuelo

    double h = alturaMaxima(v0, theta);// Calculamos la altura máxima

    double R = alcanceMaximo(v0, theta);// Calculamos el alcance horizontal

    double Vx = velocidadHorizontal(v0, theta);// Calculamos la velocidad horizontal

    double Vy_max = velocidadVertical(v0, theta, t/2);// Calculamos la velocidad vertical en el punto maximo

    double V_max = magnitudVelocidad(Vx, Vy_max);// Calculamos la magnitud de la velocidad en el punto maximo

    // Mostramos los resultados
    cout << "Tiempo de vuelo: " << t << " s" << endl;
    cout << "Altura máxima: " << h << " m" << endl;
    cout << "Alcance horizontal: " << R << " m" << endl;
    cout << "Velocidad horizontal: " << Vx << " m/s" << endl;
    cout << "Velocidad vertical en el punto maximo: " << Vy_max << " m/s" << endl;
    cout << "Magnitud de la velocidad en el punto maximo: " << V_max << " m/s" << endl;
}


int main (){

    int opcion;// Variables para el menú
    double v0, theta_grados, theta, t, h, R, Vx, Vy_max, V_max;// Variables para el menú

    do {
        // Mostramos el menú
        msge("Menu de opciones");
        msge("----------------");
        msge("1. Calcular el tiempo de vuelo");
        msge("2. Calcular la altura maxima");
        msge("3. Calcular el alcance horizontal");
        msge("4. Calcular la velocidad horizontal");
        msge("5. Calcular la velocidad en el punto maximo");
        msge("6. Realizar un tiro parabolico completo");
        msge("0. Salir");

        msg("Ingrese la opcion deseada: ");// Solicitamos la opción al usuario
        cin >> opcion;

        switch(opcion) {
        case 1:
            system("cls");

            msg("Ingrese la velocidad inicial (m/s): ");// Pedimos los valores de v0 y theta
            cin >> v0;
            msg("Ingrese el ángulo de lanzamiento (grados): ");
            cin >> theta_grados;

            theta = theta_grados * PI / 180;// Convertimos el ángulo de grados a radianes

            if (theta_grados < 0 || theta_grados > 90) {
                cout << "El ángulo debe estar en el rango [0, 90] grados" << endl;
                break;
            }

            t = tiempoDeVuelo(v0, theta);// Calculamos el tiempo de vuelo

            cout << "El tiempo de vuelo es " << t << " segundos." << endl;// Mostramos el resultado

            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");

            msg("Ingrese la velocidad inicial (m/s): ");// Pedimos los valores de v0 y theta
            cin >> v0;
            msg("Ingrese el ángulo de lanzamiento (grados): ");
            cin >> theta_grados;

            if (theta_grados < 0 || theta_grados > 90) {
                cout << "El ángulo debe estar en el rango [0, 90] grados" << endl;
                break;
            }

            theta = theta_grados * PI / 180;// Convertimos el ángulo de grados a radianes

            h = alturaMaxima(v0, theta);// Calculamos la altura máxima

            cout << "La altura máxima es " << h << " metros." << endl;// Mostramos el resultado

            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");

            cout << "Ingrese la velocidad inicial (m/s): ";// Pedimos los valores de v0 y theta
            cin >> v0;
            cout << "Ingrese el ángulo de lanzamiento (grados): ";
            cin >> theta_grados;

            if (theta_grados < 0 || theta_grados > 90) {
                msge("El ángulo debe estar en el rango [0, 90] grados");
                break;
            }

            theta = theta_grados * PI / 180;// Convertimos el ángulo de grados a radianes

            R = alcanceMaximo(v0, theta);// Calculamos el alcance horizontal

            cout << "El alcance horizontal es " << R << " metros." << endl;// Mostramos el resultado

            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");

            cout << "Ingrese la velocidad inicial (m/s): ";// Pedimos los valores de v0 y theta
            cin >> v0;
            cout << "Ingrese el ángulo de lanzamiento (grados): ";
            cin >> theta_grados;

            if (theta_grados < 0 || theta_grados > 90) {
                cout << "El ángulo debe estar en el rango [0, 90] grados" << endl;
                break;
            }

            theta = (theta_grados * PI)/(180);// Convertimos el ángulo de grados a radianes

            Vx = velocidadHorizontal(v0, theta);// Calculamos la velocidad horizontal

            cout << "La velocidad horizontal es " << Vx << " m/s."<< endl;// Mostramos el resultado

            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");

            cout << "Ingrese la velocidad inicial (m/s): ";// Pedimos los valores de v0 y theta
            cin >> v0;
            cout << "Ingrese el ángulo de lanzamiento (grados): ";
            cin >> theta_grados;

            if (theta_grados < 0 || theta_grados > 90) {
                cout << "El ángulo debe estar en el rango [0, 90] grados" << endl;
                break;
            }

            theta = theta_grados * PI / 180;// Convertimos el ángulo de grados a radianes

            t = tiempoDeVuelo(v0, theta);// Calculamos la velocidad vertical en el punto maximo
            Vy_max = velocidadVertical(v0, theta, t/2);

            V_max = magnitudVelocidad(Vx, Vy_max);// Calculamos la magnitud de la velocidad en el punto maximo

            cout << "La velocidad en el punto maximo es " << V_max << " m/s." << endl;// Mostramos el resultado

            system("pause");
            system("cls");
            break;

        case 6:
            system("cls");

            system("cls");
            cout << "\nIngrese la velocidad inicial (m/s): ";// Solicitamos los datos al usuario
            cin >> v0;
            cout << "Ingrese el angulo de lanzamiento (grados): ";
            cin >> theta_grados;

            if (theta_grados < 0 || theta_grados > 90) {
                cout << "El angulo debe estar en el rango [0, 90] grados" << endl;
                break;
            }

            theta = theta_grados * PI / 180;// Convertimos el ángulo a radianes

            tiroParabolico(v0, theta);// Realizamos el cálculo completo del tiro parabólico

            system("pause");
            system("cls");
            break;

        case 0:
            system("cls");

            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida, intente de nuevo." << endl;

            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 0);

    return false;
}