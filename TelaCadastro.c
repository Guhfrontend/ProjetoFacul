static void on_cadastrar_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *nome_industria = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));

    g_print("Indústria cadastrada: %s\n", nome_industria);
}


static void start_cadastro(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *nome_entry;
    GtkWidget *cadastrar_button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Cadastro de Indústria");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);


    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), box);

    label = gtk_label_new("Nome da Indústria");
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    nome_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), nome_entry, FALSE, FALSE, 0);

    cadastrar_button = gtk_button_new_with_label("Cadastrar");
    g_signal_connect(cadastrar_button, "clicked", G_CALLBACK(on_cadastrar_button_clicked), nome_entry);
    gtk_box_pack_start(GTK_BOX(box), cadastrar_button, FALSE, FALSE, 0);

    gtk_widget_show_all(window);
}
