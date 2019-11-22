#ifndef DIALOGMESICE_URAN_H
#define DIALOGMESICE_URAN_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Uran;
}

class DialogMesice_Uran : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Uran(QWidget *parent = nullptr);
    ~DialogMesice_Uran();

private slots:
    void MesiceUranZmena();
    void MesiceUranZmena2();

    void MesiceUranCordelia();
    void MesiceUranCordelia2();
    void MesiceUranOphelia();
    void MesiceUranOphelia2();
    void MesiceUranBianca();
    void MesiceUranBianca2();
    void MesiceUranCressida();
    void MesiceUranCressida2();
    void MesiceUranDesdemona();
    void MesiceUranDesdemona2();
    void MesiceUranJuliet();
    void MesiceUranJuliet2();
    void MesiceUranPortia();
    void MesiceUranPortia2();
    void MesiceUranRosalind();
    void MesiceUranRosalind2();
    void MesiceUranCupid();
    void MesiceUranCupid2();
    void MesiceUranBelinda();
    void MesiceUranBelinda2();
    void MesiceUranPerdita();
    void MesiceUranPerdita2();
    void MesiceUranPuck();
    void MesiceUranPuck2();
    void MesiceUranMab();
    void MesiceUranMab2();
    void MesiceUranMiranda();
    void MesiceUranMiranda2();
    void MesiceUranAriel();
    void MesiceUranAriel2();
    void MesiceUranUmbriel();
    void MesiceUranUmbriel2();
    void MesiceUranTitania();
    void MesiceUranTitania2();
    void MesiceUranOberon();
    void MesiceUranOberon2();
    void MesiceUranFrancisco();
    void MesiceUranFrancisco2();
    void MesiceUranCaliban();
    void MesiceUranCaliban2();
    void MesiceUranStephano();
    void MesiceUranStephano2();
    void MesiceUranTrinculo();
    void MesiceUranTrinculo2();
    void MesiceUranSycorax();
    void MesiceUranSycorax2();
    void MesiceUranMargaret();
    void MesiceUranMargaret2();
    void MesiceUranProspero();
    void MesiceUranProspero2();
    void MesiceUranSetebos();
    void MesiceUranSetebos2();
    void MesiceUranFerdinand();
    void MesiceUranFerdinand2();

    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::DialogMesice_Uran *ui;
    QString mesice = "Všechny měsíce";
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesiceuran;
};

#endif // DIALOGMESICE_URAN_H
