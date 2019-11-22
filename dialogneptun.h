#ifndef DIALOGNEPTUN_H
#define DIALOGNEPTUN_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogNeptun;
}

class DialogNeptun : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNeptun(QWidget *parent = nullptr);
    ~DialogNeptun();

private slots:

    void NeptunZmena();
    void NeptunZmena2();
    void NeptunZmena3();
    void NeptunZmena4();
    void NeptunZmena5();
    void NeptunZmena6();
    void NeptunZmena7();
    void NeptunZmena8();
    void NeptunZmena9();
    void on_checkBox_2_clicked(bool checked_typ);

    void on_checkBox_4_clicked(bool checked_vzd);

    void on_checkBox_5_clicked(bool checked_doba);

    void on_checkBox_8_clicked(bool checked_delkadne);

    void on_checkBox_9_clicked(bool checked_polomer);

    void on_checkBox_7_clicked(bool checked_teplota);

    void on_checkBox_10_clicked(bool checked_hmotnost);

    void on_checkBox_6_clicked(bool checked_pocetmesicu);

    void on_checkBox_3_clicked(bool checked_objevitel);

    void on_checkBox_clicked(bool checked_rok);

private:
    Ui::DialogNeptun *ui;
    int typ = 0;
    int vzd = 0;
    int doba = 0;
    int delka_dne = 0;
    int polomer = 0;
    int teplota = 0;
    int hmotnost = 0;
    int pocet_mesicu = 0;
    int objevitel = 0;
    int rok = 0;
    QSqlQueryModel* model_neptun;
};

#endif // DIALOGNEPTUN_H
