#ifndef DIALOGMESICE_MARS_H
#define DIALOGMESICE_MARS_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Mars;
}

class DialogMesice_Mars : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Mars(QWidget *parent = nullptr);
    ~DialogMesice_Mars();

private slots:
    void MesiceMarsZmena();
    void MesiceMarsZmena2();
    void MesiceMarsPhobos();
    void MesiceMarsPhobos2();
    void MesiceMarsDeimos();
    void MesiceMarsDeimos2();
    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::DialogMesice_Mars *ui;
    QString mesice = "Všechny měsíce";
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesicemars;
};

#endif // DIALOGMESICE_MARS_H
