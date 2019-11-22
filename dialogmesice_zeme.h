#ifndef DIALOGMESICE_ZEME_H
#define DIALOGMESICE_ZEME_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Zeme;
}

class DialogMesice_Zeme : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Zeme(QWidget *parent = nullptr);
    ~DialogMesice_Zeme();

private slots:
    void MesiceZemeZmena();
    void MesiceZemeZmena2();
    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);

private:
    Ui::DialogMesice_Zeme *ui;
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesicezeme;
};

#endif // DIALOGMESICE_ZEME_H
