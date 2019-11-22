#include "dialogjupiter.h"
#include "ui_dialogjupiter.h"


#include <QSqlDatabase>
#include <QSqlQuery>


DialogJupiter::DialogJupiter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJupiter)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_jupiter  = new QSqlQueryModel;
    ui->tableViewJupiter->setModel(model_jupiter);
}

DialogJupiter::~DialogJupiter()
{
    delete ui;
    delete model_jupiter;
}

void DialogJupiter::on_checkBox_2_clicked(bool checked_typ)
{
    if(checked_typ==true)
    {
        typ = 1;
        JupiterZmena();
    }
    else
    {
        typ = 0;
        JupiterZmena();
    }

}

void DialogJupiter::on_checkBox_4_clicked(bool checked_vzd)
{
    if(checked_vzd==true)
    {
        vzd = 1;
        JupiterZmena();
    }
    else
    {
        vzd = 0;
        JupiterZmena();
    }

}

void DialogJupiter::on_checkBox_5_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        JupiterZmena();
    }
    else
    {
        doba = 0;
        JupiterZmena();
    }
}

void DialogJupiter::on_checkBox_8_clicked(bool checked_delkadne)
{
    if(checked_delkadne==true)
    {
        delka_dne = 1;
        JupiterZmena();
    }
    else
    {
        delka_dne = 0;
        JupiterZmena();
    }
}

void DialogJupiter::on_checkBox_9_clicked(bool checked_polomer)
{
    if(checked_polomer==true)
    {
        polomer = 1;
        JupiterZmena();
    }
    else
    {
        polomer = 0;
        JupiterZmena();
    }
}

void DialogJupiter::on_checkBox_7_clicked(bool checked_teplota)
{
    if(checked_teplota==true)
    {
        teplota = 1;
        JupiterZmena();
    }
    else
    {
        teplota = 0;
        JupiterZmena();
    }
}

void DialogJupiter::on_checkBox_10_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        JupiterZmena();
    }
    else
    {
        hmotnost = 0;
        JupiterZmena();
    }
}

void DialogJupiter::on_checkBox_6_clicked(bool checked_pocetmesicu)
{
    if(checked_pocetmesicu==true)
    {
        pocet_mesicu = 1;
        JupiterZmena();
    }
    else
    {
        pocet_mesicu = 0;
        JupiterZmena();
    }
}

void DialogJupiter::on_checkBox_3_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        JupiterZmena();
    }
    else
    {
        objevitel = 0;
        JupiterZmena();
    }
}

void DialogJupiter::on_checkBox_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        JupiterZmena();
    }
    else
    {
        rok = 0;
        JupiterZmena();
    }
}

void DialogJupiter::JupiterZmena()
{
    //1 checkbox----------------------------------------------------------
    if(vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // Po řadě vše--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 2 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km  FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km  FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km  FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 3 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena2();
    }
 }
void DialogJupiter::JupiterZmena2()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 4 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena3();
    }

}

void DialogJupiter::JupiterZmena3()
{

    if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena4();
    }
}
void DialogJupiter::JupiterZmena4()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 5 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena5();
    }

}

void DialogJupiter::JupiterZmena5()
{
    if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena6();
    }

}

void DialogJupiter::JupiterZmena6()
{
    if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 6 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena7();
    }

}

void DialogJupiter::JupiterZmena7()
{
    if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena8();
    }

}
void DialogJupiter::JupiterZmena8()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 7 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        JupiterZmena9();
    }

}
void DialogJupiter::JupiterZmena9()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 8 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    // 9 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_jupiter->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 5");
    }
    else
    {
        model_jupiter->setQuery("SELECT FROM planety_info WHERE id_p = 5");
    }
}

