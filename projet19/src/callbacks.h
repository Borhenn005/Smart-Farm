#include <gtk/gtk.h>
#include <time.h>

void
on_buttonajoutetroupeaux_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonafficher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonajouter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttontype_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_buttonrechrecher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifier_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodretour_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifierid_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodifretour_enter             (GtkButton       *button,
                                        gpointer         user_data);

void
on_enregistrermodifier_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_quittez_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifretour_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_suppaff_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supression_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_supretour_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Confirmer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retaff_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_okajout_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_okmod_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_suppok_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_oui_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_non_clicked                         (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_okfin_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_brebi_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_veaux_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_totale_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_oktype_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_b_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_v_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_oppsupp_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_oppmod_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_annuller_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);
