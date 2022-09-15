#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "thread.h"
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public :

signals:
   //void clicked();
   void NewVal(double);
   void envoie_IHM(double);

public slots:
    void tache1(void);

private slots:
    void on_lcdNumber_overflow();
       void affichageIHM(double);
       void quitte_la_tache(void);

private:
    Ui::Dialog *ui;
    QTcpSocket *socket;
    Thread tache;



};
#endif // DIALOG_H
