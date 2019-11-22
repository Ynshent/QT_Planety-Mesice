#ifndef DIALOGMESICE_SATURN_H
#define DIALOGMESICE_SATURN_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Saturn;
}

class DialogMesice_Saturn : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Saturn(QWidget *parent = nullptr);
    ~DialogMesice_Saturn();

private slots:
    void MesiceSaturnZmena();
    void MesiceSaturnZmena2();

    void MesiceSaturnPan();
    void MesiceSaturnPan2();
    void MesiceSaturnDaphnis();
    void MesiceSaturnDaphnis2();
    void MesiceSaturnAtlas();
    void MesiceSaturnAtlas2();
    void MesiceSaturnPrometheus();
    void MesiceSaturnPrometheus2();
    void MesiceSaturnPandora();
    void MesiceSaturnPandora2();
    void MesiceSaturnEpimetheus();
    void MesiceSaturnEpimetheus2();
    void MesiceSaturnJanus();
    void MesiceSaturnJanus2();
    void MesiceSaturnAegaenon();
    void MesiceSaturnAegaenon2();
    void MesiceSaturnMimas();
    void MesiceSaturnMimas2();
    void MesiceSaturnMethone();
    void MesiceSaturnMethone2();
    void MesiceSaturnPallene();
    void MesiceSaturnPallene2();
    void MesiceSaturnEnceladus();
    void MesiceSaturnEnceladus2();
    void MesiceSaturnTelesto();
    void MesiceSaturnTelesto2();
    void MesiceSaturnTethys();
    void MesiceSaturnTethys2();
    void MesiceSaturnCalypso();
    void MesiceSaturnCalypso2();
    void MesiceSaturnPolydeuces();
    void MesiceSaturnPolydeuces2();
    void MesiceSaturnDione();
    void MesiceSaturnDione2();
    void MesiceSaturnHelene();
    void MesiceSaturnHelene2();
    void MesiceSaturnRhea();
    void MesiceSaturnRhea2();
    void MesiceSaturnTitan();
    void MesiceSaturnTitan2();
    void MesiceSaturnHyperion();
    void MesiceSaturnHyperion2();
    void MesiceSaturnJapetus();
    void MesiceSaturnJapetus2();
    void MesiceSaturnKiviuq();
    void MesiceSaturnKiviuq2();
    void MesiceSaturnIjiraq();
    void MesiceSaturnIjiraq2();
    void MesiceSaturnPhoebe();
    void MesiceSaturnPhoebe2();
    void MesiceSaturnPaaliaq();
    void MesiceSaturnPaaliaq2();
    void MesiceSaturnSkathi();
    void MesiceSaturnSkathi2();
    void MesiceSaturnAlbiorix();
    void MesiceSaturnAlbiorix2();
    void MesiceSaturnBebhionn();
    void MesiceSaturnBebhionn2();
    void MesiceSaturnErriapo();
    void MesiceSaturnErriapo2();
    void MesiceSaturnSiarnaq();
    void MesiceSaturnSiarnaq2();
    void MesiceSaturnTarvos();
    void MesiceSaturnTarvos2();
    void MesiceSaturnMundilfari();
    void MesiceSaturnMundilfari2();
    void MesiceSaturnNarvi();
    void MesiceSaturnNarvi2();
    void MesiceSaturnBergelmir();
    void MesiceSaturnBergelmir2();
    void MesiceSaturnAegir();
    void MesiceSaturnAegir2();
    void MesiceSaturnSuttungr();
    void MesiceSaturnSuttungr2();
    void MesiceSaturnBestla();
    void MesiceSaturnBestla2();
    void MesiceSaturnFarbauti();
    void MesiceSaturnFarbauti2();
    void MesiceSaturnHati();
    void MesiceSaturnHati2();
    void MesiceSaturnThrymr();
    void MesiceSaturnThrymr2();
    void MesiceSaturnFornjot();
    void MesiceSaturnFornjot2();
    void MesiceSaturnFenrir();
    void MesiceSaturnFenrir2();
    void MesiceSaturnYmir();
    void MesiceSaturnYmir2();


    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::DialogMesice_Saturn *ui;
    QString mesice = "Všechny měsíce";
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesicesaturn;
};

#endif // DIALOGMESICE_SATURN_H
