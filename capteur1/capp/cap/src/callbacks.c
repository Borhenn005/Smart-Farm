#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include <string.h>
int x=1;
int y =2;
int z=1;
int w=1;

void
on_treeview_gestion_capteur_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*GtkTreeIter Iter;	
	gchar* Reference;
	gchar* Nomdecapteur;
	gchar* Valeur;
	gchar* service;
	gchar* Prix;
	gchar* Etat;
	gchar* jourofcapteur;
	gchar* moisofcapteur;
	gchar* anneeofcapteur;

	char num_Reference[20];	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if(gtk_tree_model_get_iter(model,&Iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&Iter,0,&Reference,1,&Nomdecapteur,2,&Valeur,3,&service,4,&Prix,5,&Etat,6,&jourofcapteur,7,&moisofcapteur,8,&moisofcapteur,9,anneeofcapteur,-1);
		
		strcpy(num_Reference,Reference);
		supprimer_capteur(num_Reference);
	
}*/


}


void
on_gescaptomenu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_openaddcap_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;	
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"gestioncapteur");
	window2 = create_addCapteur();
  	gtk_widget_destroy(window1);
	gtk_widget_show(window2);
}


void
on_affcap_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;	
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"gestioncapteur");
	window2 = lookup_widget(window1,"treeview1");
  	afficher_capteur(window2);

}


void
on_opendelcap_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;	
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"gestioncapteur");
	window2 = create_DelCapteur();
  	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

}


void
on_openeditcap_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;	
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"gestioncapteur");
	window2 = create_editCapteur();
  	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

}


void
on_retourajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;	
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"addCapteur");
	window2= create_gestioncapteur();
  	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

}


void
on_button_confirmer_ajouter_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input8;
	GtkWidget *output;
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *output3;
	GtkWidget *output4;
	GtkWidget *output5;
	
	int p,o,i,u,l;
	

	char texte[200];

	capteur c;

	input1=lookup_widget(objet,"nomcapadd");
	input2=lookup_widget(objet,"refcapadd");
	input3=lookup_widget(objet,"vavaadd");
	input4=lookup_widget(objet,"spinbutton3");
	input5=lookup_widget(objet,"spinbutton1");
	input6=lookup_widget(objet,"spinbutton2");
	input8=lookup_widget(objet,"prixadd");
	
	


	if (w==1){
		strcpy(c.service,"Temperature");
}
	else if(w==2){
		strcpy(c.service,"Humidité");
}
	
	if(x==1){
		strcpy(c.Etat,"Fonctionnel");
	}
	else if(x==2){
		strcpy(c.Etat,"Defectueux");
	}
	
	
	strcpy(c.Nomdecapteur,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(c.Reference,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(c.Valeur,gtk_entry_get_text(GTK_ENTRY(input3)));
	c.jourofcapteur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
	c.moisofcapteur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
	c.anneeofcapteur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
	strcpy(c.Prix,gtk_entry_get_text(GTK_ENTRY(input8)));
	

	p=RefExist(c.Reference);
	output1 = lookup_widget(objet,"labelRe");
	if(!p){
	gtk_label_set_text(GTK_LABEL(output1),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(output1),"❌");
	}
	o=verifSal(c.Valeur);
	output2 = lookup_widget(objet,"labelValeur");
	if(o){
	gtk_label_set_text(GTK_LABEL(output2),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(output2),"❌");
	}

	i=verifSal(c.Prix);
	output3 = lookup_widget(objet,"labelPRIX");
	if(i){
	gtk_label_set_text(GTK_LABEL(output3),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(output3),"❌");
	}

	u=verifName(c.Nomdecapteur);
	output4 = lookup_widget(objet,"labelNo");
	if(u){
	gtk_label_set_text(GTK_LABEL(output4),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(output4),"❌");
	}

	l=verifier_date(c.jourofcapteur,c.moisofcapteur,c.anneeofcapteur);
	output5 = lookup_widget(objet,"labelDate");
	if(l){
	gtk_label_set_text(GTK_LABEL(output5),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(output5),"❌");
	}

	if(!p&&o&&i&&u&&l){
		ajouter_capteur(c);
		sprintf(texte,"Capteur ajouté avec succés");
		output = lookup_widget(objet,"outputaddcap");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
	}
	else{		
		sprintf(texte,"Verfier vos données !");
		output = lookup_widget(objet,"outputaddcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);	
	}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        x = 1;
	}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        x = 2;
	}
}


void
on_suppcap_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input;
	GtkWidget *output;
	char ref[20];
	char texte[100];

	input = lookup_widget(objet_graphique,"referencedelcap");
	strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
	
	if(RefExist(ref)){
		supprimer_capteur(ref);		
		sprintf(texte,"Votre suppression à été effectué avec succés\n");
		output = lookup_widget(objet_graphique,"outputsuppcap");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
		char reset[20];
		sprintf(reset,"");
		gtk_entry_set_text(GTK_ENTRY(input),reset);
		
	}
	else{
		sprintf(texte,"Reference  n'existe pas\n");
		output = lookup_widget(objet_graphique,"outputsuppcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);	
	}

}


void
on_retoursuppcap_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;	
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"DelCapteur");
	window2= create_gestioncapteur();
  	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

}


void
on_consulter_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	char ref[20];
	GtkWidget *input1;
	input1 = lookup_widget(objet_graphique,"referenceedit");
	strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));

	char texte1[20],texte2[20],texte3[20],texte4[20];
	char outputmessage[100];
	GtkWidget *outputnom;
	GtkWidget *outputservice;
	GtkWidget *outputprix;
	GtkWidget *outputval;
	GtkWidget *output10;
	if(RefExist(ref)==0){
		sprintf(outputmessage,"Réference n'existe pas\n");
		output10 = lookup_widget(objet_graphique,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
	}
	else{
		capteur c;
		strcpy(c.Nomdecapteur,find_cap(ref).Nomdecapteur);
		strcpy(c.Valeur,find_cap(ref).Valeur);
		strcpy(c.service,find_cap(ref).service);
		strcpy(c.Prix,find_cap(ref).Prix);
		
			
		sprintf(outputmessage,"Tapez vos nouveau donnée puis cliquez sur\n\tenregistrer les modifications\n");
		output10 = lookup_widget(objet_graphique,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#0c8ae8", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);		

		sprintf(texte1,"%s",c.Nomdecapteur);
		outputnom = lookup_widget(objet_graphique,"nameedit");
    		gtk_entry_set_text(GTK_ENTRY(outputnom),texte1);

		sprintf(texte2,"%s",c.Valeur);
		outputval = lookup_widget(objet_graphique,"valeuredit");
    		gtk_entry_set_text(GTK_ENTRY(outputval),texte2);
		
		sprintf(texte3,"%s",c.service);
		outputservice = lookup_widget(objet_graphique,"serviceedit");
    		gtk_entry_set_text(GTK_ENTRY(outputservice),texte3);

		sprintf(texte4,"%s",c.Prix);
		outputprix = lookup_widget(objet_graphique,"prixedit");
    		gtk_entry_set_text(GTK_ENTRY(outputprix),texte4);
	}
}


void
on_saveeditcap_enter                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *output2;
	GtkWidget *output3;
	GtkWidget *output4;
	

	GtkWidget *output10;
	int o,i,u;

	char ref[20];

	char outputmessage[100];
	input1 = lookup_widget(objet_graphique,"referenceedit");
	strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));
	if(!RefExist(ref)){
		sprintf(outputmessage,"Reference n'existe pas\n");
		output10 = lookup_widget(objet_graphique,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
	}
	else{	
		capteur c;
		strcpy(c.Reference,ref);

		input1 = lookup_widget(objet_graphique,"nameedit");
		
		input3 = lookup_widget(objet_graphique,"prixedit");
		input4 = lookup_widget(objet_graphique,"valeuredit");
		

		if (z==1){
		strcpy(c.service,"Temperature");
}
		else if(z==2){
		strcpy(c.service,"Humidité");
}
		
		
		if(y==1){
		strcpy(c.Etat,"Fonctionnel");
		}
		else if(y==2){
			strcpy(c.Etat,"Defectueux");
		}

		
		
		strcpy(c.Nomdecapteur,gtk_entry_get_text(GTK_ENTRY(input1)));
		
		strcpy(c.Prix,gtk_entry_get_text(GTK_ENTRY(input3)));
		strcpy(c.Valeur,gtk_entry_get_text(GTK_ENTRY(input4)));

		c.jourofcapteur = find_cap(ref).jourofcapteur;
		c.moisofcapteur = find_cap(ref).moisofcapteur;
		c.anneeofcapteur = find_cap(ref).anneeofcapteur;
		o=verifSal(c.Valeur);
		output2 = lookup_widget(objet_graphique,"labelVal");
		if(o){
		gtk_label_set_text(GTK_LABEL(output2),"✔️");
		}
		else{
			gtk_label_set_text(GTK_LABEL(output2),"❌");
		}

		i=verifSal(c.Prix);
		output3 = lookup_widget(objet_graphique,"labelPri");
		if(i){
		gtk_label_set_text(GTK_LABEL(output3),"✔️");
		}
		else{
			gtk_label_set_text(GTK_LABEL(output3),"❌");
		}

		u=verifName(c.Nomdecapteur);
		output4 = lookup_widget(objet_graphique,"labelNom");
		if(u){
		gtk_label_set_text(GTK_LABEL(output4),"✔️");
		}
		else{
			gtk_label_set_text(GTK_LABEL(output4),"❌");
		}
		if(o && i && u){
		
		modifier_capteur(c);
		sprintf(outputmessage,"Votre modification a été effectué avec succés\n");
		output10 = lookup_widget(objet_graphique,"outputeditcap");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output10, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
		

		char reset[20];
		sprintf(reset,"");
		gtk_entry_set_text(GTK_ENTRY(input1),reset);
		
		gtk_entry_set_text(GTK_ENTRY(input3),reset);
		gtk_entry_set_text(GTK_ENTRY(input4),reset);
		}
		
		
	}	
}


void
on_lastgescap_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window1;	
	GtkWidget *window2;
	window1 = lookup_widget(objet_graphique,"editCapteur");
	window2= create_gestioncapteur();
  	gtk_widget_destroy(window1);
	gtk_widget_show(window2);

}


void
on_treeview_calssement_ouvrier_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_retour_calssmenet_ouvrier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retour_ouvrier_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        y = 2;
	}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        y = 1;
	}
}


void
on_radiobuttonTem_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        w= 1;
	}

}


void
on_radiobuttonHum_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        w= 2;
	}

}


void
on_radiobuttonTe_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        z = 1;
	}

}


void
on_radiobuttonHu_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        z = 2;
	}

}


void
on_defectueux_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget*capteurdef;
GtkWidget*gestioncapteur;
GtkWidget*treeviewdef;
gestioncapteur=lookup_widget(objet,"gestioncapteur");
gtk_widget_destroy(gestioncapteur);
capteurdef=create_capteurdef();
gtk_widget_show(capteurdef);
treeviewdef=lookup_widget(capteurdef,"treeviewdef");
defectuex();
afficherdef(treeviewdef);
remove("capteurdef.txt");



}

