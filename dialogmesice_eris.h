#ifndef DIALOGMESICE_ERIS_H
#define DIALOGMESICE_ERIS_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Eris;
}

class DialogMesice_Eris : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Eris(QWidget *parent = nullptr);
    ~DialogMesice_Eris();

private slots:
    void MesiceErisZmena();
    void MesiceErisZmena2();
    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);

private:
    Ui::DialogMesice_Eris *ui;
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesiceeris;
};

#endif // DIALOGMESICE_ERIS_H
