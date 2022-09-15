#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

        // lance la tâche en appuyant sur le bouton start
        QObject::connect(ui->start,SIGNAL(clicked()),this,SLOT(tache1()));
        // affiche la mediane
        QObject::connect(&tache,SIGNAL(envoie_IHM(double)),this,SLOT(affichageIHM(double)));
        // quitte la tâche
        QObject::connect(ui->exit,SIGNAL(clicked()),this,SLOT(tache1()));


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::affichageIHM(double mediane)
{
    // affiche la médiane sur l'IHM
    ui->lcdNumber->display(mediane);
    ui->msg->setText(" thread is running ");
    std::cout << std::endl << "la mediane = "  << mediane << std::endl;
}

void Dialog::tache1(void)
{

    // appel du constructeur run1
    tache.run1();
    // lancement de la tâche
    tache.start();
    std::cout << " thread is running " << std::endl;

}

void Dialog::quitte_la_tache(void)
{
    tache.exit(0);
    exit(-1);
}

void Dialog::on_lcdNumber_overflow()
{

}


