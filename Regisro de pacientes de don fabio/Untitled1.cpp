#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Paciente
{
    int turno;
    string nombre;
    int edad;
    int urgencia;
    string estado;
};

string obtenerUrgencia(int urgencia)
{
    if (urgencia == 3)
        return "Alta";
    else if (urgencia == 2)
        return "Media";
    else
        return "Baja";
}

int main()
{
    vector<Paciente> pacientes;

    int cantidad;
    int siguienteTurno = 1;

    cout << "============================================\n";
    cout << "       SISTEMA DE REGISTRO DE PACIENTES\n";
    cout << "                 DON FABIO\n";
    cout << "============================================\n\n";

    cout << "Cuantos pacientes desea registrar: ";
    cin >> cantidad;
    cin.ignore();

    while (cantidad <= 0)
    {
        cout << "Debe registrar al menos un paciente.\n";
        cout << "Cuantos pacientes desea registrar: ";
        cin >> cantidad;
        cin.ignore();
    }

    for (int i = 0; i < cantidad; i++)
    {
        Paciente paciente;

        cout << "\n--------------------------------------------\n";
        cout << "REGISTRO DEL PACIENTE #" << i + 1 << "\n";
        cout << "--------------------------------------------\n";

        paciente.turno = siguienteTurno;

        cout << "Nombre: ";
        getline(cin, paciente.nombre);

        cout << "Edad: ";
        cin >> paciente.edad;

        while (paciente.edad <= 0)
        {
            cout << "Edad invalida. Introduzca una edad mayor que 0: ";
            cin >> paciente.edad;
        }

        cout << "Nivel de urgencia:\n";
        cout << "1 - Baja\n";
        cout << "2 - Media\n";
        cout << "3 - Alta\n";
        cout << "Seleccione el nivel: ";
        cin >> paciente.urgencia;
        cin.ignore();

        while (paciente.urgencia < 1 || paciente.urgencia > 3)
        {
            cout << "Nivel invalido. Seleccione 1, 2 o 3: ";
            cin >> paciente.urgencia;
            cin.ignore();
        }

        paciente.estado = "En espera";

        pacientes.push_back(paciente);

        cout << "\nPaciente registrado correctamente.\n";
        cout << "Numero de turno: " << paciente.turno << endl;
        cout << "Nivel de urgencia: "
             << obtenerUrgencia(paciente.urgencia) << endl;
        cout << "Estado: " << paciente.estado << endl;

        siguienteTurno++;
    }

    cout << "\n\n============================================\n";
    cout << "          PACIENTES REGISTRADOS\n";
    cout << "============================================\n";

    for (int i = 0; i < pacientes.size(); i++)
    {
        cout << "\nTurno: " << pacientes[i].turno << endl;
        cout << "Nombre: " << pacientes[i].nombre << endl;
        cout << "Edad: " << pacientes[i].edad << " anos" << endl;
        cout << "Urgencia: "
             << obtenerUrgencia(pacientes[i].urgencia) << endl;
        cout << "Estado: " << pacientes[i].estado << endl;
        cout << "--------------------------------------------\n";
    }

    cout << "\nRegistro finalizado correctamente.\n";

    return 0;
}