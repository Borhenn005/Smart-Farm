#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"


void
on_creecompte_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_login_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_add_client_back_6_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowAddClient");
	window2 = create_windowGesClient ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_add_client_confirm_6_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *input9;
	GtkWidget *input10;
	GtkWidget *output;
        GtkWidget *outputId;
	GtkWidget *outputcity;
	GtkWidget *outputadress;
        GtkWidget *outputPrenom;
	GtkWidget *outputNom;
	GtkWidget *outputNum;
	GtkWidget *outputdateee;
	GtkWidget *outputmaiil;
	Client c;
	input1 = lookup_widget(objet_graphique,"entryid");
	input2 = lookup_widget(objet_graphique,"entry_first_name_6");
	input3 = lookup_widget(objet_graphique,"entry_last_name_6");
	input4 = lookup_widget(objet_graphique,"spinbutton_day_6");
	input5 = lookup_widget(objet_graphique,"spinbutton_mouth_6");
	input6 = lookup_widget(objet_graphique,"spinbutton_year_6");
	input7 = lookup_widget(objet_graphique,"entry_email_6");
	input8 = lookup_widget(objet_graphique,"entry_adress_6");
	input9 = lookup_widget(objet_graphique,"entry_phone_number_6");
	input10 = lookup_widget(objet_graphique,"entry_city_6");

	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));

	c.dateNaissance.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
	c.dateNaissance.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
	c.dateNaissance.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));

	strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input8)));
	strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input9)));
	strcpy(c.ville,gtk_entry_get_text(GTK_ENTRY(input10)));
	char texte[200];
        int test1,test2,test3,test4,test5,test6,test7,test8;
	
	/*----------- CONTROLE DE SAISIE --------------------*/
	test1 = idExiste(c.id);
	outputId = lookup_widget(objet_graphique,"idclientVerif");
	if(!test1){
		gtk_label_set_text(GTK_LABEL(outputId),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputId),"❌");
	}
        test2 = verifName(c.nom);
	outputNom = lookup_widget(objet_graphique,"lalelnom");
	if(test2){
		gtk_label_set_text(GTK_LABEL(outputNom),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputNom),"❌");
	}

	/*-------------------------------------------------------*/
	test3= verifName(c.prenom);
	outputPrenom = lookup_widget(objet_graphique,"lalelprenom");
	if(test3){
		gtk_label_set_text(GTK_LABEL(outputPrenom),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputPrenom),"❌");
	}

     	test4 = verifName(c.adresse);
	outputadress = lookup_widget(objet_graphique,"laleladress");
	if(test4){
		gtk_label_set_text(GTK_LABEL(outputadress),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputadress),"❌");
	}

	/*-------------------------------------------------------*/
	test5= verifName(c.ville);
	outputcity  = lookup_widget(objet_graphique,"lalelville");
	if(test5){
		gtk_label_set_text(GTK_LABEL(outputcity),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputcity),"❌");
	}
	test6 = verifNum(c.num);
	outputNum = lookup_widget(objet_graphique,"lalelnum");
	if(test6){
		gtk_label_set_text(GTK_LABEL(outputNum),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputNum),"❌");
	}
	test7 = verifier_date(c.dateNaissance.j,c.dateNaissance.m,c.dateNaissance.a);
	outputdateee = lookup_widget(objet_graphique,"dateNclieAdd");
	if(test7){
		gtk_label_set_text(GTK_LABEL(outputdateee),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputdateee),"❌");
	}
	
	if(!test1 && test2 && test3 && test4 && test5 && test6 && test7 ){
			
         ajouter_client(c);
		sprintf(texte,"Votre Client a été ajouter avec succés\n");
		output = lookup_widget(objet_graphique,"resultaddCl");
    		gtk_label_set_text(GTK_LABEL(output),texte);
	}
	else{
		sprintf(texte,"Verifer vos donneés\n");
		output = lookup_widget(objet_graphique,"resultaddCl");
    		gtk_label_set_text(GTK_LABEL(output),texte);
	}
}


void
on_consultclient_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	char id[10];
	GtkWidget *input1;
	input1 = lookup_widget(objet_graphique,"idclientEdit");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	char texte1[30],texte2[30],texte3[30],texte4[30],texte5[30],texte6[20];
	char outputmessage[100];
	GtkWidget *outputnom;
	GtkWidget *outputprenom;
	GtkWidget *outputemail;
	GtkWidget *outputville;
	GtkWidget *outputadresse;
	GtkWidget *outputnumtel;
	GtkWidget *output10;
	if(idExiste(id)==0){
		sprintf(outputmessage,"ID NON EXISTANT\n");
		output10 = lookup_widget(objet_graphique,"resultEditCl");
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
	}
	else{
		Client y;
		strcpy(y.nom,find_client(id).nom);
		strcpy(y.prenom,find_client(id).prenom);
		
		strcpy(y.email,find_client(id).email);
		strcpy(y.num,find_client(id).num);

		strcpy(y.ville,find_client(id).ville);
		strcpy(y.adresse,find_client(id).adresse);

		sprintf(outputmessage,"Tapez vos nouveau donnée puis cliquez sur enregistrer les modifications\n");
		output10 = lookup_widget(objet_graphique,"resultEditCl");
    		gtk_label_set_text(GTK_LABEL(output10),outputmessage);	
			
		sprintf(texte1,"%s",y.nom);
		outputnom = lookup_widget(objet_graphique,"fisrtnameClEdit");
    		gtk_entry_set_text(GTK_ENTRY(outputnom),texte1);

		sprintf(texte2,"%s",y.prenom);
		outputprenom = lookup_widget(objet_graphique,"lastnameClEdit");
    		gtk_entry_set_text(GTK_ENTRY(outputprenom),texte2);

		sprintf(texte3,"%s",y.email);
		outputemail = lookup_widget(objet_graphique,"entry_new_email");
    		gtk_entry_set_text(GTK_ENTRY(outputemail),texte3);

		sprintf(texte4,"%s",y.adresse);
		outputadresse = lookup_widget(objet_graphique,"entry_new_adress");
    		gtk_entry_set_text(GTK_ENTRY(outputadresse),texte4);
    		
		sprintf(texte5,"%s",y.num);
		outputnumtel = lookup_widget(objet_graphique,"entry_new_number");
    		gtk_entry_set_text(GTK_ENTRY(outputnumtel),texte5);

		

		sprintf(texte6,"%s",y.ville);
		outputville = lookup_widget(objet_graphique,"entry_new_city");
		gtk_entry_set_text(GTK_ENTRY(outputville),y.ville);
	}


}


void
on_button_back_edit_profile_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowEditClient");
	window2 = create_windowGesClient ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_confirm_edit_profile_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input7;
	GtkWidget *input8;
	GtkWidget *input9;
	GtkWidget *input10;
	GtkWidget *output; 	 
	GtkWidget*outputNumm;
	GtkWidget *outputPrenomm; 
	GtkWidget *outputNomm;
	GtkWidget *outputadresss;
	GtkWidget *outputcityy;
	char id[10];
	input1 = lookup_widget(objet_graphique,"idclientEdit");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
	
	char texte[200];
	if(idExiste(id) == 0){
		sprintf(texte,"ID non existant\n");
		output = lookup_widget(objet_graphique,"resultEditCl");
    		gtk_label_set_text(GTK_LABEL(output),texte);
	}



	else{
		
		Client c;
		
		input2 = lookup_widget(objet_graphique,"fisrtnameClEdit");
		input3 = lookup_widget(objet_graphique,"lastnameClEdit");
		input7 = lookup_widget(objet_graphique,"entry_new_email");
		input8 = lookup_widget(objet_graphique,"entry_new_adress");
		input9 = lookup_widget(objet_graphique,"entry_new_number");
		input10 = lookup_widget(objet_graphique,"entry_new_city");

		strcpy(c.id,id);
		strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
		strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));

		c.dateNaissance.j = find_client(c.id).dateNaissance.j;
		c.dateNaissance.m = find_client(c.id).dateNaissance.m;
		c.dateNaissance.a = find_client(c.id).dateNaissance.a;

		strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input7)));
		strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input8)));
		strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input9)));
		strcpy(c.ville,gtk_entry_get_text(GTK_ENTRY(input10)));

	int test1,test2,test3,test4,test5,test6;
	
	/*----------- CONTROLE DE SAISIE --------------------*/
	
        test1 = verifName(c.nom);
	outputNomm = lookup_widget(objet_graphique,"lalelNOM");
	if(test1){
		gtk_label_set_text(GTK_LABEL(outputNomm),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputNomm),"❌");
	}

	/*-------------------------------------------------------*/
	test2= verifName(c.prenom);
	outputPrenomm = lookup_widget(objet_graphique,"lalelPRENOMM");
	if(test2){
		gtk_label_set_text(GTK_LABEL(outputPrenomm),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputPrenomm),"❌");
	}

     	test3 = verifName(c.adresse);
	outputadresss = lookup_widget(objet_graphique,"lalelADRESS");
	if(test3){
		gtk_label_set_text(GTK_LABEL(outputadresss),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputadresss),"❌");
	}

	/*-------------------------------------------------------*/
	test4= verifName(c.ville);
	outputcityy  = lookup_widget(objet_graphique,"lalelVILLE");
	if(test4){
		gtk_label_set_text(GTK_LABEL(outputcityy),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputcityy),"❌");
	}
	test5 = verifNum(c.num);
	outputNumm = lookup_widget(objet_graphique,"lalelNUM");
	if(test5){
		gtk_label_set_text(GTK_LABEL(outputNumm),"✔️");
	}
	else{
		gtk_label_set_text(GTK_LABEL(outputNumm),"❌");
	}
	
	if(test1 && test2 && test3 && test4 && test5 ){




		modifier_client(c);
		sprintf(texte,"Votre Client a été modifier avec succés\n");
		output = lookup_widget(objet_graphique,"resultEditCl");
    		gtk_label_set_text(GTK_LABEL(output),texte);
	} 
       }
}


void
on_treeview_admin_clients_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter Iter;
	gchar* id;
	char id_supp[20];	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&Iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&Iter,0,&id,-1);
		
		strcpy(id_supp,id);
		supprimer_client(id_supp);
		//afficher_clients(treeview);
		
	
	}
}


void
on_addClient_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowGesClient");
	window2 = create_windowAddClient ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_gotomodifier_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowGesClient");
	window2 = create_windowEditClient ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_buttonrefresh_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window;
	GtkWidget *window2;
	GtkWidget *treeview;
	window = lookup_widget(objet,"windowGesClient");	
	
	window2 = create_windowGesClient ();
	gtk_widget_destroy(window);	
	gtk_widget_show(window2);
	
	treeview = lookup_widget(window2,"treeview_admin_clients");	
	afficher_clients(treeview);
}


void
on_buttonacceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gotodelete_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowGesClient");
	window2 = create_windowDelClient ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_buttonretourdelete_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"windowDelClient");
	window2 = create_windowGesClient ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_button_clients_delete_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input;
	GtkWidget *output;
	char id[20];
	char texte[100];

	input = lookup_widget(objet_graphique,"entrysuppid");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
	
	if(idExiste(id)){
		supprimer_client(id);		
		sprintf(texte,"Votre suppression à été effectué avec succés\n");
		output = lookup_widget(objet_graphique,"outputDelClient");
    		gtk_label_set_text(GTK_LABEL(output),texte);
		
	}
	else{
		sprintf(texte,"L'id que vous avez saisie n'existe pas\n");
		output = lookup_widget(objet_graphique,"outputDelClient");
    		gtk_label_set_text(GTK_LABEL(output),texte);	
	}
}


void
on_appliquerchangement_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retourGesClient_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_TbuttonAfficheAnSech_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 
    GtkWidget *ansech1;
    gchar *str;  
    int a;
    a=anneseche();
    str = g_strdup_printf ("%d",a);
    ansech1 = lookup_widget(objet_graphique,"textviewAnseche") ;
    gtk_label_set_text(GTK_LABEL(ansech1),str);
    g_free (str);

}

