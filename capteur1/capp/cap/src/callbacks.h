#include <gtk/gtk.h>


void
on_treeview_gestion_capteur_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gescaptomenu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_openaddcap_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affcap_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_opendelcap_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_openeditcap_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retourajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_confirmer_ajouter_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_suppcap_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retoursuppcap_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_consulter_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_saveeditcap_enter                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_lastgescap_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_calssement_ouvrier_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_retour_calssmenet_ouvrier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_ouvrier_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTem_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonHum_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonTe_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonHu_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_defectueux_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);
