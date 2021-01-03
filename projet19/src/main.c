/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *windowtroupeaux;
  GtkWidget *affichagetroupeaux;
  GtkWidget *windowsuppmod;
  GtkWidget *idtroupeaumodifier;
  GtkWidget *modifiertroupeau; 
  GtkWidget *typedetroupeaux;
  GtkWidget *ajoutoui;
  GtkWidget *modoui;
  GtkWidget *suppoui;
  GtkWidget *alerte;
  GtkWidget *suppfin;
  GtkWidget *typeinf;
  GtkWidget *alerteopp;



#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory ("../pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
 /* windowtroupeaux = create_windowtroupeaux ();
  gtk_widget_show (windowtroupeaux);*/
  affichagetroupeaux = create_affichagetroupeaux ();
  gtk_widget_show (affichagetroupeaux);
 /* windowsuppmod = create_windowsuppmod ();
  gtk_widget_show (windowsuppmod);
  idtroupeaumodifier = create_idtroupeaumodifier ();
  gtk_widget_show (idtroupeaumodifier);
  modifiertroupeau = create_modifiertroupeau ();
  gtk_widget_show (modifiertroupeau);
  typedetroupeaux = create_typedetroupeaux ();
  gtk_widget_show (typedetroupeaux);
  ajoutoui = create_ajoutoui ();
  gtk_widget_show (ajoutoui);
  modoui = create_modoui ();
  gtk_widget_show (modoui);
  suppoui = create_suppoui ();
  gtk_widget_show (suppoui);
  alerte = create_alerte ();
  gtk_widget_show (alerte);
  suppfin = create_suppfin ();
  gtk_widget_show (suppfin);
  typeinf = create_typeinf ();
  gtk_widget_show (typeinf);
  alerteopp = create_alerteopp ();
  gtk_widget_show (alerteopp);*/


  gtk_main ();
  return 0;
}

