#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Estudiante{
    private:
        string nombre;
        int nacimiento;
        float promedio;
        float presupuesto;
    public:
        Estudiante();
        Estudiante(string n, int nac, float prom, float pres);
        void mostrar_datos();
        void actualizar_datos(string n, int nac, float prom, float pres);
        float indice_universidad() const;
        int obtener_nacimiento() const;
        float obtener_promedio() const;
        float obtener_presupuesto() const;
};
Estudiante::Estudiante(){
    nombre = "NN";
    nacimiento = 0;
    promedio = 0;
    presupuesto = 0;
}
Estudiante::Estudiante(string n, int nac, float prom, float pres){
    nombre=n;
    nacimiento=nac;
    promedio=prom;
    presupuesto=pres;
}
void Estudiante::mostrar_datos(){
    cout << "Nombre: " << nombre;
    cout << " ---- nacimiento: " << nacimiento;
    cout << " ---- Promedio (GPA): " << promedio;
    cout << " ---- Presupuesto: " << presupuesto << "\n";
}
void Estudiante::actualizar_datos(string n, int nac, float prom, float pres){
    nombre = n;
    nacimiento = nac;
    promedio = prom;
    presupuesto = pres;
}


//funciones fuera de mi clase
void mostrar_estudiantes(vector<Estudiante> &estudiantes){
    if(estudiantes.empty()){
        cout << "\nNo existen estudiantes\n";
    } else {
        cout << "\nIndice=========NOMBRE========AÑO DE NACIMIENTO==========PROMEDIO(GPA)=========PRESUPUESTO\n";
        for(int i=0; i<estudiantes.size(); i++){
            cout << i << "------";
            estudiantes[i].mostrar_datos();
        }
    }
}

void ingresar_estudiante(vector<Estudiante> &estudiantes){
    int tipo, ubicacion, indice;
    Estudiante temporal;
    do{
        cout << "1. Ingresar por defecto\n";
        cout << "2. Ingresar con datos\n";
        cout << "Elija: ";
        cin >> tipo;
        switch(tipo){
            case 1:
                temporal = Estudiante();
                break;
            case 2: {
                string a;
                cout << "\nIngrese el nombre: ";
                getline(cin >> ws, a);
                int b;
                cout << "Ingrese el año de nacimiento: ";
                cin >> b;
                float c;
                do {
                    cout << "Ingrese el promedio (GPA): ";
                    cin >> c;

                    if(c < 0 || c > 4) {
                        cout << "GPA no valido. Intente nuevamente.\n";
                    }

                } while(c < 0 || c > 4);
                float d;
                cout << "Ingrese el presupuesto: ";
                cin >> d;
                temporal = Estudiante(a, b, c, d);
                break;
            }
            default:
                cout << "Opcion no valida\n";
                break;
        }
    }while(tipo!=1 && tipo!=2);

    do{
        cout << "\n1. Insertar al final";
        cout << "\n2. Insertar en un indice especifico";
        cout << "\nElija: ";
        cin >> ubicacion;
        switch(ubicacion){
            case 1:
                estudiantes.push_back(temporal);
                break;
            case 2:
                do {
                    cout << "\nIngrese el indice: ";
                    cin >> indice;

                if(indice < 0 || indice > estudiantes.size()){
                    cout << "Indice no valido. Intente nuevamente.\n";
                }

            } while(indice < 0 || indice > estudiantes.size());
            
            estudiantes.insert(estudiantes.begin() + indice, temporal);
            break;
            
            default:
                cout << "Opcion no valida";
                break;
        }
    }while(ubicacion!=1 && ubicacion!=2);
}

void eliminar_estudiante(vector<Estudiante> &estudiantes){
    int eleccion, indice;
    if(estudiantes.empty()){
        cout << "No existen estudiantes";
        
    } else {
        do{
            cout << "\nElija la manera de eliminacion\n";
            cout << "1.Eliminar el ultimo\n";
            cout << "2.Eliminar por indice\n";
            cout << "Elija: ";
            cin >> eleccion;
            switch(eleccion){
                case 1:
                    estudiantes.pop_back();
                    break;
                case 2:
                    do{
                        cout << "\nElija el indice: ";
                        cin >> indice;
                        if(indice < 0 || indice >= estudiantes.size()){
                            cout << "Indice no valido. Intente nuevamente.\n";
                        }
                    }while(indice < 0 || indice >= estudiantes.size());
                    estudiantes.erase(estudiantes.begin() + indice);
                    break;
                default:
                    cout << "Eleccion no valida";
                    break;  
            }
        }while(eleccion!=1 && eleccion!=2);
    }
}

void actualizar_estudiante(vector<Estudiante> &estudiantes){
    int indice;

    if(estudiantes.empty()){
        cout << "No existen estudiantes para actualizar\n";
    } else {
        do {
            cout << "Ingrese el indice del estudiante que desea actualizar: ";
            cin >> indice;

            if(indice < 0 || indice >= estudiantes.size()){
                cout << "Indice no valido. Intente nuevamente.\n";
            }

        } while(indice < 0 || indice >= estudiantes.size());

        string n;
        int nac;
        float prom, pres;

        cout << "Ingrese el nuevo nombre: ";
        getline(cin >> ws, n);

        cout << "Ingrese el nuevo año de nacimiento: ";
        cin >> nac;
        
        do{
            cout << "Ingrese el nuevo promedio: ";
            cin >> prom;
            if(prom < 0 || prom > 4){
                cout << "Promedio (GPA) no valido,  intentelo de nuevo\n";
            }
        } while(prom < 0 || prom > 4);

        cout << "Ingrese el nuevo presupuesto: ";
        cin >> pres;

        estudiantes[indice].actualizar_datos(n, nac, prom, pres);

        cout << "\nEstudiante actualizado correctamente\n";
    }
}

float Estudiante::indice_universidad() const {
    return abs(promedio - 3) * presupuesto;
}

int Estudiante::obtener_nacimiento() const {
    return nacimiento;
}

float Estudiante::obtener_promedio() const {
    return promedio;
}

float Estudiante::obtener_presupuesto() const {
    return presupuesto;
}

void ordenar_estudiantes(vector<Estudiante> &estudiantes){
    int opcion;

    if(estudiantes.empty()){
        cout << "No existen estudiantes para ordenar\n";
    } else {
        cout << "\nOrdenar estudiantes por:\n";
        cout << "1. Año de nacimiento\n";
        cout << "2. GPA\n";
        cout << "3. Presupuesto\n";
        cout << "4. Indice universidad\n";
        cout << "Elija: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                sort(estudiantes.begin(), estudiantes.end(),
                    [](const Estudiante &a, const Estudiante &b){
                        return a.obtener_nacimiento() < b.obtener_nacimiento();
                    });
                break;

            case 2:
                sort(estudiantes.begin(), estudiantes.end(),
                    [](const Estudiante &a, const Estudiante &b){
                        return a.obtener_promedio() < b.obtener_promedio();
                    });
                break;

            case 3:
                sort(estudiantes.begin(), estudiantes.end(),
                    [](const Estudiante &a, const Estudiante &b){
                        return a.obtener_presupuesto() < b.obtener_presupuesto();
                    });
                break;

            case 4:
                sort(estudiantes.begin(), estudiantes.end(),
                    [](const Estudiante &a, const Estudiante &b){
                        return a.indice_universidad() < b.indice_universidad();
                    });
                break;

            default:
                cout << "Opcion no valida\n";
                break;
        }
    }
}

void menu_y_funcionamiento(vector<Estudiante> &estudiantes){
    int opcion;
    do{
        cout << "\nMenu\n";
        cout << "1. Ingresar estudiante\n";
        cout << "2. Eliminar estudiante\n";
        cout << "3. Actualizar estudiante\n";
        cout << "4. Ordenar\n";
        cout << "5. Imprimir\n";
        cout << "0. Salir\n";
        cout << "seleccione un opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                ingresar_estudiante(estudiantes);
                break;
            case 2:
                eliminar_estudiante(estudiantes);
                break;
            case 3:
                actualizar_estudiante(estudiantes);
                break;
            case 4:
                ordenar_estudiantes(estudiantes);
                break;
            case 5:
                mostrar_estudiantes(estudiantes);
                break;
            case 0:
                break;
            default:
                cout << "opcion no valida";
        }
    } while (opcion!=0);
}

int main(){
    vector<Estudiante> estudiantes;
    menu_y_funcionamiento(estudiantes);
    return 0;
}