#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "GYM.h"

void 	RegistroRecep();
bool usuVerificacion (usuarios USURecep);
bool conVerificacion(usuarios USURecep);

main()
{
	int O;
	usuarios USU;
	
	do
	{
		system("CLS");
		printf("\033[1;33m");
		printf(".......................");
		printf("\n Modulo Administracion");
		printf("\n.......................");
		printf("\033[1;36m");
		printf("\n\n 1) Iniciar Sesion.");
		printf("\n 2) Registrar usuario de Recepcion.");
		printf("\n 3) Registrar actividades del Gym.");
		printf("\n 4) Calcular pago al entrenador.");
		printf("\n 5) Entrenador con mayor carga horaria.");
		printf("\033[1;32m");
		printf("\n\nIngrese una Opcion: ");
		printf("\033[1;31m");
		scanf("%d", &O);
		printf("\033[1;36m");
		
		
		switch (O)	
		{
		
			case 1:
				{
					system ("cls");
					
					FILE *Arch;
					char buscarusuario[10], buscarcontrasena[10];
					bool encontrar=false, encontrar2=false;
					int CError=0;
					
					Arch= fopen("Usuarios.dat", "r+b");
					
					printf("Ingrese el nombre de usuario: ");
					_flushall();
					gets (buscarusuario);	
						
					while(encontrar==false && !feof(Arch));
					{
						if(strcmp(buscarusuario,USU.usuario)==0)
						{
							encontrar==true;
							printf("\n Usuario encontrado \n");
							printf("Ingrese la contrasena: ");
							gets(buscarcontrasena);
							while(encontrar2=false && CError<4)
							{
								if(strcmp(buscarcontrasena,USU.contrasena)==0)
								{
									system("cls");
									encontrar2=true;
									printf("\n Contrasena correcta! \n");
									printf("Ha iniciado sesion como: ");
									puts (USU.apynom);
								}
								else
								{
									printf("Contrasena incorrecta. \n\n Ingresela nuevamente: ");
									gets(buscarcontrasena);
									CError++;
								}
								
							}
								if(encontrar2==false)
							{
								printf("\n Ha superado el numero de intentos permitidos. \n\n Vuelva a intentarlo mas tarde");
							}
						}
						else
						{
							printf("\n Usuario incorrecto");
						}
					}
					
					break;			
					
				}
				
			case 2:
				
				system("cls");
					
				RegistroRecep();
					
				break;		
		}
			/*case 3:
				{
					system("cls");
					
					printf("\n\t\t Registro de Actividades \n\n");
					regAct();
					
				}*/
	}
	while (O<7);

}



bool usuVerificacion (usuarios USURecep)
{
	FILE *aux;
	usuarios Verif;
	bool con=true;
	int i, Controlletras=0;
	
	aux= fopen("usuarios.dat", "r+b");
		
	
	
	if(strlen (USURecep.usuario)>10 || strlen (USURecep.usuario)<6)
	{
		con=false;
		printf("\n El usuario no tiene el numero de caracteres requeridos.");
	}
	
	fread (&Verif, sizeof(usuarios),1, aux);
	
	while (!feof(aux))
	{
		if(strcmp(Verif.usuario, USURecep.usuario)==0)
		{
			con=false;
			printf("\n El usuario ingresado ya existe \n");
			break;
		}
		fread(&Verif, sizeof(usuarios),1,aux);	
	}
	
	for (i=0;i<strlen(USURecep.usuario);i++) //chequea letra por letra (cant de la palabra) las mayusculas
	{
		if(USURecep.usuario[i]>= 'A' && USURecep.usuario[i]<= 'Z')
		Controlletras++; //cuenta la cantidad de mayusculas
	}
	if(Controlletras<2)
	{
		con=false;
		printf("\n El nombre de usuario contiene menos de dos mayusculas.");
	}
	
	Controlletras=0;
	
	for(i=0;i<strlen(USURecep.usuario);i++)
	{
		if(USURecep.usuario[i]<='9' && USURecep.usuario[i]>='0')
		Controlletras++;
	}
	if(Controlletras>3)
	{
		con=false;
		printf("\n El usuario supera la cantidad de numeros permitidos.");
	}
	
	/*if(USURecep.usuario[0] >='z' && USURecep.usuario[0]<= 'a');
	{
		con=false;
		printf("\n El usuario debe comenzar con una minuscula");
	}*/
	if (USURecep.usuario[0] >= 'a' and USURecep.usuario[0] <= 'z') {
		
		
		
	} else {
		
		con = false;
		
		printf("\nEl Usuario debe comenzar con una minuscula\n");
		
	}
	
	fclose(aux);
    if (con==false) {
		
		printf("\n\n\n");
	
		system("PAUSE");
		
	}
	return con;
}

void RegistroRecep()
{
		FILE *Arch;
				usuarios USURecep;
				int op;
				bool veri=true;
			
					
				Arch= fopen("usuarios.dat", "a+b");
					
				printf("\n\t\t Registro de usuarios de recepcion \n\n");
					
				printf("\n El usuario debe cumplir las siguientes condiciones: ");
				printf("\n a)Ser único para cada usuario registrado.");
				printf("\n b) Comenzar con una letra minúscula. ");
				printf("\n c) Tener al menos 2 letras mayúsculas. ");
				printf("\n d) Tener como máximo 3 dígitos. \n\n");
				
				printf("Usuario: ");
				_flushall();
				gets(USURecep.usuario);
				
				veri=usuVerificacion (USURecep);
					
				while(veri==false)
				{
					system("cls");	
						
					printf("Nombre de usuario incorrecto \n\n");
					printf("1. Ingresar otro nombre de usuario.\n");
					printf("2. Regresar. \n\n");
						
					printf("Opcion: ");
					scanf("%d",&op);
						
					if(op==1)
					{
						system("cls");							
						printf("\n\t\t Registro de usuarios de recepcion \n\n");
					
						printf("\n El usuario debe cumplir las siguientes condiciones: ");
						printf("\n a)Ser único para cada usuario registrado.");
						printf("\n b) Comenzar con una letra minúscula. ");
						printf("\n c) Tener al menos 2 letras mayúsculas. ");
						printf("\n d) Tener como máximo 3 dígitos. \n\n");
				
						printf("Usuario: ");
						_flushall();
						gets(USURecep.usuario);
						veri=usuVerificacion (USURecep);
							
					}
			
					else
					{
						fclose(Arch);
						break;
					}
		
				}
				
				
				printf("Nombre de usuario exitoso!\n\n");
				
				system("cls");
				printf("\n\t\t Crear una contrasena \n\n" );
				printf("La contrasena debe cumplir las siguientes condiciones: ");
				printf("\n a) Contener al menos una letra mayuscula, una letra minuscula y un numero.");
				printf("\n b) Contener entre 6 y 32 caracteres");
				printf("\n c) No contener mas de 3 caracteres consecutivos");
				printf("\n d) No contener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas(ascendentemente)");
				
				printf("\n\n Nombre de usuario: ");
				puts(USURecep.usuario);
				printf("Ingrese una contrasena: ");
				gets(USURecep.contrasena);
				veri=conVerificacion(USURecep);
				
				while(veri==false)
				{
					system("cls");
					
					printf("\n La contrasena no cumple las condiciones \n\n");
					printf("1. Ingresar otra contrasena.\n");
					printf("2. Regresar. \n\n");
						
					printf("Opcion: ");
					scanf("%d",&op);
						
					if(op==1)
					{
						system("cls");
						printf("\n\t\t Crear una contrasena \n\n" );
						printf("La contrasena debe cumplir las siguientes condiciones: ");
						printf("\n a) Contener al menos una letra mayuscula, una letra minuscula y un numero.");
						printf("\n b) Contener entre 6 y 32 caracteres");
						printf("\n c) No contener mas de 3 caracteres consecutivos");
						printf("\n d) No contener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas(ascendentemente)");
						
						printf("\n\n Nombre de usuario: ");
						puts(USURecep.usuario);
						printf("Ingrese una contrasena: ");
						gets(USURecep.contrasena);
						veri=conVerificacion(USURecep);
							
					}
					else
					{
						fclose(Arch);
						break;
					}
				}
				printf("Contrasena valida! \n\n Ingrese un Nombre y Apellido:  ");
				gets(USURecep.apynom);
				
				fwrite(&USURecep, sizeof(usuarios), 1, Arch);
				fclose(Arch);
				
	
}

bool conVerificacion(usuarios USURecep)
{
	bool con=true;
	int i, May=0, Min=0, Num=0, CantL;
	
	for(i=0;i<strlen(USURecep.contrasena); i++)
	{
		if(USURecep.contrasena[i]>='A' && USURecep.contrasena[i]<='Z')
		{
			May=1;
		}	
		else 
		if(USURecep.contrasena[i]>='a' && USURecep.contrasena[i]<='z')
		{
			Min=1;
		}
		else
		if(USURecep.contrasena[i]>='0' && USURecep.contrasena[i]<='9')
		{
			Num=1;
		}
		
	}
	
	if(May==0)
	{
		con=false;	
		printf("\n La clave debe contener al menos una mayuscula");
	}
	if(Min==0)
	{
		con=false;	
		printf("\n La clave debe contener al menos una minuscula");
	}
		if (USURecep.contrasena[i] >= 'A' && USURecep.contrasena[i] <= 'Z') {
			
		} else if (USURecep.contrasena[i] >= 'a' && USURecep.contrasena[i] <= 'z') {
			
		} else if (USURecep.contrasena[i] >= '0' && USURecep.contrasena[i] <= '9') {
			
		} else {
			con = false;
			
			printf("\nLa contrasena no puede contener signos\n");
			
		}
	
	if(May==0)
	{
		con=false;	
		printf("\n La clave debe contener al menos un numero");
		con=false;
		printf("La clave debe contener entre 6 y 32 caracteres.");
	}
	
	
	for(i=0; i<strlen(USURecep.contrasena);i++)
	{}
	
	CantL=strlen(USURecep.contrasena);
	if(CantL<6 || CantL>32)
	{}
	
	for(i=0;i<(CantL-2);i++)
	{
		if(USURecep.contrasena[i]>='0' && USURecep.contrasena[i]<='9')
		{
			if(USURecep.contrasena[i+1]>='0' && USURecep.contrasena[i+1]<='9')
			{
				if(USURecep.contrasena[i+2]>='0' && USURecep.contrasena[i+2]<='9')
				{
					con=false;
					printf("\n La clave no puede tener 3 numeros consecutivos");
				}
			}
		}
	}
	
	for(i=0;i<(CantL-1); i++)
	{
			if (USURecep.contrasena[i] >= 'A' && USURecep.contrasena[i] <= 'Y') {
			
			if (USURecep.contrasena[i+1] == (USURecep.contrasena[i] + 1) || USURecep.contrasena[i+1] == (USURecep.contrasena[i] + 33)) {
				
				con = false;
				
				printf("\nLa contrasena no debe tener dos letras alfabeticamente seguidas" );
				
			}
			
		} else if (USURecep.contrasena[i] >= 'a' && USURecep.contrasena[i] <= 'y') {
			
			if (USURecep.contrasena[i+1] == (USURecep.contrasena[i] + 1) || USURecep.contrasena[i+1] == (USURecep.contrasena[i] - 31)) {
				
				con = false;
				
				printf("\nLa contrasena no debe tener dos letras alfabeticamente seguidas");
				
			}
			
		}
	}
	
	if(con==false)
	{
		printf("\n\n");
		system("PAUSE");
	}
	return con;
}

/*void regAct()
{
	FILE *arch;
	
}*/

