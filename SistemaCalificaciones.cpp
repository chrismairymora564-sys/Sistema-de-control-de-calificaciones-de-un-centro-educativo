#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int cantidadEstudiantes;
    string nombre;
    double calificacion;
    double sumaNotas;
    double promedioEstudiante;
    double sumaPromedios;
    double promedioGeneral;
    double mejorPromedio;
    string mejorEstudiante;
    int aprobados;
    int reprobados;
    char deseaOtroGrupo;

    // Bucle do-while para repetir todo el programa si desea procesar otro grupo
    // Se usa do-while porque el programa debe ejecutarse al menos una vez
    do {
        // Se reinician contadores y acumuladores para cada grupo nuevo
        aprobados = 0;
        reprobados = 0;
        sumaPromedios = 0;
        mejorPromedio = 0;
        mejorEstudiante = "";

        // Bucle do-while para validar la cantidad de estudiantes
        // Se usa do-while porque debe pedir el dato al menos una vez y repetirlo si es invalido
        do {
            cout << "Cantidad de estudiantes: ";
            cin >> cantidadEstudiantes;
            if (cantidadEstudiantes <= 0) {
                cout << "Cantidad invalida. Debe ser mayor que 0." << endl;
            }
        } while (cantidadEstudiantes <= 0);

        // Bucle for para recorrer estudiantes
        // Se usa for porque ya sabemos cuantas veces se repetira: cantidadEstudiantes
        for (int i = 1; i <= cantidadEstudiantes; i++) {
            cout << "--- Estudiante " << i << " ---" << endl;
            cout << "Nombre: ";
            cin >> nombre;

            sumaNotas = 0;

            // Bucle for para recorrer las 4 calificaciones
            // Se usa for porque sabemos que son exactamente 4 calificaciones
            for (int j = 1; j <= 4; j++) {
                // Bucle do-while para validar cada calificacion
                // Se usa do-while porque debe pedir la nota al menos una vez y repetirla si esta fuera de 0 a 100
                do {
                    cout << "Calificacion " << j << ": ";
                    cin >> calificacion;
                    if (calificacion < 0 || calificacion > 100) {
                        cout << "Calificacion invalida. Debe estar entre 0 y 100." << endl;
                    }
                } while (calificacion < 0 || calificacion > 100);

                // Acumulador: suma las notas de este estudiante
                sumaNotas = sumaNotas + calificacion;
            }

            promedioEstudiante = sumaNotas / 4;

            // Acumulador: suma los promedios para calcular el promedio general
            sumaPromedios = sumaPromedios + promedioEstudiante;

            cout << fixed << setprecision(2);
            if (promedioEstudiante >= 70) {
                cout << "Promedio: " << promedioEstudiante << " - Aprobado" << endl;
                // Contador de aprobados
                aprobados = aprobados + 1;
            }
            else {
                cout << "Promedio: " << promedioEstudiante << " - Reprobado" << endl;
                // Contador de reprobados
                reprobados = reprobados + 1;
            }

            // Se busca el estudiante con el promedio mas alto
            if (i == 1 || promedioEstudiante > mejorPromedio) {
                mejorPromedio = promedioEstudiante;
                mejorEstudiante = nombre;
            }
        }

        promedioGeneral = sumaPromedios / cantidadEstudiantes;

        cout << "===== RESUMEN =====" << endl;
        cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
        cout << fixed << setprecision(2);
        cout << "Promedio del grupo: " << promedioGeneral << endl;
        cout << "Mejor promedio: " << mejorEstudiante << " (" << mejorPromedio << ")" << endl;

        cout << "Desea procesar otro grupo? (s/n): ";
        cin >> deseaOtroGrupo;

        // Bucle while para validar que la respuesta sea s o n
        // Se usa while porque no sabemos cuantas veces el usuario se equivocara
        while (deseaOtroGrupo != 's' && deseaOtroGrupo != 'n' && deseaOtroGrupo != 'S' && deseaOtroGrupo != 'N') {
            cout << "Respuesta invalida. Escriba s o n: ";
            cin >> deseaOtroGrupo;
        }

    } while (deseaOtroGrupo == 's' || deseaOtroGrupo == 'S');

    return 0;
}