#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "troupeau.h"
#include <string.h>
#include <gdk/gdk.h>
#include <time.h>
struct tm h;
int xx=3;
int t[2]={0,0};
int zeta=0;



void
on_buttonajoutetroupeaux_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
troupeau p;
int *d,*m,*a;
GtkWidget *combotype;
GtkWidget *img1;
GtkWidget *img2;
GtkWidget *img3;
GtkWidget *img4;
GtkWidget *img5;
GtkWidget *img6;
GtkWidget *img15;
GtkWidget *img16;
GtkWidget *l1;
GtkWidget *combo1;
GtkWidget *entrynom;
GtkWidget *labelajouter;
GtkWidget *calendar1;
GtkWidget *type;
GtkWidget *nom;
GtkWidget *genre;
GtkWidget *ajoutoui;
GtkWidget *windowtroupeaux;
GtkWidget *buttonajoutetroupeaux;
GdkColor color;
GdkColor color1;
GdkColor color2;
d=&p.birth.jour;
m=&p.birth.mois;
a=&p.birth.annee;
int x,s;

buttonajoutetroupeaux=lookup_widget(objet_graphique,"buttonajoutetroupeaux");
windowtroupeaux=lookup_widget(objet_graphique,"windowtroupeaux");
type=lookup_widget(objet_graphique,"type");
l1=lookup_widget(objet_graphique,"l1");
img1=lookup_widget(objet_graphique,"img1");
img2=lookup_widget(objet_graphique,"img2");
img3=lookup_widget(objet_graphique,"img3");
img4=lookup_widget(objet_graphique,"img4");
img5=lookup_widget(objet_graphique,"img5");
img6=lookup_widget(objet_graphique,"img6");
img15=lookup_widget(objet_graphique,"img15");
img16=lookup_widget(objet_graphique,"img16");
nom=lookup_widget(objet_graphique,"nom");
genre=lookup_widget(objet_graphique,"genre");
combotype=lookup_widget(objet_graphique,"combotype");
combo1=lookup_widget(objet_graphique,"combo1");
entrynom=lookup_widget(objet_graphique,"entrynom");
labelajouter=lookup_widget(objet_graphique,"labelajouter");
calendar1=lookup_widget(objet_graphique,"calendar1");
gtk_calendar_get_date(calendar1,a,m,d);
++*m;
s=verif( p.birth.jour,p.birth.mois,p.birth.annee, h);
FILE *t;
t=fopen("horloge.txt","a");
fprintf(t,"%d\n%d %d %d \n",s,d,m,a);
fclose(t);
strcpy(p.name,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(p.genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo1)));
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combotype)));




if(s==1)
{
gtk_label_set_markup(GTK_LABEL(l1),"<span  foreground='#f90922'> *verifier la date!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(buttonajoutetroupeaux,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img15);
gtk_widget_hide(img16);
}
else
{
gtk_label_set_text(GTK_LABEL(l1),"");
gtk_widget_hide(img15);
gtk_widget_show(img16);
}


if(strcmp(p.type,"./")==0)
{
gtk_label_set_markup(GTK_LABEL(type),"<span  foreground='#f90922'> *le champ type est vide!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(buttonajoutetroupeaux,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img1);
gtk_widget_hide(img2);
}
else
{
gtk_label_set_text(GTK_LABEL(type),"");
gtk_widget_hide(img1);
gtk_widget_show(img2);
}

if(strcmp(p.genre,"./")==0)
{
gtk_label_set_markup(GTK_LABEL(genre),"<span  foreground='#f90922'> *le champ genre est vide!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(buttonajoutetroupeaux,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img5);
gtk_widget_hide(img6);
}
else
{
gtk_label_set_text(GTK_LABEL(genre),"");
gtk_widget_show(img6);
gtk_widget_hide(img5);
}
if(strlen(p.name)==0)
{
gtk_label_set_markup(GTK_LABEL(nom),"<span  foreground='#f90922'> *le champ nom est vide!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(buttonajoutetroupeaux,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img3);
gtk_widget_hide(img4);
}
else

{
x=alpha(p.name);
if(x==1)
{
gtk_label_set_markup(GTK_LABEL(nom),"<span  foreground='#f90922'> *entrer des alphabets!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(buttonajoutetroupeaux,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img3);
gtk_widget_hide(img4);
}
else
{
gtk_label_set_text(GTK_LABEL(nom),"");
gtk_widget_show(img4);
gtk_widget_hide(img3);
}

}





if((strcmp(p.type,"./")!=0)&&(strcmp(p.genre,"./")!=0)&&(strlen(p.name)!=0)&&(x==0)&&(s==0))
{
gtk_widget_hide(img2);
gtk_widget_hide(img4);
gtk_widget_hide(img6);
ajouter(p);
gtk_widget_destroy (windowtroupeaux);
ajoutoui = create_ajoutoui ();
gtk_widget_show (ajoutoui);



}


}


void
on_buttonafficher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowtroupeaux;
GtkWidget *affichagetroupeaux;
GtkWidget *treeview1;
windowtroupeaux=lookup_widget(objet,"windowtroupeaux");
gtk_widget_destroy(windowtroupeaux);
affichagetroupeaux=lookup_widget(objet,"affichagetroupeaux");
affichagetroupeaux=create_affichagetroupeaux();
gtk_widget_show(affichagetroupeaux);
treeview1=lookup_widget(affichagetroupeaux,"treeview1");
affichage(treeview1);


}


void
on_buttonajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combotype;
GtkWidget *entrynom;
GtkWidget *combo1;
GtkWidget *type;
GtkWidget *nom;
GtkWidget *genre;
GtkWidget *img1;
GtkWidget *img2;
GtkWidget *img3;
GtkWidget *img4;
GtkWidget *img5;
GtkWidget *img6;
GtkWidget *l1;
GtkWidget *img15;
GtkWidget *img16;
GtkWidget *windowtroupeaux;
GtkWidget *affichagetroupeaux;
affichagetroupeaux=lookup_widget(objet_graphique,"affichagetroupeaux");

gtk_widget_destroy(affichagetroupeaux);
windowtroupeaux = create_windowtroupeaux ();
gtk_widget_show (windowtroupeaux);
combotype=lookup_widget(windowtroupeaux,"combotype");
combo1=lookup_widget(windowtroupeaux,"combo1");
entrynom=lookup_widget(windowtroupeaux,"entrynom");
gtk_combo_box_set_active(combotype,0);
gtk_combo_box_set_active(combo1,0);
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entrynom),10);
type=lookup_widget(windowtroupeaux,"type");
nom=lookup_widget(windowtroupeaux,"nom");
genre=lookup_widget(windowtroupeaux,"genre");
img1=lookup_widget(windowtroupeaux,"img1");
img2=lookup_widget(windowtroupeaux,"img2");
img3=lookup_widget(windowtroupeaux,"img3");
img4=lookup_widget(windowtroupeaux,"img4");
img5=lookup_widget(windowtroupeaux,"img5");
img6=lookup_widget(windowtroupeaux,"img6");
l1=lookup_widget(windowtroupeaux,"l1");
img15=lookup_widget(windowtroupeaux,"img15");
img16=lookup_widget(windowtroupeaux,"img16");
gtk_widget_hide(img1);
gtk_widget_hide(img2);
gtk_widget_hide(img3);
gtk_widget_hide(img4);
gtk_widget_hide(img5);
gtk_widget_hide(img6);
gtk_widget_hide(img15);
gtk_widget_hide(img16);
gtk_label_set_text(GTK_LABEL(type),"");
gtk_label_set_text(GTK_LABEL(nom),"");
gtk_label_set_text(GTK_LABEL(genre),"");
gtk_label_set_text(GTK_LABEL(l1),"");


}


void
on_buttontype_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *typedetroupeaux;
GtkWidget *affichagetroupeaux;
GtkWidget *totale;
affichagetroupeaux=lookup_widget(objet,"affichagetroupeaux");
gtk_widget_destroy(affichagetroupeaux);
typedetroupeaux=lookup_widget(objet,"typedetroupeaux");
typedetroupeaux=create_typedetroupeaux();
gtk_widget_show(typedetroupeaux);
totale=lookup_widget(typedetroupeaux,"totale");

gtk_toggle_button_set_active (totale,"true");


}



void
on_buttonmodifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichagetroupeaux;
GtkWidget *idtroupeaumodifier;
GtkWidget *entry4;
GtkWidget *labelmod;
GtkWidget *labelinf;
GtkWidget *img9;
GtkWidget *img10;

affichagetroupeaux=lookup_widget(objet_graphique,"affichagetroupeaux");
//idtroupeaumodifier=lookup_widget(objet_graphique,"idtroupeaumodifier");
gtk_widget_destroy(affichagetroupeaux);
idtroupeaumodifier = create_idtroupeaumodifier ();
gtk_widget_show (idtroupeaumodifier);
entry4=lookup_widget(idtroupeaumodifier,"entry4");
labelmod=lookup_widget(idtroupeaumodifier,"labelmod");
labelinf=lookup_widget(idtroupeaumodifier,"labelinf");
img9=lookup_widget(idtroupeaumodifier,"img9");
img10=lookup_widget(idtroupeaumodifier,"img10");
gtk_widget_hide(img9);
gtk_widget_hide(img10);
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry4),5);
gtk_entry_set_text(GTK_ENTRY(entry4),"");
gtk_label_set_text(GTK_LABEL(labelmod),"");
gtk_label_set_text(GTK_LABEL(labelinf),"");



}


void
on_buttonmodretour_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *idtroupeaumodifier;
GtkWidget *affichagetroupeaux;
GtkWidget *treeview1;
idtroupeaumodifier=lookup_widget(objet,"idtroupeaumodifier");
gtk_widget_destroy(idtroupeaumodifier);
affichagetroupeaux=lookup_widget(objet,"affichagetroupeaux");
affichagetroupeaux=create_affichagetroupeaux();
gtk_widget_show(affichagetroupeaux);
treeview1=lookup_widget(affichagetroupeaux,"treeview1");
affichage(treeview1);

}


void
on_modifierid_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char idf0[30];
int x,y;
GtkWidget *img9;
GtkWidget *img10;
GdkColor color1;
GdkColor color2;
GtkWidget *entry4;
GtkWidget *labelmod;
GtkWidget *idtroupeaumodifier;
GtkWidget *modifierid;
img9=lookup_widget(objet_graphique,"img9");
img10=lookup_widget(objet_graphique,"img10");
modifierid=lookup_widget(objet_graphique,"modifierid");
idtroupeaumodifier=lookup_widget(objet_graphique,"idtroupeaumodifier");
labelmod=lookup_widget(objet_graphique,"labelmod");
entry4=lookup_widget(objet_graphique,"entry4");
y=maj(gtk_entry_get_text(GTK_ENTRY(entry4)));
if(strcmp("",gtk_entry_get_text(GTK_ENTRY(entry4)))==0)
{
gtk_label_set_markup(GTK_LABEL(labelmod),"<span  foreground='#f90922'> *le champ est vide!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(modifierid,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img9);
gtk_widget_hide(img10);
}
else
if(y==1)
{
gtk_label_set_markup(GTK_LABEL(labelmod),"<span  foreground='#f90922'> *entrer des MAJUSCULE et des chiffres!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(modifierid,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img9);
gtk_widget_hide(img10);
}
else
if((y!=1)&&(strcmp("",gtk_entry_get_text(GTK_ENTRY(entry4)))!=0))
{
strcpy(idf0,gtk_entry_get_text(GTK_ENTRY(entry4)));
x=idmodifier(idf0);
if(x==1)
{
/*gdk_color_parse("#32ff00",&color1);
gtk_widget_modify_bg(modifierid,GTK_STATE_NORMAL,&color1);*/

gtk_widget_destroy(idtroupeaumodifier);

GtkWidget *modifiertroupeau;
//modifiertroupeaux=lookup_widget(objet_graphique,"modifiertroupeaux");
modifiertroupeau = create_modifiertroupeau ();
gtk_widget_show (modifiertroupeau);
GtkWidget *entry2;
GtkWidget *combobox3;
GtkWidget *combobox4;
GtkWidget *calendar2;
GtkWidget *labelnomt;
GtkWidget *img7;
GtkWidget *img8;
GtkWidget *img20;
GtkWidget *img21;
GtkWidget *l2;
l2=lookup_widget(modifiertroupeau,"l2");
img20=lookup_widget(modifiertroupeau,"img20");
img21=lookup_widget(modifiertroupeau,"img21");
img7=lookup_widget(modifiertroupeau,"img7");
img8=lookup_widget(modifiertroupeau,"img8");
labelnomt=lookup_widget(modifiertroupeau,"labelnomt");
entry2=lookup_widget(modifiertroupeau,"entry2");
combobox3=lookup_widget(modifiertroupeau,"combobox3");
combobox4=lookup_widget(modifiertroupeau,"combobox4");
calendar2=lookup_widget(modifiertroupeau,"calendar2");
gtk_label_set_text(GTK_LABEL(labelnomt),"");
gtk_label_set_text(GTK_LABEL(l2),"");
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry2),10);
gtk_widget_hide(img7);
gtk_widget_hide(img8);
gtk_widget_hide(img20);
gtk_widget_hide(img21);
FILE *f;
troupeau t;
char  nomt[30],nom1[30],nom2[30],idf[30];
int d,m,a;
f=fopen("projet.txt","r");
if(f!=NULL)
    {


        
        while(fscanf(f,"%s %s %s %s %d %d %d\n",nomt,nom1,nom2,idf,&d,&m,&a)!=EOF)
        {
	    	if(strcmp(idf0,idf)==0)
		{
		
            		strcpy(t.type,nomt);
            		strcpy(t.name,nom1);
            		strcpy(t.genre,nom2);
            		t.birth.jour=d;
            		t.birth.mois=m;
            		t.birth.annee=a;
			FILE *e;
			e=fopen("id.txt","w");
			fprintf(e,"%s",idf0);
			fclose(e);
            	}	
            
        }
        
        fclose(f);
     }
gtk_entry_set_text(GTK_ENTRY(entry2),t.name);
if(strcmp(t.type,"brebi")==0)
{
gtk_combo_box_set_active(combobox3,0);

}
if(strcmp(t.type,"veaux")==0)
{
gtk_combo_box_set_active(combobox3,1);
}
if(strcmp(t.genre,"male")==0)
{
gtk_combo_box_set_active(combobox4,0);
}
if(strcmp(t.genre,"female")==0)
{
gtk_combo_box_set_active(combobox4,1);
}
gtk_calendar_select_day(calendar2,t.birth.jour);
gtk_calendar_select_month(calendar2,t.birth.mois-1,t.birth.annee);

}
else
{
gtk_label_set_markup(GTK_LABEL(labelmod),"<span  foreground='#f90922'> *l'id n'existe pas!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(modifierid,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img9);
gtk_widget_hide(img10);
}

}

}

void
on_enregistrermodifier_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
troupeau p;
FILE *f;
int *d,*m,*a;
char id[10],inf[50];
GtkWidget *idtroupeaumodifier;
GtkWidget *modifiertroupeau;
GtkWidget *enregistrermodifier;
GtkWidget *combobox3;
GtkWidget *entry2;
GtkWidget *entry4;
GtkWidget *combobox4;
GtkWidget *calendar2;
GtkWidget *labelnomt;
GtkWidget *labelinf;
GtkWidget *img7;
GtkWidget *img8;
GtkWidget *img20;
GtkWidget *img21;
GtkWidget *l2;
GdkColor color;
GdkColor color1;
GdkColor color2;
GtkWidget *labelmod;
GtkWidget *modoui;
int y,s;
d=&p.birth.jour;
m=&p.birth.mois;
a=&p.birth.annee;

f=fopen("id.txt","r");
fscanf(f,"%s",id);
fclose(f);
img20=lookup_widget(objet_graphique,"img20");
img21=lookup_widget(objet_graphique,"img21");
l2=lookup_widget(objet_graphique,"l2");
img7=lookup_widget(objet_graphique,"img7");
img8=lookup_widget(objet_graphique,"img8");
enregistrermodifier=lookup_widget(objet_graphique,"enregistrermodifier");
calendar2=lookup_widget(objet_graphique,"calendar2");
combobox3=lookup_widget(objet_graphique,"combobox3");
combobox4=lookup_widget(objet_graphique,"combobox4");
labelnomt=lookup_widget(objet_graphique,"labelnomt");
entry2=lookup_widget(objet_graphique,"entry2");
strcpy(p.name,gtk_entry_get_text(GTK_ENTRY(entry2)));
strcpy(p.genre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
gtk_calendar_get_date(calendar2,a,m,d);
++*m;
s=verif( p.birth.jour,p.birth.mois,p.birth.annee, h);
y=alpha(p.name);
if(s==1)
{
gtk_label_set_markup(GTK_LABEL(l2),"<span  foreground='#f90922'> *verifier la date!!! </span>");
/*gdk_color_parse("#ff0000",&color2);
gtk_widget_modify_bg(enregistrermodifier,GTK_STATE_NORMAL,&color2);*/
gtk_widget_show(img21);
gtk_widget_hide(img20);
}
else
{
gtk_label_set_text(GTK_LABEL(l2),"");
gtk_widget_hide(img21);
gtk_widget_show(img20);
}

if(strcmp(p.name,"")==0)
{

gtk_label_set_markup(GTK_LABEL(labelnomt),"<span  foreground='#f90922'> *le champ nom est vide!!! </span>");
/*gdk_color_parse("#ff0000",&color1);
gtk_widget_modify_bg(enregistrermodifier,GTK_STATE_NORMAL,&color1);*/
gtk_widget_show(img7);
gtk_widget_hide(img8);
}
else
{
if(y==1)
{
gtk_label_set_markup(GTK_LABEL(labelnomt),"<span  foreground='#f90922'> *entrer des alphabets!!! </span>");
/*gdk_color_parse("#ff0000",&color1);
gtk_widget_modify_bg(enregistrermodifier,GTK_STATE_NORMAL,&color1);*/
gtk_widget_show(img7);
gtk_widget_hide(img8);
}
else
{
gtk_widget_show(img8);
gtk_widget_hide(img7);
gtk_label_set_text(labelnomt,"");

}
}
if((y!=1)&&(s==0))
{


/*gdk_color_parse("#32ff00",&color2);
gtk_widget_modify_bg(enregistrermodifier,GTK_STATE_NORMAL,&color2);*/

modifier( id, p);

modifiertroupeau=lookup_widget(objet_graphique,"modifiertroupeau");
gtk_widget_destroy(modifiertroupeau);
modoui = create_modoui ();
gtk_widget_show (modoui);

/*idtroupeaumodifier = create_idtroupeaumodifier ();
gtk_widget_show (idtroupeaumodifier);
labelinf=lookup_widget(idtroupeaumodifier,"labelinf");
labelmod=lookup_widget(idtroupeaumodifier,"labelmod");
entry4=lookup_widget(idtroupeaumodifier,"entry4");
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry4),5);
gtk_label_set_text(labelmod,"");
strcpy(inf,"vous avez modifier le troupeau d'id: ");
strcat(inf,id);
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(labelinf,GTK_STATE_NORMAL,&color);
gtk_label_set_text(labelinf,inf);*/



}

}


void
on_quittez_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f;
remove("nombre.txt");
f=fopen("remplace.txt","w");
fprintf(f,"%d",0);
fclose(f);
rename("remplace.txt","nombre.txt");




gtk_main_quit();


}


void
on_buttonmodifretour_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifiertroupeau;
GtkWidget *idtroupeaumodifier;
GtkWidget *entry4;
GtkWidget *labelmod;
GtkWidget *labelinf;
GtkWidget *img9;
GtkWidget *img10;


modifiertroupeau=lookup_widget(objet_graphique,"modifiertroupeau");
//idtroupeaumodifier=lookup_widget(objet_graphique,"idtroupeaumodifier");
if(zeta==0)
{
gtk_widget_destroy(modifiertroupeau);
idtroupeaumodifier = create_idtroupeaumodifier ();
gtk_widget_show (idtroupeaumodifier);
entry4=lookup_widget(idtroupeaumodifier,"entry4");
labelmod=lookup_widget(idtroupeaumodifier,"labelmod");
labelinf=lookup_widget(idtroupeaumodifier,"labelinf");
img9=lookup_widget(idtroupeaumodifier,"img9");
img10=lookup_widget(idtroupeaumodifier,"img10");
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry4),5);
gtk_entry_set_text(GTK_ENTRY(entry4),"");
gtk_label_set_text(GTK_LABEL(labelmod),"");
gtk_label_set_text(GTK_LABEL(labelinf),"");
gtk_widget_hide(img9);
gtk_widget_hide(img10);
}
else
{
gtk_widget_destroy(modifiertroupeau);
}

}


void
on_suppaff_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichagetroupeaux;
GtkWidget *windowsuppmod;
GtkWidget *entry3;
GtkWidget *labelsup;
GtkWidget *labelsup2;
GtkWidget *img11;



affichagetroupeaux=lookup_widget(objet_graphique,"affichagetroupeaux");
//idtroupeaumodifier=lookup_widget(objet_graphique,"idtroupeaumodifier");
gtk_widget_destroy(affichagetroupeaux);
windowsuppmod = create_windowsuppmod ();
gtk_widget_show (windowsuppmod);
entry3=lookup_widget(windowsuppmod,"entry3");
labelsup=lookup_widget(windowsuppmod,"labelsup");
labelsup2=lookup_widget(windowsuppmod,"labelsup2");
img11=lookup_widget(windowsuppmod,"img11");
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry3),5);
gtk_entry_set_text(GTK_ENTRY(entry3),"");
gtk_label_set_text(GTK_LABEL(labelsup),"");
gtk_label_set_text(GTK_LABEL(labelsup2),"");
gtk_widget_hide(img11);


}


void
on_supression_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int *kappa,a,y;
char value[10],idt[100];
a=0;
kappa=&a;
troupeau tab[100];
GtkWidget *labelsup;
GtkWidget *labelsup2;
GtkWidget *entry3;
GtkWidget *img11;
GtkWidget *alerte;
GtkWidget *lab;
GdkColor color;
int x;
GtkWidget *supression;
GtkWidget *windowsuppmod;
GdkColor color1;
GdkColor color2;
GdkColor color3;
supression=lookup_widget(objet_graphique,"supression");
img11=lookup_widget(objet_graphique,"img11");
labelsup=lookup_widget(objet_graphique,"labelsup");
labelsup2=lookup_widget(objet_graphique,"labelsup2");
entry3=lookup_widget(objet_graphique,"entry3");
windowsuppmod=lookup_widget(objet_graphique,"windowsuppmod");
strcpy(value,gtk_entry_get_text(GTK_ENTRY(entry3)));
y=maj(value);
if(strcmp(value,"")==0)
{
gtk_label_set_markup(GTK_LABEL(labelsup),"<span  foreground='#f90922'> *le champ est vide!!! </span>");
/*gdk_color_parse("#ff0000",&color1);
gtk_widget_modify_bg(supression,GTK_STATE_NORMAL,&color1);*/
gtk_widget_show(img11);
}
else
if(y==1)
{
gtk_label_set_markup(GTK_LABEL(labelsup),"<span  foreground='#f90922'> *entrer des MAJUSCULE et des chiffres!!! </span>");
/*gdk_color_parse("#ff0000",&color1);
gtk_widget_modify_bg(supression,GTK_STATE_NORMAL,&color1);*/
gtk_widget_show(img11);
}
else
if((y!=1)&&(strcmp(value,"")!=0))
{
x=idmodifier(value);
if(x==1)
{
gtk_widget_destroy(windowsuppmod);
alerte = create_alerte ();
gtk_widget_show (alerte);
lab=lookup_widget(alerte,"lab");
strcpy(idt,value);
strcat(idt," ?");
//char t[100];
//strcpy(t,"!!!voulez vous supprimer le troupeau d'id: ");
//strcat(t,value);
GdkColor color3;
gdk_color_parse("black",&color3);
gtk_widget_modify_fg(lab,GTK_STATE_NORMAL,&color3);
gtk_label_set_text(lab,idt);
FILE *t;
t=fopen("id.txt","w");
fprintf(t,"%s",value);
fclose(t);


/*supprimer(tab,100,value,kappa);
if(*kappa==1)
{
gtk_widget_destroy(windowsuppmod);
alerte = create_alerte ();
gtk_widget_show (alerte);
lab=lookup_widget(alerte,"lab");
//char t[100];
//strcpy(t,"!!!voulez vous supprimer le troupeau d'id: ");
//strcat(t,value);
GdkColor color3;
gdk_color_parse("red",&color3);
gtk_widget_modify_fg(lab,GTK_STATE_NORMAL,&color3);
gtk_label_set_text(lab,value);*/

/*gdk_color_parse("#32ff00",&color2);
gtk_widget_modify_bg(supression,GTK_STATE_NORMAL,&color2);

strcpy(idt,"la suppression du troupeau d'id: ");
strcat(idt,value);
strcat(idt," a été effectuée avec succes.");
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(labelsup2,GTK_STATE_NORMAL,&color);
gtk_label_set_text(labelsup2,idt);
gtk_entry_set_text(GTK_ENTRY(entry3),"");*/

}
else
{
gtk_label_set_markup(GTK_LABEL(labelsup),"<span  foreground='#f90922'> *l'id n'existe pas!!! </span>");
/*gdk_color_parse("#ff0000",&color1);
gtk_widget_modify_bg(supression,GTK_STATE_NORMAL,&color1);*/
}

}
}


void
on_supretour_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowsuppmod;
GtkWidget *affichagetroupeaux;
GtkWidget *treeview1;
windowsuppmod=lookup_widget(objet,"windowsuppmod");
gtk_widget_destroy(windowsuppmod);
affichagetroupeaux=lookup_widget(objet,"affichagetroupeaux");
affichagetroupeaux=create_affichagetroupeaux();
gtk_widget_show(affichagetroupeaux);
treeview1=lookup_widget(affichagetroupeaux,"treeview1");
affichage(treeview1);

}


void
on_b_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active (togglebutton))
t[0]=1;
else
t[0]=0;


}


void
on_v_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active (togglebutton))
t[1]=1;
else
t[1]=0;

}


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;

GtkWidget *affichagetroupeaux;
GtkWidget *treeview1;
affichagetroupeaux=lookup_widget(objet,"affichagetroupeaux");
gtk_widget_destroy(affichagetroupeaux);
affichagetroupeaux=lookup_widget(objet,"affichagetroupeaux");
affichagetroupeaux=create_affichagetroupeaux();
gtk_widget_show(affichagetroupeaux);
treeview1=lookup_widget(affichagetroupeaux,"treeview1");
filtre();
if((t[0]==1)&&(t[1]==1))
affichage(treeview1);
else
if(t[0]==1)
affichage1(treeview1);
else
if(t[1]==1)
affichage2(treeview1);
else
if((t[0]==0)&&(t[1]==0))
affichage(treeview1);


remove("brebi.txt");
remove("veaux.txt");

f=fopen("tab.txt","w");
fprintf(f,"%d %d ",t[0],t[1]);
fclose(f);

t[0]=0;
t[1]=0;



}


void
on_Confirmer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *typedetroupeaux;
GtkWidget *typeinf;
GtkWidget *tpi;
GdkColor color;
typedetroupeaux=lookup_widget(objet_graphique,"typedetroupeaux");

int *b,*v,*t,a=0,e=0,c=0;
char inf[50],rec[10];
b=&a;
v=&e;
t=&c;
nombre(b,v,t);
if(xx==1)
{
gtk_widget_destroy(typedetroupeaux);
typeinf=create_typeinf();
gtk_widget_show(typeinf);
tpi=lookup_widget(typeinf,"tpi");
sprintf(rec,"%d",a);
strcpy(inf,"Le nombre de brebis est: ");
strcat(inf,rec);
gdk_color_parse("black",&color);
gtk_widget_modify_fg(tpi,GTK_STATE_NORMAL,&color);
gtk_label_set_text(tpi,inf);


} 
else
if(xx==2)
{
gtk_widget_destroy(typedetroupeaux);
typeinf=create_typeinf();
gtk_widget_show(typeinf);
tpi=lookup_widget(typeinf,"tpi");
sprintf(rec,"%d",e);
strcpy(inf,"Le nombre de veaux est: ");
strcat(inf,rec);
gdk_color_parse("black",&color);
gtk_widget_modify_fg(tpi,GTK_STATE_NORMAL,&color);
gtk_label_set_text(tpi,inf);
}
else
if(xx==3)
{
gtk_widget_destroy(typedetroupeaux);
typeinf=create_typeinf();
gtk_widget_show(typeinf);
tpi=lookup_widget(typeinf,"tpi");
sprintf(rec,"%d",c);
strcpy(inf,"Le nombre totale du troupeaux est: ");
strcat(inf,rec);
gdk_color_parse("black",&color);
gtk_widget_modify_fg(tpi,GTK_STATE_NORMAL,&color);
gtk_label_set_text(tpi,inf);
}
xx=3;

}


void
on_retaff_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *typedetroupeaux;
GtkWidget *affichagetroupeaux;
GtkWidget *treeview1;
typedetroupeaux=lookup_widget(objet,"typedetroupeaux");
gtk_widget_destroy(typedetroupeaux);
//typedetroupeaux=lookup_widget(objet,"typedetroupeaux");
affichagetroupeaux=create_affichagetroupeaux();
gtk_widget_show(affichagetroupeaux);
treeview1=lookup_widget(affichagetroupeaux,"treeview1");
affichage(treeview1);
                                      

}


void
on_okajout_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *type;
GtkWidget *nom;
GtkWidget *genre;
GtkWidget *windowtroupeaux;
GtkWidget *ajoutoui;
GtkWidget *labelajouter;
GtkWidget *combotype;
GtkWidget *combo1;
GtkWidget *entrynom;
GtkWidget *buttonajoutetroupeaux;
GdkColor color;
GdkColor color1;
GtkWidget *img1;
GtkWidget *img2;
GtkWidget *img3;
GtkWidget *img4;
GtkWidget *img5;
GtkWidget *img6;
GtkWidget *img15;
GtkWidget *img16;
GtkWidget *l1;
ajoutoui=lookup_widget(objet_graphique,"ajoutoui");
gtk_widget_destroy (ajoutoui);
windowtroupeaux = create_windowtroupeaux ();
gtk_widget_show (windowtroupeaux);
labelajouter=lookup_widget(windowtroupeaux,"labelajouter");
combotype=lookup_widget(windowtroupeaux,"combotype");
combo1=lookup_widget(windowtroupeaux,"combo1");
entrynom=lookup_widget(windowtroupeaux,"entrynom");
buttonajoutetroupeaux=lookup_widget(windowtroupeaux,"buttonajoutetroupeaux");
img1=lookup_widget(windowtroupeaux,"img1");
img2=lookup_widget(windowtroupeaux,"img2");
img3=lookup_widget(windowtroupeaux,"img3");
img4=lookup_widget(windowtroupeaux,"img4");
img5=lookup_widget(windowtroupeaux,"img5");
img6=lookup_widget(windowtroupeaux,"img6");
type=lookup_widget(windowtroupeaux,"type");
nom=lookup_widget(windowtroupeaux,"nom");
genre=lookup_widget(windowtroupeaux,"genre");
img16=lookup_widget(windowtroupeaux,"img16");
img15=lookup_widget(windowtroupeaux,"img15");
l1=lookup_widget(windowtroupeaux,"l1");
gtk_widget_hide(img1);
gtk_widget_hide(img2);
gtk_widget_hide(img3);
gtk_widget_hide(img4);
gtk_widget_hide(img5);
gtk_widget_hide(img6);
gtk_widget_hide(img15);
gtk_widget_hide(img16);
gtk_label_set_text(GTK_LABEL(type),"");
gtk_label_set_text(GTK_LABEL(nom),"");
gtk_label_set_text(GTK_LABEL(genre),"");
gtk_label_set_text(GTK_LABEL(l1),"");

int n;
char ac[30];
char ab[30];
FILE *a;
FILE *aa;
a=fopen("nombre.txt","r");
fscanf(a,"%d",&n);
fclose(a);
n++;
aa=fopen("nombre.txt","w");
fprintf(aa,"%d",n);
fclose(aa);
sprintf(ac,"%d",n);
strcpy(ab,"vous avez ajoutee");
strcat(ab,ac);
strcat(ab," troupeau.");
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(labelajouter,GTK_STATE_NORMAL,&color);
/*gdk_color_parse("#32ff00",&color1);
gtk_widget_modify_bg(buttonajoutetroupeaux,GTK_STATE_NORMAL,&color1);*/



gtk_label_set_text(GTK_LABEL(labelajouter),ab);
gtk_combo_box_set_active(combotype,0);
gtk_combo_box_set_active(combo1,0);
gtk_entry_set_text(entrynom,"");


}


void
on_okmod_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[10],inf[100];
GtkWidget *idtroupeaumodifier;
GtkWidget *labelinf;
GtkWidget *labelmod;
GtkWidget *entry4;
GtkWidget *img9;
GtkWidget *img10;
GtkWidget *modoui;
FILE *f;
GdkColor color;
modoui=lookup_widget(objet_graphique,"modoui");
gtk_widget_destroy(modoui);
if(zeta==0)
{
idtroupeaumodifier = create_idtroupeaumodifier ();
gtk_widget_show (idtroupeaumodifier);
labelinf=lookup_widget(idtroupeaumodifier,"labelinf");
labelmod=lookup_widget(idtroupeaumodifier,"labelmod");
entry4=lookup_widget(idtroupeaumodifier,"entry4");
img9=lookup_widget(idtroupeaumodifier,"img9");
img10=lookup_widget(idtroupeaumodifier,"img10");
gtk_widget_hide(img9);
gtk_widget_hide(img10);
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry4),5);
gtk_label_set_text(labelmod,"");
FILE *ff;
char id1[30];
f=fopen("id.txt","r");
fscanf(f,"%s",id);
fclose(f);
ff=fopen("idnouv.txt","r");
fscanf(ff,"%s",id1);
fclose(ff);
strcpy(inf,"vous avez modifier le troupeau d'ancien id: ");
strcat(inf,id);
strcat(inf," et de nouveau id: ");
strcat(inf,id1);
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(labelinf,GTK_STATE_NORMAL,&color);
gtk_label_set_text(labelinf,inf);
}
else
{
gtk_widget_destroy(modoui);
}
zeta=0;
}


void
on_suppok_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *suppoui;
GtkWidget *windowsuppmod;
GtkWidget *entry3;
GtkWidget *labelsup;
GtkWidget *labelsup2;
GtkWidget *img11;
GdkColor color;



suppoui=lookup_widget(objet_graphique,"suppoui");
//idtroupeaumodifier=lookup_widget(objet_graphique,"idtroupeaumodifier");
gtk_widget_destroy(suppoui);
windowsuppmod = create_windowsuppmod ();
gtk_widget_show (windowsuppmod);
entry3=lookup_widget(windowsuppmod,"entry3");
labelsup=lookup_widget(windowsuppmod,"labelsup");
labelsup2=lookup_widget(windowsuppmod,"labelsup2");
img11=lookup_widget(windowsuppmod,"img11");
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry3),5);
gtk_entry_set_text(GTK_ENTRY(entry3),"");
gtk_label_set_text(GTK_LABEL(labelsup),"");
gtk_label_set_text(GTK_LABEL(labelsup2),"");
gtk_widget_hide(img11);
char inf[100],id[10];
FILE *f;
f=fopen("id.txt","r");
fscanf(f,"%s",id);
fclose(f);
strcpy(inf,"Vous avez supprimer le troupeau d'id: ");
strcat(inf,id);
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(labelsup2,GTK_STATE_NORMAL,&color);
gtk_label_set_text(labelsup2,inf);


}


void
on_oui_clicked                         (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *suppoui;
GtkWidget *alerte;

FILE *f;
char id[10];
int *kappa,a=0;
troupeau tab[100];
kappa=&a;
f=fopen("id.txt","r");
fscanf(f,"%s",id);
fclose(f);

supprimer(tab,100,id,kappa);
alerte=lookup_widget(objet_graphique,"alerte");
gtk_widget_destroy(alerte);
suppoui = create_suppoui();
gtk_widget_show (suppoui);
//lab=lookup_widget(alerte,"lab");
//char t[100];
//strcpy(t,"!!!voulez vous supprimer le troupeau d'id: ");
//strcat(t,value);
/*GdkColor color3;
gdk_color_parse("red",&color3);
gtk_widget_modify_fg(lab,GTK_STATE_NORMAL,&color3);
gtk_label_set_text(lab,value);*/

/*gdk_color_parse("#32ff00",&color2);
gtk_widget_modify_bg(supression,GTK_STATE_NORMAL,&color2);

strcpy(idt,"la suppression du troupeau d'id: ");
strcat(idt,value);
strcat(idt," a été effectuée avec succes.");
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(labelsup2,GTK_STATE_NORMAL,&color);
gtk_label_set_text(labelsup2,idt);
gtk_entry_set_text(GTK_ENTRY(entry3),"");*/



}


void
on_non_clicked                         (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *alerte;
GtkWidget *windowsuppmod;
GtkWidget *entry3;
GtkWidget *labelsup;
GtkWidget *labelsup2;
GtkWidget *img11;



alerte=lookup_widget(objet_graphique,"alerte");
//idtroupeaumodifier=lookup_widget(objet_graphique,"idtroupeaumodifier");
gtk_widget_destroy(alerte);
windowsuppmod = create_windowsuppmod ();
gtk_widget_show (windowsuppmod);
entry3=lookup_widget(windowsuppmod,"entry3");
labelsup=lookup_widget(windowsuppmod,"labelsup");
labelsup2=lookup_widget(windowsuppmod,"labelsup2");
img11=lookup_widget(windowsuppmod,"img11");
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry3),5);
gtk_entry_set_text(GTK_ENTRY(entry3),"");
gtk_label_set_text(GTK_LABEL(labelsup),"");
gtk_label_set_text(GTK_LABEL(labelsup2),"");
gtk_widget_hide(img11);



}


void
on_okfin_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *suppfin;
GtkWidget *affichagetroupeaux;
GtkWidget *treeview1;
//affichagetroupeaux=lookup_widget(objet,"affichagetroupeaux");
suppfin=lookup_widget(objet,"suppfin");
//gtk_widget_destroy(affichagetroupeaux);
gtk_widget_destroy(suppfin);



/*affichagetroupeaux=create_affichagetroupeaux();
gtk_widget_show(affichagetroupeaux);
treeview1=lookup_widget(affichagetroupeaux,"treeview1");
affichage(treeview1);*/




}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;

GdkColor color;
GtkWidget *alerteopp;
GtkWidget *opplab;
char mot[50];

char id0[30];
gchar *id;
FILE *f;
f=fopen("id.txt","w");

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,3,&id,-1);
strcpy(id0,id);
fprintf(f,"%s",id0);
fclose(f);
strcpy(mot,"Choisir l'opération sur le troupeau d'id :");
strcat(mot,id0);

alerteopp = create_alerteopp ();
gtk_widget_show (alerteopp);
opplab=lookup_widget(alerteopp,"opplab");
gdk_color_parse("black",&color);
gtk_widget_modify_fg(opplab,GTK_STATE_NORMAL,&color);
gtk_label_set_text(opplab,mot);



}

}


void
on_brebi_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
xx=1;

}


void
on_veaux_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
xx=2;

}


void
on_totale_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
xx=3;
}


void
on_oktype_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *typedetroupeaux;
GtkWidget *typeinf;
GtkWidget *totale;
typeinf=lookup_widget(objet,"typeinf");
gtk_widget_destroy(typeinf);
typedetroupeaux=create_typedetroupeaux();
gtk_widget_show(typedetroupeaux);
totale=lookup_widget(typedetroupeaux,"totale");
gtk_toggle_button_set_active (totale,"true");

}




void
on_oppsupp_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *suppfin;
GtkWidget *fin;
GtkWidget *alerteopp;
GdkColor color;






int *k,a=0;
char id0[10];
troupeau tab[100];
k=&a;
alerteopp=lookup_widget(objet_graphique,"alerteopp");
gtk_widget_destroy(alerteopp);
FILE *f;
f=fopen("id.txt","r");
fscanf(f,"%s",id0);
fclose(f);
supprimer(tab,100,id0,k);
suppfin = create_suppfin ();
gtk_widget_show (suppfin);
fin=lookup_widget(suppfin,"fin");
gdk_color_parse("black",&color);
gtk_widget_modify_fg(fin,GTK_STATE_NORMAL,&color);
gtk_label_set_text(fin,id0);



}


void
on_oppmod_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

char idf0[30];
GtkWidget *alerteopp;
alerteopp=lookup_widget(objet_graphique,"alerteopp");
gtk_widget_destroy(alerteopp);
GtkWidget *modifiertroupeau;
FILE *k;
k=fopen("id.txt","r");
fscanf(k,"%s",idf0);
fclose(k);
//modifiertroupeaux=lookup_widget(objet_graphique,"modifiertroupeaux");
modifiertroupeau = create_modifiertroupeau ();
gtk_widget_show (modifiertroupeau);
GtkWidget *entry2;
GtkWidget *combobox3;
GtkWidget *combobox4;
GtkWidget *calendar2;
GtkWidget *labelnomt;
GtkWidget *img7;
GtkWidget *img8;
GtkWidget *img20;
GtkWidget *img21;
GtkWidget *l2;
l2=lookup_widget(modifiertroupeau,"l2");
img20=lookup_widget(modifiertroupeau,"img20");
img21=lookup_widget(modifiertroupeau,"img21");
img7=lookup_widget(modifiertroupeau,"img7");
img8=lookup_widget(modifiertroupeau,"img8");
labelnomt=lookup_widget(modifiertroupeau,"labelnomt");
entry2=lookup_widget(modifiertroupeau,"entry2");
combobox3=lookup_widget(modifiertroupeau,"combobox3");
combobox4=lookup_widget(modifiertroupeau,"combobox4");
calendar2=lookup_widget(modifiertroupeau,"calendar2");
gtk_label_set_text(GTK_LABEL(labelnomt),"");
gtk_label_set_text(GTK_LABEL(l2),"");
gtk_entry_buffer_set_max_length(gtk_entry_get_buffer(entry2),10);
gtk_widget_hide(img7);
gtk_widget_hide(img8);
gtk_widget_hide(img20);
gtk_widget_hide(img21);
FILE *f;
troupeau t;
char  nomt[30],nom1[30],nom2[30],idf[30];
int d,m,a;
f=fopen("projet.txt","r");
if(f!=NULL)
    {


        
        while(fscanf(f,"%s %s %s %s %d %d %d\n",nomt,nom1,nom2,idf,&d,&m,&a)!=EOF)
        {
	    	if(strcmp(idf0,idf)==0)
		{
		
            		strcpy(t.type,nomt);
            		strcpy(t.name,nom1);
            		strcpy(t.genre,nom2);
            		t.birth.jour=d;
            		t.birth.mois=m;
            		t.birth.annee=a;
			FILE *e;
			e=fopen("id.txt","w");
			fprintf(e,"%s",idf0);
			fclose(e);
            	}	
            
        }
        
        fclose(f);
     }
gtk_entry_set_text(GTK_ENTRY(entry2),t.name);
if(strcmp(t.type,"brebi")==0)
{
gtk_combo_box_set_active(combobox3,0);

}
if(strcmp(t.type,"veaux")==0)
{
gtk_combo_box_set_active(combobox3,1);
}
if(strcmp(t.genre,"male")==0)
{
gtk_combo_box_set_active(combobox4,0);
}
if(strcmp(t.genre,"female")==0)
{
gtk_combo_box_set_active(combobox4,1);
}
gtk_calendar_select_day(calendar2,t.birth.jour);
gtk_calendar_select_month(calendar2,t.birth.mois-1,t.birth.annee);
zeta=1;

}


void
on_annuller_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *alerteopp;
alerteopp=lookup_widget(objet,"alerteopp");
gtk_widget_destroy(alerteopp);

}

