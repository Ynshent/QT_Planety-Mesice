#include "dialogeris.h"
#include "ui_dialogeris.h"

#include <QSqlDatabase>
#include <QSqlQuery>

DialogEris::DialogEris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEris)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("planety.db");
    db.open();

    model_eris  = new QSqlQueryModel;
    ui->tableViewEris->setModel(model_eris);
}

DialogEris::~DialogEris()
{
    delete ui;
    delete model_eris;
}

void DialogEris::on_checkBox_2_clicked(bool checked_typ)
{
    if(checked_typ==true)
    {
        typ = 1;
        ErisZmena();
    }
    else
    {
        typ = 0;
        ErisZmena();
    }

}

void DialogEris::on_checkBox_4_clicked(bool checked_vzd)
{
    if(checked_vzd==true)
    {
        vzd = 1;
        ErisZmena();
    }
    else
    {
        vzd = 0;
        ErisZmena();
    }

}

void DialogEris::on_checkBox_5_clicked(bool checked_doba)
{
    if(checked_doba==true)
    {
        doba = 1;
        ErisZmena();
    }
    else
    {
        doba = 0;
        ErisZmena();
    }
}

void DialogEris::on_checkBox_8_clicked(bool checked_delkadne)
{
    if(checked_delkadne==true)
    {
        delka_dne = 1;
        ErisZmena();
    }
    else
    {
        delka_dne = 0;
        ErisZmena();
    }
}

void DialogEris::on_checkBox_9_clicked(bool checked_polomer)
{
    if(checked_polomer==true)
    {
        polomer = 1;
        ErisZmena();
    }
    else
    {
        polomer = 0;
        ErisZmena();
    }
}

void DialogEris::on_checkBox_7_clicked(bool checked_teplota)
{
    if(checked_teplota==true)
    {
        teplota = 1;
        ErisZmena();
    }
    else
    {
        teplota = 0;
        ErisZmena();
    }
}

void DialogEris::on_checkBox_10_clicked(bool checked_hmotnost)
{
    if(checked_hmotnost==true)
    {
        hmotnost = 1;
        ErisZmena();
    }
    else
    {
        hmotnost = 0;
        ErisZmena();
    }
}

void DialogEris::on_checkBox_6_clicked(bool checked_pocetmesicu)
{
    if(checked_pocetmesicu==true)
    {
        pocet_mesicu = 1;
        ErisZmena();
    }
    else
    {
        pocet_mesicu = 0;
        ErisZmena();
    }
}

void DialogEris::on_checkBox_3_clicked(bool checked_objevitel)
{
    if(checked_objevitel==true)
    {
        objevitel = 1;
        ErisZmena();
    }
    else
    {
        objevitel = 0;
        ErisZmena();
    }
}

void DialogEris::on_checkBox_clicked(bool checked_rok)
{
    if(checked_rok==true)
    {
        rok = 1;
        ErisZmena();
    }
    else
    {
        rok = 0;
        ErisZmena();
    }
}

void DialogEris::ErisZmena()
{
    //1 checkbox----------------------------------------------------------
    if(vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // Po řadě vše--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 2 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km  FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km  FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km  FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 3 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena2();
    }
 }
void DialogEris::ErisZmena2()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 4 checkboxy--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena3();
    }

}

void DialogEris::ErisZmena3()
{

    if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena4();
    }
}
void DialogEris::ErisZmena4()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 5 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena5();
    }

}

void DialogEris::ErisZmena5()
{
    if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena6();
    }

}

void DialogEris::ErisZmena6()
{
    if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 &&  typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 6 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena7();
    }

}

void DialogEris::ErisZmena7()
{
    if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena8();
    }

}
void DialogEris::ErisZmena8()
{
    if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 7 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        ErisZmena9();
    }

}
void DialogEris::ErisZmena9()
{
    if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 8 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    // 9 checkboxu--------------------------------------------------------------
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 0)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 0 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 0 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 0 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 0 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 0 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 1 && delka_dne == 0 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, doba_obehu_dny, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 1 && doba == 0 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, vzdalenost_Slunce, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 1 && typ == 0 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT vzdalenost_Slunce, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else if (vzd == 0 && typ == 1 && doba == 1 && delka_dne == 1 && polomer == 1 && teplota == 1 && hmotnost == 1 && pocet_mesicu == 1 && objevitel == 1 && rok == 1)
    {
        model_eris->setQuery("SELECT typ, doba_obehu_dny, delka_dne_hod, polomer_km, prumerna_teplota_Celsia, hmotnost_kg, pocet_mesicu, objevitel, rok_objevu FROM planety_info WHERE id_p = 13");
    }
    else
    {
        model_eris->setQuery("SELECT FROM planety_info WHERE id_p = 13");
    }
}
