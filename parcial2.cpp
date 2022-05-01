#include <iostream>
#include <stdio.h>  
#include <string.h> 
using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Estudiante{
	int carnet;
	char nombre[50];
	char apellido[50];
	int telefono;
};
void leerE();
void crearE();
void actE();
void eliE();
void abrir_estudiante();
int main (){
crearE();
leerE();
actE();
eliE();
abrir_estudiante();
	return 0;	
}
void leerE(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	char continuar;
		Estudiante estudiante;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Carnet:";
		cin>>estudiante.carnet;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	
}
void crearE(){
system("cls");
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CARNET" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.carnet <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
	
	void actE(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Carnet:";
		cin>>estudiante.carnet;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}
void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CARNET" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.carnet <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
	
	void eliE(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	Estudiante estudiante;
	FILE* archivo = fopen(nombe_archivo, "rb");
	FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
	int id=0,i=0;
		cout<<"ingrese el id a eliminar:"; 
	cin>>id; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
			
			if (i != id){
				fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
			} 
			
			i++; 
		}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombe_archivo,"wb"); 
	 
		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	abrir_estudiante();
		system("PAUSE");
}