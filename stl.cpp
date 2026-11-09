#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

struct Estudiante {
    string nombre;
    int nacimiento;
    double gpa;
};

int main() {
    array<int, 20> n = {21, 23, 25, 27, 29, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 1, 3, 5, 7, 9};

    cout << "1a. Todos los elementos:" << endl;
    for (auto it = n.begin(); it != n.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "1b. Mayores de 20 y menores que 50:" << endl;
    for (int x : n) {
        if (x > 20 && x < 50) cout << x << " ";
    }
    cout << endl;

    sort(n.begin(), n.end());
    cout << "1c. Elementos ordenados:" << endl;
    for (int x : n) {
        cout << x << " ";
    }
    cout << endl;

    cout << "1d. Indices impares menores de 10:" << endl;
    for (int i = 1; i < 10; i += 2) {
        cout << n[i] << " ";
    }
    cout << endl << endl;

    array<string, 12> p = {"Argentina", "Bolivia", "Brasil", "Chile", "Colombia", "Ecuador", "Guyana", "Paraguay", "Peru", "Surinam"};

    p.at(10) = "Uruguay";
    p[11] = "Venezuela";

    cout << "2b. Paises con C o P:" << endl;
    for (string x : p) {
        if (x[0] == 'C' || x[0] == 'P') cout << x << " ";
    }
    cout << endl;

    cout << "2c. Primero y ultimo:" << endl;
    cout << p.front() << " - " << p.back() << endl;

    sort(p.begin(), p.end());
    cout << "2d. Paises ordenados:" << endl;
    for (string x : p) {
        cout << x << " ";
    }
    cout << endl << endl;

    array<Estudiante, 10> est = {{
        {"Juan", 2000, 3.4},
        {"Maria", 2005, 2.8}
    }};

    cout << "Ingrese nombre, nacimiento y GPA del estudiante 3: " << endl;
    cin >> est[2].nombre >> est[2].nacimiento >> est[2].gpa;

    cout << "Ingrese nombre, nacimiento y GPA del estudiante 4: " << endl;
    cin >> est[3].nombre >> est[3].nacimiento >> est[3].gpa;

    string nombres[3] = {"Gaby", "Patty", "Diana"};
    int nacimientos[3] = {2002, 2004, 2006};
    double gps[3] = {3.8, 3.0, 2.9};

    est[4] = {nombres[0], nacimientos[0], gps[0]};
    est[5] = {nombres[1], nacimientos[1], gps[1]};

    ifstream archivo("datos.txt");
    for (int i = 6; i < 10; i++) {
        archivo >> est[i].nombre >> est[i].nacimiento >> est[i].gpa;
    }
    archivo.close();

    cout << endl << "3d. Lista de estudiantes:" << endl;
    for (Estudiante e : est) {
        cout << e.nombre << " | Anio: " << e.nacimiento << " | GPA: " << e.gpa << " | Edad: " << 2026 - e.nacimiento << " | Beca: ";
        if (e.gpa >= 3.5) {
            cout << "Si" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}