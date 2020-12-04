
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<math.h>
#include <windows.h>
#include <locale.h>
#include<string.h>
float base,altura,final,suma;
void definicion();
struct marcos
{
   char string_nombre[30];
  float extra;
   float costo;
 } marcos[900];

int buscar(char morcon[20])
 {
 	int y,j=0;
 	for (y=1;y<=900;y++)
 	{

 		if( strcmp(marcos[y].string_nombre,morcon)==0)
 	   {
 	   	   j=y;
 	   	   break;
		}
	}
 	return j;
 }
 /*//int impresion()//para ver si se agregaron bien
{
	int i;
	for(i=137;i<=182;i++)
	{
		printf("\n marco %s",marcos[i].string_nombre);
		printf(" extra  %d    costo %d",marcos[i].extra,marcos[i].costo);
	}
	return 0;
}//*/
int ConfiguraIdioma()
{
	//Cambia al idioma Español
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();

	//Configura cantidades para México
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";
   return 0;
}
 int menuv()
 {
 	int vidrio;
 	printf("\n tipos de vidrio ");
 	printf(" \n 1. claro   \n 2. antireflejante \n 3. claro  maria \n 4. maria antireflejante \n 5. antireflejante antireflejante ");
 	printf("\n ¿Qué vidrio sera?");
 	scanf("%d",&vidrio);
 	return vidrio;
 }
 int vidrio()
 {
 	char resp;
 	float totalc=0;
 	float mult;
 	int v;
 	printf("\n ¿COTIZA CON VIDRIO?");
 	scanf("%s",&resp);
   if (resp=='s')
 	{
 		v=menuv();
 		mult=(altura/100)*(base/100);
 		switch (v)
 		{
 			case 1:

 				    totalc=(mult)*850  ;
 				    printf("\n precio  sin vidrio  %.2f",final);

 				    printf("\n                              precio  final %.2f",final+totalc);
 				     break;
 			case 2:

 				    totalc=(mult)*960  ;
 				    printf("\n precio  sin vidrio  %.2f",final);

 				    printf("\n                               precio  final %.2f",final+totalc);
 				     break;
 			case 3:

 				    totalc=(mult)*850  ;
 				    printf("\n precio  sin vidrio  %.2f",final);

 				    printf("\n                               precio  final %.2f",final+totalc+totalc);
 				     break;
 			case 4:
			        totalc=(mult*960)+(mult*850) ;
			        printf("\n precio  sin vidrio  %.2f",final);

 				    printf("\n                               precio final %.2f",final+totalc);
 				     break;

 		   case 5:
		        	totalc=(mult)*960 ;
			         printf("\n precio  sin vidrio  %.2f",final);

 				    printf("\n                               precio final %.2f",final+totalc+totalc);
 				    break;
		 }
	 }
	 else
	 {

	 	 printf("\n precio  sin vidrio  %.2f",final);

	 }
	 return 0;
 }
 void  sacar(float x,int z)//x es el numero del marco
{

	float metros;
	metros=(x+marcos[z].extra)/100;
    final=metros*marcos[z].costo;

    vidrio();
}
 int main()
 {

 	ConfiguraIdioma();
 	definicion();

	char volver;
 	int i=0;
 	char morcob[20];

 		do
	{

	   // impresion();
		printf("\n digite la altura ");

	scanf("%f",&altura);
	printf("\n digite la base");
	scanf("%f",&base);
	suma=(altura+base)*2;
	printf("  marco: ");
    scanf("%s", morcob);
    i=buscar(morcob);

	sacar(suma,i);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
	printf("\n quiere hacer otra cotizacion ");
	scanf("%s",&volver);
	}while(volver=='s');


 	return 0;
 }

