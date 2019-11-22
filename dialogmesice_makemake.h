#ifndef DIALOGMESICE_MAKEMAKE_H
#define DIALOGMESICE_MAKEMAKE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Makemake;
}

class DialogMesice_Makemake : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Makemake(QWidget *parent = nullptr);
    ~DialogMesice_Makemake();

private slots:
    void MesiceMakemakeZmena();
    void MesiceMakemakeZmena2();
    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);

private:
    Ui::DialogMesice_Makemake *ui;
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesicemakemake;
};

#endif // DIALOGMESICE_MAKEMAKE_H
