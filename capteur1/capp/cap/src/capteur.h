#ifndef __CAPTEUR__H__
#define __CAPTEUR__H__
#include<gtk/gtk.h>

typedef struct{
int nombre;
char marquedef[30];
}defect;

typedef struct 
{
char Valeur[20];
char Nomdecapteur[20];
char Reference[20]; 
char service[20];
char Prix[20];
char Etat[20];
int jourofcapteur;
int moisofcapteur;
int anneeofcapteur;
}capteur;

void afficher_capteur(GtkWidget *liste);
void ajouter_capteur(capteur c);
void supprimer_capteur(char ref[]);
void modifier_capteur(capteur y);
void defectuex();



/*---------------------------------------------------------------*/
capteur find_cap(char ref[]);
int RefExist(char Reference[]);
int verifName(char c[]);
int verifSal(char s[]);
int verifier_date(int j,int m,int a);


void afficherdef(GtkWidget *liste);
#endif
