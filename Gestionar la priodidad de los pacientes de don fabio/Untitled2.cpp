#include <iostream>
#include <queue>
#include <vector>
#include <string>

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

struct CompararPacientes
{
    bool operator()(const Paciente& p1, const Paciente& p2)
    {
        // El paciente con mayor urgencia tiene prioridad
        if (p1.urgencia != p2.urgencia)
        {
            return p1.urgencia < p2.urgencia;
        }

        // Si tienen la misma urgencia,
        // se respeta el orden de llegada
        return p1.turno > p2.turno;
    }
};

void registrarPaciente(
    priority_queue<Paciente, vector<Paciente>, CompararPacientes>& cola,
    int& siguienteTurno)
{
    Paciente paciente;

    cout << "\n============================================\n";
    cout << "             REGISTRAR PACIENTE\n";
    cout << "============================================\n";

    paciente.turno = siguienteTurno;

    cin.ignore();

    cout << "Nombre: ";
    getline(cin, paciente.nombre);

    cout << "Edad: ";
    cin >> paciente.edad;

    while (paciente.edad <= 0)
    {
        cout << "Edad invalida. Introduzca una edad mayor que 0: ";
        cin >> paciente.edad;
    }

    cout << "\nNivel de urgencia:\n";
    cout << "1 - Baja\n";
    cout << "2 - Media\n";
    cout << "3 - Alta\n";
    cout << "Seleccione el nivel: ";
    cin >> paciente.urgencia;

    while (paciente.urgencia < 1 || paciente.urgencia > 3)
    {
        cout << "Nivel invalido. Seleccione 1, 2 o 3: ";
        cin >> paciente.urgencia;
    }

    paciente.estado = "En espera";

    cola.push(paciente);

    cout << "\n--------------------------------------------\n";
    cout << "Paciente registrado correctamente.\n";
    cout << "Turno: " << paciente.turno << endl;
    cout << "Nombre: " << paciente.nombre << endl;
    cout << "Urgencia: " << obtenerUrgencia(paciente.urgencia) << endl;
    cout << "Estado: " << paciente.estado << endl;
    cout << "--------------------------------------------\n";

    siguienteTurno++;
}

void atenderPaciente(
    priority_queue<Paciente, vector<Paciente>, CompararPacientes>& cola,
    vector<Paciente>& historial)
{
    if (cola.empty())
    {
        cout << "\nNo hay pacientes en espera.\n";
        return;
    }

    Paciente paciente = cola.top();
    cola.pop();

    paciente.estado = "Atendido";

    historial.push_back(paciente);

    cout << "\n============================================\n";
    cout << "            PACIENTE EN ATENCION\n";
    cout << "============================================\n";
    cout << "Turno: " << paciente.turno << endl;
    cout << "Nombre: " << paciente.nombre << endl;
    cout << "Edad: " << paciente.edad << " anos" << endl;
    cout << "Urgencia: " << obtenerUrgencia(paciente.urgencia) << endl;
    cout << "Estado: " << paciente.estado << endl;
    cout << "============================================\n";
}

void mostrarPacientesEnEspera(
    priority_queue<Paciente, vector<Paciente>, CompararPacientes> cola)
{
    if (cola.empty())
    {
        cout << "\nNo hay pacientes en espera.\n";
        return;
    }

    cout << "\n============================================\n";
    cout << "           PACIENTES EN ESPERA\n";
    cout << "============================================\n";

    while (!cola.empty())
    {
        Paciente paciente = cola.top();
        cola.pop();

        cout << "\nTurno: " << paciente.turno << endl;
        cout << "Nombre: " << paciente.nombre << endl;
        cout << "Edad: " << paciente.edad << " anos" << endl;
        cout << "Urgencia: " << obtenerUrgencia(paciente.urgencia) << endl;
        cout << "Estado: " << paciente.estado << endl;
        cout << "--------------------------------------------\n";
    }
}

void mostrarHistorial(const vector<Paciente>& historial)
{
    if (historial.empty())
    {
        cout << "\nTodavia no se ha atendido ningun paciente.\n";
        return;
    }

    cout << "\n============================================\n";
    cout << "          HISTORIAL DE ATENCION\n";
    cout << "============================================\n";

    for (int i = 0; i < historial.size(); i++)
    {
        cout << "\nAtencion #" << i + 1 << endl;
        cout << "Turno: " << historial[i].turno << endl;
        cout << "Nombre: " << historial[i].nombre << endl;
        cout << "Edad: " << historial[i].edad << " anos" << endl;
        cout << "Urgencia: "
             << obtenerUrgencia(historial[i].urgencia) << endl;
        cout << "Estado: " << historial[i].estado << endl;
        cout << "--------------------------------------------\n";
    }
}

int main()
{
    priority_queue<Paciente, vector<Paciente>, CompararPacientes> cola;

    vector<Paciente> historial;

    int siguienteTurno = 1;
    int opcion;

    do
    {
        cout << "\n\n============================================\n";
        cout << "        SISTEMA DE ATENCION MEDICA\n";
        cout << "                 DON FABIO\n";
        cout << "============================================\n";
        cout << "1. Registrar paciente\n";
        cout << "2. Atender siguiente paciente\n";
        cout << "3. Mostrar pacientes en espera\n";
        cout << "4. Mostrar historial de atencion\n";
        cout << "5. Salir\n";
        cout << "============================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarPaciente(cola, siguienteTurno);
            break;

        case 2:
            atenderPaciente(cola, historial);
            break;

        case 3:
            mostrarPacientesEnEspera(cola);
            break;

        case 4:
            mostrarHistorial(historial);
            break;

        case 5:
            cout << "\n============================================\n";
            cout << "Sistema cerrado correctamente.\n";
            cout << "Gracias por utilizar el sistema de Don Fabio.\n";
            cout << "============================================\n";
            break;

        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 5);

    return 0;
}