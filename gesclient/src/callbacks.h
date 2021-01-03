#include <gtk/gtk.h>


void
on_creecompte_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_login_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_add_client_back_6_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_add_client_confirm_6_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_consultclient_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_back_edit_profile_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_confirm_edit_profile_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_admin_clients_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_addClient_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gotomodifier_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonrefresh_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonacceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_gotodelete_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretourdelete_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_clients_delete_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_appliquerchangement_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourGesClient_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_TbuttonAfficheAnSech_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
