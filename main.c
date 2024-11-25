#include <gtk/gtk.h>


static void on_login_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *username = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));

    if (g_strcmp0(username, "admin") == 0) {
        gtk_widget_destroy(GTK_WIDGET(widget));
        gtk_main_quit(); 
    } else {
        g_print("Login Inválido!\n");
    }
}

static void on_menu_button_clicked(GtkWidget *widget, gpointer data) {

    g_print("Opção escolhida: %s\n", (char *)data);
}

static void start_gui(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *login_button;
    GtkWidget *username_entry;
    GtkWidget *label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Gestão Ambiental");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), box);


    label = gtk_label_new("Usuário");
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    username_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), username_entry, FALSE, FALSE, 0);


    login_button = gtk_button_new_with_label("Login");
    g_signal_connect(login_button, "clicked", G_CALLBACK(on_login_button_clicked), username_entry);
    gtk_box_pack_start(GTK_BOX(box), login_button, FALSE, FALSE, 0);

    gtk_widget_show_all(window);
}


int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.gtkapp", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(start_gui), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
