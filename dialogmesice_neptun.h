#ifndef DIALOGMESICE_NEPTUN_H
#define DIALOGMESICE_NEPTUN_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Neptun;
}

class DialogMesice_Neptun : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Neptun(QWidget *parent = nullptr);
    ~DialogMesice_Neptun();

private slots:
    void MesiceNeptunZmena();
    void MesiceNeptunZmena2();
    void MesiceNeptunNaiada();
    void MesiceNeptunNaiada2();
    void MesiceNeptunThalassa();
    void MesiceNeptunThalassa2();
    void MesiceNeptunDespina();
    void MesiceNeptunDespina2();
    void MesiceNeptunGalatea();
    void MesiceNeptunGalatea2();
    void MesiceNeptunLarissa();
    void MesiceNeptunLarissa2();
    void MesiceNeptunProteus();
    void MesiceNeptunProteus2();
    void MesiceNeptunTriton();
    void MesiceNeptunTriton2();
    void MesiceNeptunNereida();
    void MesiceNeptunNereida2();
    void MesiceNeptunHalimede();
    void MesiceNeptunHalimede2();
    void MesiceNeptunLaomedeia();
    void MesiceNeptunLaomedeia2();
    void MesiceNeptunSao();
    void MesiceNeptunSao2();
    void MesiceNeptunPsamathe();
    void MesiceNeptunPsamathe2();
    void MesiceNeptunNeso();
    void MesiceNeptunNeso2();
    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::DialogMesice_Neptun *ui;
    QString mesice = "Všechny měsíce";
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesiceneptun;
};

#endif // DIALOGMESICE_NEPTUN_H
