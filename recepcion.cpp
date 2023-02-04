#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "GYM.h"

void inicioses();
void regsocio();
void listpagos();

main ()
{
	int opcion=0, ingreso=1;
	bool sesion=false;
	int ex=0;

	
	do {
		
		system("CLS");
		printf(".....................");
		printf(" \n Modulo de Recepcion");
		printf("\n.....................");
		printf("\n\n 1) Iniciar Sesion.");
		printf("\n 2) Registrar Socio.");
		printf("\n 3) Registrar Actividades de Socios."/*Además se tiene la opción de registrar por cada socio 
		una rutina indicada por el entrenador en un texto no mayor a 380 palabras, para esto cada operador deberá 
		identificarse en el sistema con un nombre de usuario y contraseña.*/);
		printf("\n 4) Listado de Socios y su/s correspondiente/s actividad/es.");
		printf("\n 5) Listado de fechas de pagos.");
		printf("\n 6) Cerrar la aplicacion.");
		printf("\n\n Ingrese una opcion: \n");
		scanf("%d", &opcion);
		
		/*if (!sesion and opcion != 1 and opcion != 6) {
			
			system("cls");
				
			printf("Primero inicie sesion...");
		}*/
	/*	else {
			ingreso=1;
			*/
			switch(opcion){
				case 1:
					system("cls");
					inicioses(); 
					
					break;
					
				case 2:
					{
						system("cls");
					
					while (ingreso==1){
					
					/*void regsocio();*/
						socios soc;
						FILE *archs;
						char in, f;
						int ex;
	
						archs=fopen("Socios.dat", "a+b");
						ex=1;
	
						printf("Fecha actual:\n");
						printf("\n  Dia: ");
						scanf("%d", &soc.fechareg.d);
						printf("\n  Mes: ");
						scanf("%d", &soc.fechareg.m);
						printf("\n  Anio: ");
						scanf("%d", &soc.fechareg.a);
						system("cls");
	
						printf("REGISTRO DE SOCIOS:\n\n");
						printf("- Apellido y nombre: ");
						_flushall();
						gets(soc.apynom);
						printf("\n- Domicilio: ");
						_flushall();
						gets(soc.domicilio);
						printf("\n- DNI: ");
						scanf("%d", &soc.dni);
						printf("\n- Telefono: ");
						scanf("%d", &soc.telefono);
						printf("\n- Fecha de nacimiento:\n");
						printf("\n    - Dia: ");
						scanf("%d", &soc.fechanac.d);
						printf("\n    - Mes: ");
						scanf("%d", &soc.fechanac.m);
						printf("\n    - Anio: ");
						scanf("%d", &soc.fechanac.a);
						printf("\n- Edad: ");
						scanf("%d", &soc.edad);
						printf("\n- Peso(kg): ");
						scanf("%f", &soc.peso);
						printf("\n- Altura(m): ");
						scanf("%f", &soc.altura);
						printf("\n\n- Presenta indicaciones medicas especificas? (s/n)");
						printf("-> %s\n");
						scanf("%s", &in);
						if (in== 's'){
							printf("Indicaciones: \n\n");
							_flushall();
							gets(soc.indicaciones);
							printf("\n");
						}
						fwrite(&soc, sizeof(soc), 1, archs);
	
						system("pause");
				
						fclose(archs);
						system("cls");

						printf("Continuar registrando socios?");
						printf("\n\n 0) No, salir");
						printf("\n 1) Si, continuar");
						printf("\n - ");
							scanf("%d", &ingreso);
					}
					
					break;
				}
					
				case 3:
					
					
				case 4:
					
					
				case 5:
					system("cls");
					listpagos();
					
					system("cls");
					break;
					
					
			}
			
		
		}
	while(opcion<6);
}

void inicioses(){
	usuarios us;
	int aux, aux2;
	FILE *archus;
	char buscarusuario[10], buscarcontrasena[10];
	bool encontrar=false, encontrar2=false;
	int error=0;
					
	archus=fopen("Usuarios.dat", "r+b");
					
	printf("Ingrese el nombre de usuario: ");
	_flushall();
	gets(buscarusuario);
	
	fread(&us, sizeof(us), 1, archus);
					
	while(encontrar==false && !feof(archus));
	{
	aux=strcmp(buscarusuario,us.usuario);
	if (aux=0)
	{
	encontrar=true;
	printf("\n **Usuario encontrado**");
	printf("\n\nIngrese la contrasena: ");
	gets(buscarcontrasena);
	system("cls");
							
	aux2=strcmp(buscarusuario,us.contrasena);
							
	while(encontrar2==false && error<4);
	{
	if(aux2=0)
	{
	encontrar2=true;
	printf("\n **Ha iniciado sesion**");
	printf("\n\nApellido y nombre del usuario: ");
	puts(us.apynom);
	}
	else 
	{
	printf("\nContrasena incorrecta");
	printf("\n\nIngrese nuevamente la contrasena: ");
	gets(buscarcontrasena);
	error++;
	}
	
	if(encontrar2==false){
	printf("\nHa superado el numero de intentos permitidos. Por favor, intente nuevamente mas tarde.");
	}
								
	}
	}
	else {
	printf("\n**Usuario incorrecto**");
	}
	fread(&us, sizeof(us), 1, archus);
	}
	system("cls");
	fclose(archus);
}


void listpagos(){
	socios soc;
	fecha f;
	FILE *archs;
	int ex;
	
	do{
	
		archs=fopen("Socios.dat", "rb");
		
		printf("Fecha actual:\n");
		printf("\n  Dia: ");
		scanf("%d", &f.d);
		printf("\n  Mes: ");
		scanf("%d", &f.m);
		printf("\n  Anio: ");
		scanf("%d", &f.a);
		system("cls");
		
		printf("\n**Listado de fecha de pago:**");
		
		fread(&soc, sizeof(soc), 1, archs);
		while(!feof(archs)){
			printf("\n\n- Apellido y Nombre: ");
			puts(soc.apynom);
			printf("\n- Fecha de ingreso: %d/%d/%d", soc.fechareg.d, soc.fechareg.m, soc.fechareg.a);
			if(soc.fechareg.d<=f.d && soc.fechareg.m<f.m && soc.fechareg.a<=f.a){
				printf("\nSOCIO PROXIMO A PAGO!");
			}
			else {
				printf("\nSocio correctamente al dia");
			}
			printf("\n\n");
			fread(&soc, sizeof(soc), 1, archs);
		}
		system("pause");
		system("cls");
	}
	while(ex==1);

	fclose(archs);
	system("cls");
	
}

