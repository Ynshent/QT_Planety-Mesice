#ifndef DIALOGMESICE_JUPITER_H
#define DIALOGMESICE_JUPITER_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogMesice_Jupiter;
}

class DialogMesice_Jupiter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMesice_Jupiter(QWidget *parent = nullptr);
    ~DialogMesice_Jupiter();

private slots:
    void MesiceJupiterZmena();
    void MesiceJupiterZmena2();

    void MesiceJupiterMetis();
    void MesiceJupiterAdrastea();
    void MesiceJupiterAmalthea();
    void MesiceJupiterThebe();
    void MesiceJupiterIo();
    void MesiceJupiterEuropa();
    void MesiceJupiterGanymed();
    void MesiceJupiterCallisto();
    void MesiceJupiterThemisto();
    void MesiceJupiterLeda();
    void MesiceJupiterHimalia();
    void MesiceJupiterErsa();
    void MesiceJupiterPandia();
    void MesiceJupiterLysithea();
    void MesiceJupiterElara();
    void MesiceJupiterDia();
    void MesiceJupiterCarpo();
    void MesiceJupiterEuporie();
    void MesiceJupiterEupheme();
    void MesiceJupiterOrthosie();
    void MesiceJupiterEuanthe();
    void MesiceJupiterThyone();
    void MesiceJupiterMneme();
    void MesiceJupiterHarpalyke();
    void MesiceJupiterHermippe();
    void MesiceJupiterPraxidike();
    void MesiceJupiterThelxinoe();
    void MesiceJupiterHelike();
    void MesiceJupiterIocaste();
    void MesiceJupiterAnanke();
    void MesiceJupiterPhilophrosyne();
    void MesiceJupiterEurydome();
    void MesiceJupiterArche();
    void MesiceJupiterAutonoe();
    void MesiceJupiterPasithee();
    void MesiceJupiterChaldene();
    void MesiceJupiterKale();
    void MesiceJupiterIsonoe();
    void MesiceJupiterEirene();
    void MesiceJupiterAitne();
    void MesiceJupiterErinome();
    void MesiceJupiterTaygete();
    void MesiceJupiterCarme();
    void MesiceJupiterSponde();
    void MesiceJupiterKalyke();
    void MesiceJupiterPasiphae();
    void MesiceJupiterEukelade();
    void MesiceJupiterMegaclite();
    void MesiceJupiterSinope();
    void MesiceJupiterHegemone();
    void MesiceJupiterAoede();
    void MesiceJupiterKallichore();
    void MesiceJupiterCallirrhoe();
    void MesiceJupiterCyllene();


    void MesiceJupiterMetis2();
    void MesiceJupiterAdrastea2();
    void MesiceJupiterAmalthea2();
    void MesiceJupiterThebe2();
    void MesiceJupiterIo2();
    void MesiceJupiterEuropa2();
    void MesiceJupiterGanymed2();
    void MesiceJupiterCallisto2();
    void MesiceJupiterThemisto2();
    void MesiceJupiterLeda2();
    void MesiceJupiterHimalia2();
    void MesiceJupiterErsa2();
    void MesiceJupiterPandia2();
    void MesiceJupiterLysithea2();
    void MesiceJupiterElara2();
    void MesiceJupiterDia2();
    void MesiceJupiterCarpo2();
    void MesiceJupiterEuporie2();
    void MesiceJupiterEupheme2();
    void MesiceJupiterOrthosie2();
    void MesiceJupiterEuanthe2();
    void MesiceJupiterThyone2();
    void MesiceJupiterMneme2();
    void MesiceJupiterHarpalyke2();
    void MesiceJupiterHermippe2();
    void MesiceJupiterPraxidike2();
    void MesiceJupiterThelxinoe2();
    void MesiceJupiterHelike2();
    void MesiceJupiterIocaste2();
    void MesiceJupiterAnanke2();
    void MesiceJupiterPhilophrosyne2();
    void MesiceJupiterEurydome2();
    void MesiceJupiterArche2();
    void MesiceJupiterAutonoe2();
    void MesiceJupiterPasithee2();
    void MesiceJupiterChaldene2();
    void MesiceJupiterKale2();
    void MesiceJupiterIsonoe2();
    void MesiceJupiterEirene2();
    void MesiceJupiterAitne2();
    void MesiceJupiterErinome2();
    void MesiceJupiterTaygete2();
    void MesiceJupiterCarme2();
    void MesiceJupiterSponde2();
    void MesiceJupiterKalyke2();
    void MesiceJupiterPasiphae2();
    void MesiceJupiterEukelade2();
    void MesiceJupiterMegaclite2();
    void MesiceJupiterSinope2();
    void MesiceJupiterHegemone2();
    void MesiceJupiterAoede2();
    void MesiceJupiterKallichore2();
    void MesiceJupiterCallirrhoe2();
    void MesiceJupiterCyllene2();


    void on_checkBox_2_clicked(bool checked_rok);

    void on_checkBox_4_clicked(bool checked_doba);

    void on_checkBox_6_clicked(bool checked_rozmer);

    void on_checkBox_5_clicked(bool checked_objem);

    void on_checkBox_7_clicked(bool checked_hmotnost);

    void on_checkBox_3_clicked(bool checked_pocetpristani);

    void on_checkBox_clicked(bool checked_objevitel);
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::DialogMesice_Jupiter *ui;
    QString mesice = "Všechny měsíce";
    int rok = 0;
    int doba = 0;
    int rozmer = 0;
    int objem = 0;
    int hmotnost = 0;
    int pocet_pristani = 0;
    int objevitel = 0;
    QSqlQueryModel* model_mesicejupiter;
};

#endif // DIALOGMESICE_JUPITER_H
